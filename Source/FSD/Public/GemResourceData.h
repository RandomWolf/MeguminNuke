#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ResourceData.h"
#include "IRandRange.h"
#include "GemResourceData.generated.h"

class UDebrisBase;
class UGemResourceCreator;
class UDebrisPositioning;
class AGem;
class AFSDGameState;

UCLASS(Blueprintable)
class UGemResourceData : public UResourceData {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebrisPositioning* DebrisPositioning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CheckIfCompletelyCoveredByTerrain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIRandRange GemValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGemResourceCreator* ResourceCreator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InfluencerRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UDebrisBase>> Debris;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AGem>> GemClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ImportantRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AGem>> GemClassesLoaded;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UDebrisBase*> DebrisLoaded;
    
public:
    UGemResourceData();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetCollectedGemsCreditValue(AFSDGameState* GameState);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetCollectedGemsAmount(AFSDGameState* GameState);
    
};

