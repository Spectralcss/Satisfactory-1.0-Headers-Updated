// Copyright Coffee Stain Studios. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FGSignificanceInterface.generated.h"

/**
 * Interface for actors that are handled by UFGSignificanceManager.
 */
UINTERFACE( Blueprintable )
class FACTORYGAME_API UFGSignificanceInterface : public UInterface
{
	GENERATED_BODY()
};

class FACTORYGAME_API IFGSignificanceInterface
{
	GENERATED_BODY()
public:
	/** Call when actor gained significance */
	UFUNCTION( BlueprintNativeEvent, Category = "Significance" )
	void GainedSignificance();

	/** Call when actor gained significance */
	UFUNCTION( BlueprintNativeEvent, Category = "Significance" )
	void LostSignificance();

	UFUNCTION( BlueprintNativeEvent, Category = "Significance" )
	void UpdateSignificanceTickRate( float NewTickRate, bool bTickEnabled );

	/** Call before adding object to significance in order to prepare it. ( Set up bounds and stuff ) */
	UFUNCTION()
	virtual void SetupForSignificance();

	/** Defaults to 10000.f */
	UFUNCTION()
	virtual float GetSignificanceRange();

	virtual bool DoesReduceTick() const { return false; };
	
	virtual int32 NumTickLevels() const { return 0; };

	virtual float GetTickExponent() const { return 1.f; }

	UFUNCTION(BlueprintNativeEvent, Category="Significance")
	void GainedNetSignificance();
	
	UFUNCTION(BlueprintNativeEvent, Category="Significance")
	void LostNetSignificance();
	
	UFUNCTION()
	virtual void UpdateMeshLodLevels(int32 newLodLevel);

	//@todo 2021-10-04 G2: These should be removed according to Ben.
	UFUNCTION()
	virtual void GainedSignificance_Native();
	UFUNCTION()
	virtual void LostSignificance_Native();

	virtual void SetInitialState(bool bState) {}
};
