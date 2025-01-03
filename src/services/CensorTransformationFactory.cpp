#include "CensorTransformationFactory.hpp"

CensorTransformationFactory::CensorTransformationFactory(std::initializer_list<std::shared_ptr<CensorTransformation>> ctf_list) {
    for (const auto& ctf : ctf_list) {
        if (ctf->getCensorWord().length() <= 4)
            pool[ctf->getCensorWord()] = ctf;
    }
}

std::shared_ptr<CensorTransformation> CensorTransformationFactory::createCensorTransformation(const std::string& to_censor) {
    if (to_censor.length() <= 4) {
        // find the transformation in the pool
        auto it = pool.find(to_censor);
        // if found, return it
        if (it != pool.end()) {
            return it->second;
        } else {
            // if not found, create a new transformation and add it to the pool
            std::shared_ptr<CensorTransformation> ctf = std::make_shared<CensorTransformation>(to_censor);
            pool[to_censor] = ctf;
            // then return it
            return ctf;
        }
    } else {
        // if word is longer than 4 characters, create a new transformation and return it
        return std::make_shared<CensorTransformation>(to_censor);
    }
}
