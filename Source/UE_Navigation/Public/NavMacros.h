#pragma once

//如果位置发生了距离在min到max大小范围内的突变就限制其变化，系数为DelayCoefficient，系数越小变化就越平缓
#define DelayRangeMin 50.0
#define DelayRangeMax 1200.0
#define DelayCoefficient 0.080

//浮点0
#define FZero 1e-6

