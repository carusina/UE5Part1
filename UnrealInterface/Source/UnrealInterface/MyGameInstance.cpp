// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h" // 이 include가 첫번째 include
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"

UMyGameInstance::UMyGameInstance()
{
	SchoolName = TEXT("기본 학교"); // 엔진이 초기화될 때 실행
}

void UMyGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Log, TEXT("==============================="));

	TArray<UPerson*> Persons = { NewObject<UStudent>(), NewObject<UTeacher>(), NewObject<UStaff>() };
	for (UPerson* const Person : Persons)
	{
		UE_LOG(LogTemp, Log, TEXT("구성원 이름: %s"), *Person->GetName());
	}

	UE_LOG(LogTemp, Log, TEXT("==============================="));

	for (UPerson* const Person : Persons)
	{
		ILessonInterface* LessonInterface = Cast<ILessonInterface>(Person);
		if (LessonInterface) // ILessonInterface이 구현되어있다면
		{
			UE_LOG(LogTemp, Log, TEXT("%s님은 수업에 참여할 수 있습니다."), *Person->GetName());
			LessonInterface->DoLesson();
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("%s님은 수업에 참여할 수 없습니다."), *Person->GetName());
		}
	}

	UE_LOG(LogTemp, Log, TEXT("==============================="));
}
