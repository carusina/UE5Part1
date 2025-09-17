// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h" // 이 include가 첫번째 include
#include "Student.h"
#include "Teacher.h"

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

	UStudent* Student = NewObject<UStudent>();
	UTeacher* Teacher = NewObject<UTeacher>();
	Student->SetName(TEXT("학생1"));
	UE_LOG(LogTemp, Log, TEXT("새로운 학생 이름: %s"), *Student->GetName());

	FString CurrentTeacherName;
	FString NewTeacherName(TEXT("이득우"));
	FProperty* NameProp = UTeacher::StaticClass()->FindPropertyByName(TEXT("Name"));
	if (NameProp)
	{
		NameProp->GetValue_InContainer(Teacher, &CurrentTeacherName);
		UE_LOG(LogTemp, Log, TEXT("현재 선생님 이름: %s"), *CurrentTeacherName);

		NameProp->SetValue_InContainer(Teacher, &NewTeacherName);
		UE_LOG(LogTemp, Log, TEXT("새로운 선생님 이름: %s"), *Teacher->GetName());
	}

	UE_LOG(LogTemp, Log, TEXT("==============================="));

	Student->DoLesson();
	UFunction* DoLessonFunc = Teacher->GetClass()->FindFunctionByName("DoLesson");
	if (DoLessonFunc)
	{
		Teacher->ProcessEvent(DoLessonFunc, nullptr);
	}

	UE_LOG(LogTemp, Log, TEXT("==============================="));
}
