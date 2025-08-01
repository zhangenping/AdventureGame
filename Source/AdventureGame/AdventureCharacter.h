// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "AdventureCharacter.generated.h"


class UInputMappingContext;
class UInputAction;
class UInputComponent;

class UAnimBlueprint;
class UInputMappingContext;
class UInputAction;
class UInputComponent;

UCLASS()
class ADVENTUREGAME_API AdventureCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AdventureCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<UInputMappingContext> FirstPersonContext;

	// Move Input Actions
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<UInputAction> MoveAction;

	// Jump Input Actions
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	TObjectPtr<UInputAction> JumpAction;

	// Look Input Actions
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* LookAction;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Handles 2D Movement Input
	UFUNCTION()
	void Move(const FInputActionValue& Value);

	// Handles Look Input
	UFUNCTION()
	void Look(const FInputActionValue& Value);

	// First Person camera
	UPROPERTY(VisibleAnywhere, Category = Camera)
	UCameraComponent* FirstPersonCameraComponent;

	// First-person camera field of view
	UPROPERTY(EditAnywhere, Category = Camera)
	float FirstPersonFieldOfView = 70.0f;

	// First-person camera view scale
	UPROPERTY(EditAnywhere, Category = Camera)
	float FirstPersonViewScale = 0.6f;

	// First-person mesh, visible only to the owning player
	UPROPERTY(VisibleAnywhere, Category = Mesh)
	USkeletalMeshComponent* FirstPersonMeshComponent;

	// Offset for the first-person camera
	UPROPERTY(EditAnywhere, Category = Camera)
	FVector FirstPersonCameraOffset = FVector(2.8f, 5.9f, 0.0f);

	// First Person animations
	UPROPERTY(EditAnywhere, Category = Animation)
	UAnimBlueprint* FirstPersonDefaultAnim;
};
