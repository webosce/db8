// Copyright (c) 2009-2018 LG Electronics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0



#ifndef MOJDBCLIENTTESTRUNNER_H_
#define MOJDBCLIENTTESTRUNNER_H_

#include "db/MojDbServiceClient.h"
#include "MojDbClientTestResultHandler.h"
#include "Utils.h"


class MojDbClientTest: public ::testing::Test
{
public:
	void SetUp();
	void TearDown();

	MojErr init();
	MojErr registerType();
	MojErr updateType();
	MojErr testErrorHandling(bool multiResponse);

	MojErr writeTestObj(const MojChar* json, MojObject* idOut = NULL);
	MojErr writeTestObj(const MojChar* json, bool kind, MojObject* idOut = NULL);
	MojErr getTestObj(MojObject id, MojObject& objOut);

	MojErr verifyFindResults(const MojDbClientTestResultHandler* handler,
			   			     MojObject idExpected, const MojChar* barExpected);
	MojErr delTestData();

	MojAutoPtr<MojService> m_service;
	MojAutoPtr<MojDbServiceClient> m_dbClient;
	MojAutoPtr<MojReactor> m_reactor;
};
#endif /* MOJDBCLIENTTESTRUNNER_H_ */
