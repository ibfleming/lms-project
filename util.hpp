#ifndef __UTIL_HPP
#define __UTIL_HPP

#include <bits/stdc++.h>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>

using namespace std;
using namespace boost::uuids;

uuid generate_uuid();
bool is_alpha(const string& str);
bool is_num(const string& str);
bool is_era(const string& str);

#endif