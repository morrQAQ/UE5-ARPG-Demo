#pragma once

#define DRAW_SPHERE(Location)                                                        \
    if (GetWorld())  \                                                                \
    {                                                                                \
        DrawDebugSphere(GetWorld(), Location, 30, 10,\
                      FColor::Emerald, false, 5, 2); \
    }

#define DRAW_SPHERE_EVERY_FRAME(Location)\
if(GetWorld())\
{\
    DrawDebugSphere(GetWorld(), Location, 30, 10,\
				FColor::Emerald, false, -1, 2); \
}

#define DRAW_LINE_EVERY_FRAME(StartLocation,EndLocation)\
if(GetWorld())\
{\
DrawDebugLine(GetWorld(), StartLocation, EndLocation * 50,\
                      FColor::Black, false, -1, 0, 5.f);\
}
