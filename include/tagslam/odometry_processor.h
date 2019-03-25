/* -*-c++-*--------------------------------------------------------------------
 * 2019 Bernd Pfrommer bernd.pfrommer@gmail.com
 */

#pragma once

#include "tagslam/body.h"
#include "tagslam/geometry.h"
#include "tagslam/pose_noise2.h"
#include "tagslam/graph_manager.h"
#include "tagslam/graph.h"


#include <ros/ros.h>
#include <nav_msgs/Odometry.h>

namespace tagslam {
  class OdometryProcessor {
    using Odometry = nav_msgs::Odometry;
    using OdometryConstPtr = nav_msgs::OdometryConstPtr;
  public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    OdometryProcessor(ros::NodeHandle &nh, GraphManager *graph,
                      const BodyConstPtr &body);
    void process(const OdometryConstPtr &msgs,
                 std::vector<Graph::Vertex> *factors);
    GraphManager    *graphManager_{NULL};
    BodyConstPtr    body_;
    Transform       pose_;
    ros::Time       time_{0};
    ros::Publisher  pub_;
    Transform       T_body_odom_;
    PoseNoise2      deltaPoseNoise_;
  };
}
