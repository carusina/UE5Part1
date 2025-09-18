// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Student.h"
#include "StudentManager.h"

void CheckUObjectIsValid(const UObject* InObject, const FString& InTag)
{
	// Unreal Object가 Valid하다는 것은 Object가 엔진에 의해 잘 관리, 감시되고 있냐는 의미
	// 따라서 Object가 Valid하다면, 객체의 메모리 및 누수 현상에 대해 신경 쓸 필요가 없다.
	if (InObject->IsValidLowLevel())
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] 유효한 언리얼 오브젝트"), *InTag);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] 유효하지 않은 언리얼 오브젝트"), *InTag);
	}
}

void CheckUObjectIsNull(const UObject* InObject, const FString& InTag)
{
	if (InObject == nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] 널 포인터 언리얼 오브젝트"), *InTag);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("[%s] 널 포인터가 아닌 언리얼 오브젝트"), *InTag);
	}
}

void UMyGameInstance::Init()
{
	Super::Init();

	NonPropStudent = NewObject<UStudent>();
	PropStudent = NewObject<UStudent>();

	NonPropStudents.Add(NewObject<UStudent>());
	PropStudents.Add(NewObject<UStudent>());

	StudentManager = new FStudentManager(NewObject<UStudent>());
}

void UMyGameInstance::Shutdown()
{
	Super::Shutdown();

	CheckUObjectIsNull(NonPropStudent, TEXT("NonPropStudent"));
	CheckUObjectIsValid(NonPropStudent, TEXT("NonPropStudent"));

	CheckUObjectIsNull(PropStudent, TEXT("PropStudent"));
	CheckUObjectIsValid(PropStudent, TEXT("PropStudent"));

	CheckUObjectIsNull(NonPropStudents[0], TEXT("NonPropStudents[0]"));
	CheckUObjectIsValid(NonPropStudents[0], TEXT("NonPropStudents[0]"));

	CheckUObjectIsNull(PropStudents[0], TEXT("PropStudents[0]"));
	CheckUObjectIsValid(PropStudents[0], TEXT("PropStudents[0]"));

	const UStudent* StudentInManager = StudentManager->GetStudent();

	delete StudentManager;
	StudentManager = nullptr;

	CheckUObjectIsNull(StudentInManager, TEXT("StudentInManager"));
	CheckUObjectIsValid(StudentInManager, TEXT("StudentInManager"));
}
