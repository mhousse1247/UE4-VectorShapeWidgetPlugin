// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "TypeActions/AssetTypeActions_VectorShapeData.h"
#include "Layout/Margin.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Input/SButton.h"
#include "EditorStyleSet.h"
#include "IIntroTutorials.h"
#include "EditorTutorial.h"
#include "AssetData.h"
#include "Widgets/SBoxPanel.h"
#include "VectorWidget/SlateVectorShapeData.h"
#include "VectorWidget/SVectorShapeWidget.h"
#include "Widgets/Layout/SScaleBox.h"
#include "VectorShapeEditorStyle.h"

#define LOCTEXT_NAMESPACE "FAssetTypeActions_VectorShapeData"


FText FAssetTypeActions_VectorShapeData::GetName() const
{
	return LOCTEXT("AssetTypeActions_VectorShapeData", "Vector Shape Data");
}

FColor FAssetTypeActions_VectorShapeData::GetTypeColor() const
{
	return FColor(129, 196, 115);
}

UClass* FAssetTypeActions_VectorShapeData::GetSupportedClass() const
{
	return USlateVectorShapeData::StaticClass();
}

uint32 FAssetTypeActions_VectorShapeData::GetCategories()
{
	return  EAssetTypeCategories::UI;
}


TSharedPtr<SWidget> FAssetTypeActions_VectorShapeData::GetThumbnailOverlay(const FAssetData& AssetData) const
{

	const USlateVectorShapeData* VectorDataAsset = Cast<USlateVectorShapeData>(AssetData.GetAsset());

	if (VectorDataAsset == nullptr)
	{
		return nullptr;
	}

	TSharedPtr<SVectorShapeWidget> VectorShapeMeshWidget = SNew(SVectorShapeWidget).Clipping(EWidgetClipping::ClipToBounds);
	VectorShapeMeshWidget->InitRenderData(*VectorDataAsset);

	return SNew(SBox)
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.Padding(FMargin(4))
		[
					SNew(SScaleBox)
					.VAlign(VAlign_Fill)
					.HAlign(HAlign_Fill)
					.Stretch(EStretch::Fill)
						[
							SNew(SBorder)
							.BorderImage(FVectorShapeEditorStyle::Get()->GetBrush("Checker"))	
								[							
									VectorShapeMeshWidget.ToSharedRef()								
								]

						]
		];
}

#undef LOCTEXT_NAMESPACE
