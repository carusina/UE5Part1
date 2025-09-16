// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

void UMyGameInstance::Init()
{
	Super::Init(); // override할 땐 부모 class의 함수 호출해주기

	UE_LOG(LogTemp, Log, TEXT("%s"), TEXT("Hello Unreal!"));
}
