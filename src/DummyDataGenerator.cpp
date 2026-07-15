#include "DummyDataGenerator/DummyDataGenerator.h"

#include <array>
#include <random>
#include <string>

namespace ddg {

namespace {

std::mt19937& Rng() {
    static std::mt19937 rng(std::random_device{}());
    return rng;
}

const std::array<std::string, 6> kSampleNamePool = {
    "실리콘 웨이퍼-8인치",
    "GaN 에피택셜-4인치",
    "SiC 파워기판-6인치",
    "산화막 웨이퍼-SiO2",
    "사파이어 기판-2인치",
    "InP 에피택셜-3인치"
};

const std::array<std::string, 5> kCustomerNamePool = {
    "고객A", "고객B", "고객C", "고객D", "고객E"
};

const std::array<dp::OrderStatus, 5> kOrderStatusPool = {
    dp::OrderStatus::RESERVED,
    dp::OrderStatus::CONFIRMED,
    dp::OrderStatus::PRODUCING,
    dp::OrderStatus::RELEASE,
    dp::OrderStatus::REJECTED
};

std::string NextId(const std::string& prefix, int existingCount, int offset) {
    return prefix + std::to_string(existingCount + offset + 1);
}

}

void GenerateDummySamples(dp::SampleRepository& sampleRepo, int count) {
    int existingCount = static_cast<int>(sampleRepo.GetAll().size());

    std::uniform_int_distribution<size_t> nameDist(0, kSampleNamePool.size() - 1);
    std::uniform_real_distribution<double> productionTimeDist(10.0, 120.0);
    std::uniform_real_distribution<double> yieldDist(0.70, 0.99);
    std::uniform_int_distribution<int> stockDist(0, 600);

    for (int i = 0; i < count; ++i) {
        dp::Sample sample;
        sample.id = NextId("S", existingCount, i);
        sample.name = kSampleNamePool[nameDist(Rng())];
        sample.avgProductionTimeMinutes = productionTimeDist(Rng());
        sample.yield = yieldDist(Rng());
        sample.stock = stockDist(Rng());

        std::string errorMessage;
        sampleRepo.Add(sample, errorMessage);
    }
}

void GenerateDummyOrders(dp::SampleRepository& sampleRepo, dp::OrderRepository& orderRepo, int count) {
    std::vector<dp::Sample> samples = sampleRepo.GetAll();
    if (samples.empty()) {
        return;
    }

    int existingCount = static_cast<int>(orderRepo.GetAll().size());

    std::uniform_int_distribution<size_t> sampleDist(0, samples.size() - 1);
    std::uniform_int_distribution<size_t> customerDist(0, kCustomerNamePool.size() - 1);
    std::uniform_int_distribution<size_t> statusDist(0, kOrderStatusPool.size() - 1);
    std::uniform_int_distribution<int> quantityDist(10, 200);

    for (int i = 0; i < count; ++i) {
        dp::Order order;
        order.id = NextId("O", existingCount, i);
        order.sampleId = samples[sampleDist(Rng())].id;
        order.customerName = kCustomerNamePool[customerDist(Rng())];
        order.quantity = quantityDist(Rng());
        order.status = kOrderStatusPool[statusDist(Rng())];

        std::string errorMessage;
        orderRepo.Add(order, errorMessage);
    }
}

}
