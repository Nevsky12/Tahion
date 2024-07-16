#pragma once

#include <iostream>
#include <string>


#define TAHION_RESOURCE_USER_CONFIG_DIRNAME ".Tahion"

#define TAHION_RESOURCE_SITE_ENVNAME "TWM_PROJECT_SITE"

#define TAHION_RESOURCE_SITE_FALLBACK_ENVNAME "TWM_PROJECT_DIR"

namespace Tahion
{

namespace tahionVersion
{


extern const int api;

extern const std::string patch;

extern const std::string build;

extern const std::string buildArch;

extern const std::string version;


bool patched() noexcept;


unsigned int  labelByteSize(std::string const &s) noexcept;
unsigned int scalarByteSize(std::string const &s) noexcept;


void printBuildInfo(std::ostream &os, bool const full = true) noexcept;


std::string configuredProjectDir() noexcept;

std::string coonfiguredEtcDir   () noexcept;


} // namespace tahionVersion

} // namespace Tahion
