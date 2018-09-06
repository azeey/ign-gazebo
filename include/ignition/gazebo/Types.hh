/*
 * Copyright (C) 2018 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#ifndef IGNITION_GAZEBO_TYPES_HH_
#define IGNITION_GAZEBO_TYPES_HH_

#include <chrono>
#include <functional>
#include <utility>
#include <ignition/common/Time.hh>

namespace ignition
{
  namespace gazebo
  {
    // Inline bracket to help doxygen filtering.
    inline namespace IGNITION_GAZEBO_VERSION_NAMESPACE {
    // Forward declarations.
    class EntityComponentManager;

    /// \brief Information passed to systems on the update callback.
    /// \todo(louise) Update descriptions once reset is supported.
    struct UpdateInfo
    {
      /// \brief Total time elapsed in simulation. This will not increase while
      /// paused.
      std::chrono::steady_clock::duration simTime;

      /// \brief Total wall clock time elapsed. This increases even if
      /// simulation is paused.
      std::chrono::steady_clock::duration realTime;

      /// \brief Simulation time handled during a single update. If zero,
      /// simulation is paused and time is not running.
      std::chrono::steady_clock::duration dt;

      /// \brief Total number of elapsed simulation iterations.
      // cppcheck-suppress unusedStructMember
      unsigned int iterations;
    };

    /// \brief A unique identifier for a component instance. The uniqueness
    /// of a ComponentId is scoped to the component's type.
    /// \sa ComponentKey.
    using ComponentId = int;

    /// \brief A unique identifier for a component type. A component type
    /// can be plain data type or something more complex like
    /// ignition::math::Pose3d.
    using ComponentTypeId = int;

    /// \brief A key that uniquely identifies, at the global scope, a component
    /// instance
    using ComponentKey = std::pair<ComponentTypeId, ComponentId>;

    /// \brief typedef for query callbacks
    using EntityQueryCallback = std::function<void (const UpdateInfo,
        EntityComponentManager &)>;

    /// \brief Id that indicates an invalid component.
    static const ComponentId kComponentIdInvalid = -1;

    /// \brief Id that indicates an invalid component type.
    static const ComponentTypeId kComponentTypeIdInvalid = -1;
    }
  }
}
#endif