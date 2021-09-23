// Copyright (C) 2018-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include <memory>
#include <string>

#include <transformations_visibility.hpp>

#include "ngraph/coordinate_diff.hpp"
#include "ngraph/op/op.hpp"

namespace ngraph {
namespace op {
namespace internal {

class TRANSFORMATIONS_API NonMaxSuppressionIEInternal : public Op {
public:
    OPENVINO_OP("NonMaxSuppressionIEInternal", "util");
    BWDCMP_RTTI_DECLARATION;

    NonMaxSuppressionIEInternal(const Output<Node>& boxes,
                                const Output<Node>& scores,
                                const Output<Node>& max_output_boxes_per_class,
                                const Output<Node>& iou_threshold,
                                const Output<Node>& score_threshold,
                                int center_point_box,
                                bool sort_result_descending,
                                const ngraph::element::Type& output_type = ngraph::element::i64);

    NonMaxSuppressionIEInternal(const Output<Node>& boxes,
                                const Output<Node>& scores,
                                const Output<Node>& max_output_boxes_per_class,
                                const Output<Node>& iou_threshold,
                                const Output<Node>& score_threshold,
                                const Output<Node>& soft_nms_sigma,
                                int center_point_box,
                                bool sort_result_descending,
                                const ngraph::element::Type& output_type = ngraph::element::i64);

    void validate_and_infer_types() override;

    bool visit_attributes(AttributeVisitor& visitor) override;

    std::shared_ptr<Node> clone_with_new_inputs(const OutputVector & new_args) const override;

    int m_center_point_box;
    bool m_sort_result_descending = true;
    element::Type m_output_type;

private:
    int64_t max_boxes_output_from_input() const;
};

}  // namespace internal
}  // namespace op
}  // namespace ngraph
