@call :GET_CURRENT_DIR
@cd %THIS_DIR%
hushd.exe -ac_name=ZDEEX -ac_sapling=1 -ac_reward=200000000 -ac_blocktime=300 -ac_cc=2 -ac_founders=1 -ac_perc=10000000 -ac_halving=1000000 -ac_supply=100000 -ac_private=1 -connect=194.226.49.236 -connect=89.23.106.224 -connect=89.108.115.67 -connect=193.17.92.111 -connect=194.226.49.236 -ac_pubkey=03abd1d20f8c7cf579d80788c1d4d23fcb10b04a4f01f43d2bf0aac6a51b05db0e %*
@goto :EOF

:GET_CURRENT_DIR
@pushd %~dp0
@set THIS_DIR=%CD%
@popd
@goto :EOF
