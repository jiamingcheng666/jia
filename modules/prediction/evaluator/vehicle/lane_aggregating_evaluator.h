/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file
 * @brief Define the lane aggregating evaluator class
 */

#pragma once

#include <memory>
#include <unordered_map>
#include <string>
#include <vector>

#include "torch/script.h"
#include "torch/torch.h"

#include "modules/prediction/evaluator/evaluator.h"

/**
 * @namespace apollo::prediction
 * @brief apollo::prediction
 */
namespace apollo {
namespace prediction {

class LaneAggregatingEvaluator : public Evaluator {
 public:
  /**
   * @brief Constructor
   */
  LaneAggregatingEvaluator();

  /**
   * @brief Destructor
   */
  virtual ~LaneAggregatingEvaluator() = default;

  /**
   * @brief Override Evaluate
   * @param Obstacle pointer
   */
  bool Evaluate(Obstacle* obstacle_ptr) override;

  /**
   * @brief Extract features for learning model's input
   * @param Obstacle pointer
   * @param To be filled up with extracted features
   */
  bool ExtractFeatures(const Obstacle* obstacle_ptr,
                       std::vector<double>* feature_values);

  /**
   * @brief Get the name of evaluator.
   */
  std::string GetName() override { return "LANE_AGGREGATING_EVALUATOR"; }

 // private:
 //  struct LSTMState {
 //    double timestamp;
 //    torch::Tensor ct;
 //    torch::Tensor ht;
 //  };

 //  void Clear();

 //  void LoadModel();

 // private:
 //  std::unordered_map<int, LSTMState> obstacle_id_lstm_state_map_;
 //  std::shared_ptr<torch::jit::script::Module>
 //      torch_position_embedding_ptr_ = nullptr;
 //  std::shared_ptr<torch::jit::script::Module>
 //      torch_social_embedding_ptr_ = nullptr;
 //  std::shared_ptr<torch::jit::script::Module>
 //      torch_single_lstm_ptr_ = nullptr;
 //  std::shared_ptr<torch::jit::script::Module>
 //      torch_prediction_layer_ptr_ = nullptr;
  torch::Device device_;

 //  static const int kGridSize = 2;
 //  static const int kEmbeddingSize = 64;
 //  static const int kHiddenSize = 128;
};

}  // namespace prediction
}  // namespace apollo