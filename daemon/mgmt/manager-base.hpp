/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (C) 2014 Named Data Networking Project
 * See COPYING for copyright and distribution information.
 */

#ifndef NFD_MGMT_MANAGER_BASE_HPP
#define NFD_MGMT_MANAGER_BASE_HPP

#include "common.hpp"
#include <ndn-cpp-dev/management/control-response.hpp>

namespace nfd {

class AppFace;

class ManagerBase
{
public:
  ManagerBase(shared_ptr<AppFace> face);

  virtual
  ~ManagerBase();

protected:

  void
  setResponse(ndn::ControlResponse& response,
              uint32_t code,
              const std::string& text);

  void
  sendResponse(const Name& name,
               const ndn::ControlResponse& response);

  void
  sendResponse(const Name& name,
               uint32_t code,
               const std::string& text);

protected:
  shared_ptr<AppFace> m_face;
};

inline void
ManagerBase::setResponse(ndn::ControlResponse& response,
                         uint32_t code,
                         const std::string& text)
{
  response.setCode(code);
  response.setText(text);
}


} // namespace nfd

#endif // NFD_MGMT_MANAGER_BASE_HPP
