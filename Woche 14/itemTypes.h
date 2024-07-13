#pragma once
#define STRINGIFY(any) #any

enum class ItemType
{
	Label = 0,
	Button,
	CheckButton,
	TextBox,
	HexBox,
	Count//Tricky!!!
};