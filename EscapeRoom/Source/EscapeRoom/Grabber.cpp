// Copyright Me 2018

#include "Grabber.h"
#include "Engine/World.h"
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

	// ...

	///Look for attached Physics Handle
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle)
	{
		//We did it HURRAY!
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s is missing a Physics Handle Component"), *GetOwner()->GetName())
	}

	///Look for attached Input(Only appears at run time)
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

void UGrabber::Grab()
{
	UE_LOG(LogTemp, Warning, TEXT("GRABBING"))
}

void UGrabber::Released()
{
	UE_LOG(LogTemp,Warning,TEXT("Releasing!"))
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	///Get player view point this tick
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);


	FVector LineTraceEnd = (PlayerViewPointLocation + (PlayerViewPointRotation.Vector()*Reach));
	///Draw a red trace in the world
	DrawDebugLine(
		GetWorld(), 
		PlayerViewPointLocation, 
		LineTraceEnd,
		FColor(255, 0, 0), 
		false, 0.0f, 
		0.0f,
		2.0f);


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
		UE_LOG(LogTemp, Warning, TEXT("Line trace hit: %s"),*(HitActor->GetName()))
	}
	

	///what did we hit
}

