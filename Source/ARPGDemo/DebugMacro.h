#include "CoreMinimal.h"

#define DRAW_SPHERE(Location)                                                        \
    if (GetWorld())                                                                  \
    {                                                                                \
        DrawDebugSphere(GetWorld(), Location, 30, 10, FColor::Emerald, false, 5, 2); \
    }
