// Fill out your copyright notice in the Description page of Project Settings.


#include "StudentManager.h"
#include "Student.h"

void FStudentManager::AddReferencedObjects(FReferenceCollector& Collector)
{
	if (SafeStudent->IsValidLowLevel())
	{
		Collector.AddReferencedObject(SafeStudent); // Collector에 Unreal Object 등록
	}
}
