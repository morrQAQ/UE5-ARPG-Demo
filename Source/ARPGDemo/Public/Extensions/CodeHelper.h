// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <stdexcept>

#include "CoreMinimal.h"

class ARPGDEMO_API CodeHelper
{
public:
	CodeHelper();
	~CodeHelper();

	template<typename T>
	static void Invoke(T* value,void (*FuncPtr)(T param))
	{
		value?FuncPtr(value):throw  std::invalid_argument("Null pointer exception");
	}
};
