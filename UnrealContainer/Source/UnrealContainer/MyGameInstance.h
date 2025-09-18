// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

USTRUCT()
struct FStudentData
{
	GENERATED_BODY()

	FStudentData()
	{
		Name = TEXT("홍길동");
		Order = -1;
	}

	FStudentData(FString InName, int32 InOrder) : Name(InName), Order(InOrder) {}

	bool operator==(const FStudentData& InOther) const
	{
		return Order == InOther.Order;
	}

	friend FORCEINLINE uint32 GetTypeHash(const FStudentData& InStudentData)
	{
		return GetTypeHash(InStudentData.Order);
	}

	UPROPERTY()
	FString Name;

	UPROPERTY()
	int32 Order;
};
/**
 * 
 */
UCLASS()
class UNREALCONTAINER_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	virtual void Init() override;

private:
	TArray<FStudentData> StudentsData;

	UPROPERTY() // Unreal Object를 사용하기 때문에 필수
	TArray<TObjectPtr<class UStudent>> Students;

	// Unreal Object를 사용하지 않기 때문에 없어도 무방
	TMap<int32, FString> StudentsMap;
};
