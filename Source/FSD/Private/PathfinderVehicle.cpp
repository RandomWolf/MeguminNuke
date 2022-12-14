#include "PathfinderVehicle.h"
#include "HealthComponent.h"
#include "DeepPathfinderMovement.h"
#include "Components/SkeletalMeshComponent.h"

APathfinderVehicle::APathfinderVehicle() {
    this->PathfinderMovement = CreateDefaultSubobject<UDeepPathfinderMovement>(TEXT("PathfinderMovement"));
    this->Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
    this->HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health"));
    this->Speed = 10.00f;
}

