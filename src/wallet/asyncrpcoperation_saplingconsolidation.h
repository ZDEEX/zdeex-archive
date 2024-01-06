// Copyright (c) 2020 The Hush developers
// Copyright (c) 2019 CryptoForge
// Distributed under the GPLv3 software license, see the accompanying
// file COPYING or https://www.gnu.org/licenses/gpl-3.0.en.html

#include "amount.h"
#include "asyncrpcoperation.h"
#include "univalue.h"
#include "zcash/Address.hpp"
#include "zcash/zip32.h"

//Default fee used for consolidation transactions, in puposhis
static const CAmount DEFAULT_CONSOLIDATION_FEE = 10000;
extern CAmount fConsolidationTxFee;
extern bool fConsolidationMapUsed;

class AsyncRPCOperation_saplingconsolidation : public AsyncRPCOperation
{
public:
    AsyncRPCOperation_saplingconsolidation(int targetHeight);
    virtual ~AsyncRPCOperation_saplingconsolidation();

    // We don't want to be copied or moved around
    AsyncRPCOperation_saplingconsolidation(AsyncRPCOperation_saplingconsolidation const&) = delete;            // Copy construct
    AsyncRPCOperation_saplingconsolidation(AsyncRPCOperation_saplingconsolidation&&) = delete;                 // Move construct
    AsyncRPCOperation_saplingconsolidation& operator=(AsyncRPCOperation_saplingconsolidation const&) = delete; // Copy assign
    AsyncRPCOperation_saplingconsolidation& operator=(AsyncRPCOperation_saplingconsolidation&&) = delete;      // Move assign

    virtual void main();

    virtual void cancel();

    virtual UniValue getStatus() const;

private:
    int targetHeight_;

    bool main_impl();

    void setConsolidationResult(int numTxCreated, const CAmount& amountConsolidated, const std::vector<std::string>& consolidationTxIds);

};
