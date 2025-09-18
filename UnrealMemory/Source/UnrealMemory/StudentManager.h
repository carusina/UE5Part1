// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class UNREALMEMORY_API FStudentManager : public FGCObject // 일반 C++ Object에서 Unreal Object를 관리하기 위해 상속
{
public:
	FStudentManager(class UStudent* InStudent) : SafeStudent(InStudent) {}

	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;

	virtual FString GetReferencerName() const override
	{
		return TEXT("FStudentManager"); // Class 이름
	}

	const class UStudent* GetStudent() const { return SafeStudent; }

private:
	class UStudent* SafeStudent = nullptr;
};
