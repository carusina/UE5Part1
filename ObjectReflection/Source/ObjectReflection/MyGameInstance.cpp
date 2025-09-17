// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

UMyGameInstance::UMyGameInstance()
{
	SchoolName = TEXT("기본 학교"); // 엔진이 초기화될 때 실행
}

void UMyGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Log, TEXT("==============================="));
	UClass* ClassRunTime = GetClass();
	UClass* ClassCompile = UMyGameInstance::StaticClass();

	//check(ClassRunTime != ClassCompile);  // Editor 강제 종료
	//ensure(ClassRunTime != ClassCompile); // Editor 종료되지 않음
	//ensureMsgf(ClassRunTime != ClassCompile, TEXT("일부러 error를 발생시킴"));
	UE_LOG(LogTemp, Log, TEXT("학교를 담당하는 Class 이름: %s"), *ClassRunTime->GetName());

	SchoolName = TEXT("Unreal 학교");
	UE_LOG(LogTemp, Log, TEXT("학교 이름: %s"), *SchoolName);
	UE_LOG(LogTemp, Log, TEXT("학교 이름 기본값: %s"), *GetClass()->GetDefaultObject<UMyGameInstance>()->SchoolName);

	UE_LOG(LogTemp, Log, TEXT("==============================="));
}
