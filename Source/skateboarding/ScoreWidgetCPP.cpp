#include "ScoreWidgetCPP.h"
#include "Components/TextBlock.h" 

void UScoreWidgetCPP::UpdateScore(int32 NewScore)
{
    if (ScoreText)
    {
       
        ScoreText->SetText(FText::AsNumber(NewScore));
    }
}
