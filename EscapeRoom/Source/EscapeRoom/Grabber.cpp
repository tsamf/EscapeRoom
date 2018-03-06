// Copyright Me 2018

#include "Grabber.h"
#include "Engine/World.h"
#include "Components/PrimitiveComponent.h"
#include "DrawDebugHelpers.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	FindPhysicsHandleComponent();
	SetupInputComponent();
}

///Look for attached Input(Only appears at run time)
void UGrabber::SetupInputComponent()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s has an Input Component"), *GetOwner()->GetName());
		///Bind the input axis
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Released);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s is missing an Input Component"), *GetOwner()->GetName())
	}
}

///Look for attached Physics Handle
void UGrabber::FindPhysicsHandleComponent()
{
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle)
	{
		//We did it HURRAY!
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s is missing a Physics Handle Component"), *GetOwner()->GetName())
	}
}

void UGrabber::Grab()
{
	UE_LOG(LogTemp, Warning, TEXT("GRABBING"));

	/// LINE TRACE and Try and reach any actors with physics body Collision channel set
	FHitResult HitResult = GetFirstPhysicsBodyInReach();
	UPrimitiveComponent* ComponentToGrab = HitResult.GetComponent();
	AActor* ActorHit = HitResult.GetActor();

	/// If we hit something then attach a physics handle
	if (ActorHit)
	{
		//Attach the physics handle
		PhysicsHandle->GrabComponent(
			ComponentToGrab,
			NAME_None,
			ComponentToGrab->GetOwner()->GetActorLocation(),
			true //Allow rotation
		);
	}
}

void UGrabber::Released()
{
	UE_LOG(LogTemp, Warning, TEXT("Releasing!"))
		PhysicsHandle->ReleaseComponent();
}



// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//if physics handle is attached
	if (PhysicsHandle->GrabbedComponent)
	{
		///Get player view point this tick
		FVector PlayerViewPointLocation;
		FRotator PlayerViewPointRotation;
		GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
			OUT PlayerViewPointLocation,
			OUT PlayerViewPointRotation
		);


		FVector LineTraceEnd = (PlayerViewPointLocation + (PlayerViewPointRotation.Vector()*Reach));

		//move the object that we are holding
		PhysicsHandle->SetTargetLocation(LineTraceEnd);
	}
	

	///what did we hit
}

const FHitResult UGrabber::GetFirstPhysicsBodyInReach()
{
	///Get player view point this tick
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);


	FVector LineTraceEnd = (PlayerViewPointLocation + (PlayerViewPointRotation.Vector()*Reach));
	FHitResult LineTraceHit;
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

	///Ray-cast out to reach distance
	GetWorld()->LineTraceSingleByObjectType(
		OUT LineTraceHit,
		PlayerViewPointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters
	);

	AActor* HitActor = LineTraceHit.GetActor();
	if (HitActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Line trace hit: %s"), *(HitActor->GetName()))
	}

	return LineTraceHit;
}