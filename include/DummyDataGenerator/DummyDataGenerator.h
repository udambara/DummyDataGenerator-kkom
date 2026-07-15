#pragma once

#include "DataPersistence/SampleRepository.h"
#include "DataPersistence/OrderRepository.h"

namespace ddg {

// Generates `count` random samples and registers them via sampleRepo.
void GenerateDummySamples(dp::SampleRepository& sampleRepo, int count);

// Generates `count` random orders against samples already in sampleRepo.
// Does nothing if sampleRepo has no samples yet.
void GenerateDummyOrders(dp::SampleRepository& sampleRepo, dp::OrderRepository& orderRepo, int count);

}
