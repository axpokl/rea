
; Failed pseudocode: 0x00407580 sub_407580
00407580  push    ebp
00407581  mov     eax, 122Ch
00407586  mov     ebp, esp
00407588  push    edi
00407589  push    esi
0040758A  push    ebx
0040758B  call    sub_414DF0
00407590  sub     esp, eax
00407592  mov     eax, [ebp+dwFlagsAndAttributes]
00407595  lea     ebx, [ebp+FileName]
0040759B  mov     [esp+0Ch+lpName], offset Name; "MineSweeperRushMutex"
004075A3  mov     [esp+0Ch+bInitialOwner], 1; bInitialOwner
004075AB  mov     [esp+0Ch+lpMutexAttributes], 0; lpMutexAttributes
004075B2  mov     ds:hInstance, eax
004075B7  call    CreateMutexA
004075BC  sub     esp, 0Ch
004075BF  mov     [ebp+hMutex], eax
004075C5  call    GetLastError
004075CA  cmp     eax, 0B7h
004075CF  jz      loc_409B46
004075D5  mov     [esp+0Ch+bInitialOwner], 0; lpWindowName
004075DD  mov     [esp+0Ch+lpMutexAttributes], offset MultiByteStr; "MineSweeperRushClass"
004075E4  call    FindWindowA
004075E9  test    eax, eax
004075EB  push    ecx
004075EC  push    ecx
004075ED  jnz     loc_409B46
004075F3  mov     edx, offset aData; "./data"
004075F8  mov     ecx, offset a20260524; "20260524"
004075FD  mov     eax, ebx
004075FF  call    sub_411866
00407604  mov     [esp+0Ch+lpMutexAttributes], ebx; lpFileName
00407607  call    GetFileAttributesA
0040760C  inc     eax
0040760D  push    edx
0040760E  jnz     short loc_407681
00407610  mov     eax, offset aData; "./data"
00407615  call    sub_4118A7
0040761A  mov     [esp+0Ch+lpMutexAttributes], offset FileName; "./data.cab"
00407621  call    GetFileAttributesA
00407626  inc     eax
00407627  push    edx
00407628  jz      short loc_407681
0040762A  mov     eax, offset FileName; "./data.cab"
0040762F  call    sub_411986
00407634  test    eax, eax
00407636  jz      short loc_407681
00407638  mov     [esp+0Ch+hTemplateFile], 0; hTemplateFile
00407640  mov     [esp+0Ch+dwFlagsAndAttributes], 80h; dwFlagsAndAttributes
00407648  mov     dword ptr [esp+10h], 2; dwCreationDisposition
00407650  mov     [esp+0Ch+lpSecurityAttributes], 0; lpSecurityAttributes
00407658  mov     [esp+0Ch+lpName], 0; dwShareMode
00407660  mov     [esp+0Ch+bInitialOwner], 40000000h; dwDesiredAccess
00407668  mov     [esp+0Ch+lpMutexAttributes], ebx; lpFileName
0040766B  call    CreateFileA
00407670  sub     esp, 1Ch
00407673  cmp     eax, 0FFFFFFFFh
00407676  jz      short loc_407681
00407678  mov     [esp+0Ch+lpMutexAttributes], eax; hObject
0040767B  call    CloseHandle
00407680  push    eax
00407681  lea     ecx, [ebp+var_F70]
00407687  lea     edi, [ebp+var_D24]
0040768D  mov     esi, offset unk_4182A0
00407692  call    sub_40EE22
00407697  xor     eax, eax
00407699  mov     ecx, 0Eh
0040769E  mov     dword ptr [ebp+FileName], 140h
004076A8  mov     [ebp+var_E14], 170h
004076B2  mov     [ebp+var_E10], 100h
004076BC  mov     [ebp+var_E0C], 100h
004076C6  mov     [ebp+var_E08], 18h
004076D0  mov     [ebp+var_E04], 18h
004076DA  mov     [ebp+var_E00], 18h
004076E4  mov     [ebp+var_DFC], 18h
004076EE  mov     [ebp+var_DF8], 10h
004076F8  mov     [ebp+var_DF4], 10h
00407702  mov     [ebp+var_DF0], 0Dh
0040770C  mov     [ebp+var_DEC], 9
00407716  mov     [ebp+var_DE8], 0Dh
00407720  mov     [ebp+var_DE4], 18h
0040772A  mov     [ebp+var_DE0], 11h
00407734  mov     [ebp+var_DDC], 18h
0040773E  mov     [ebp+var_DD8], 90h
00407748  mov     [ebp+var_DD4], 24h
00407752  mov     [ebp+var_DD0], 24h
0040775C  mov     [ebp+var_DCC], 24h
00407766  mov     [ebp+var_DC8], 78h
00407770  mov     [ebp+var_DC4], 24h
0040777A  mov     [ebp+var_DC0], 168h
00407784  mov     [ebp+var_DBC], 0F0h
0040778E  mov     [ebp+var_DB8], 280h
00407798  mov     [ebp+var_DB4], 1E0h
004077A2  mov     [ebp+var_DB0], 40h
004077AC  mov     [ebp+var_DAC], 20h
004077B6  mov     [ebp+var_DA8], 18h
004077C0  mov     [ebp+var_DA4], 11h
004077CA  mov     [ebp+var_DA0], 0Dh
004077D4  mov     [ebp+var_D9C], 50h
004077DE  mov     [ebp+var_D98], 0Ch
004077E8  mov     [ebp+var_D94], 13h
004077F2  mov     [ebp+var_D90], 30h
004077FC  mov     [ebp+var_D8C], 48h
00407806  mov     [ebp+var_D88], 18h
00407810  mov     [ebp+var_D84], 18h
0040781A  mov     [ebp+var_D80], 0
00407824  mov     [ebp+var_D7C], 0
0040782E  mov     [ebp+var_D78], 0
00407838  mov     [ebp+var_D74], 0
00407842  mov     [ebp+var_D70], 0
0040784C  mov     [ebp+var_D6C], 0
00407856  mov     [ebp+var_D68], 0
00407860  mov     [ebp+var_D64], 0
0040786A  mov     [ebp+var_D60], 0
00407874  mov     [ebp+var_D5C], 0
0040787E  mov     [ebp+var_D58], 0
00407888  mov     [ebp+var_D54], 0
00407892  mov     [ebp+var_D50], 0
0040789C  mov     [ebp+var_D4C], 0
004078A6  mov     [ebp+var_D48], 0
004078B0  mov     [ebp+var_D44], 0
004078BA  mov     [ebp+var_D40], 0
004078C4  mov     [ebp+var_D3C], 0
004078CE  mov     [ebp+var_D38], 0
004078D8  mov     [ebp+var_D34], 0
004078E2  mov     [ebp+var_D30], 0
004078EC  mov     [ebp+var_D2C], 0
004078F6  mov     [ebp+var_D28], 0
00407900  rep stosd
00407902  lea     edi, [ebp+var_CE8]
00407908  mov     ecx, 9
0040790D  mov     [ebp+var_CEC], 0
00407917  rep stosd
00407919  lea     edi, [ebp+var_CC0]
0040791F  mov     ecx, 0Bh
00407924  mov     [ebp+var_CC4], 0
0040792E  rep stosd
00407930  lea     edi, [ebp+var_C64]
00407936  mov     ecx, 1Eh
0040793B  mov     [ebp+var_C94], 0
00407945  mov     [ebp+var_C90], 0
0040794F  mov     [ebp+var_C8C], 0
00407959  mov     [ebp+var_C88], 0
00407963  mov     [ebp+var_C84], 0
0040796D  mov     [ebp+var_C80], 0
00407977  mov     [ebp+var_C7C], 0
00407981  mov     [ebp+var_C78], 0
0040798B  mov     [ebp+var_C74], 0
00407995  mov     [ebp+var_C70], 0
0040799F  mov     [ebp+var_C6C], 0
004079A9  mov     [ebp+var_C68], 0
004079B3  rep stosd
004079B5  mov     [ebp+var_BEC], 0
004079BF  mov     [ebp+var_BE8], 0
004079C9  lea     edi, [ebp+var_B8C]
004079CF  mov     [ebp+var_BE4], 0
004079D9  mov     [ebp+var_BE0], 0
004079E3  mov     ecx, 9
004079E8  mov     [ebp+var_BDC], 0
004079F2  mov     [ebp+var_BD8], 0
004079FC  lea     eax, [ebp+var_B38]
00407A02  mov     [ebp+var_BD4], 0
00407A0C  mov     [ebp+var_BD0], 0
00407A16  mov     [ebp+var_BCC], 0
00407A20  mov     [ebp+var_BC8], 0
00407A2A  mov     [ebp+var_BC4], 0
00407A34  mov     [ebp+var_BC0], 0
00407A3E  mov     [ebp+var_BBC], 0
00407A48  mov     [ebp+var_BB8], 0
00407A52  mov     [ebp+var_BB4], 0
00407A5C  mov     [ebp+var_BB0], 0
00407A66  mov     [ebp+var_BAC], 0
00407A70  mov     [ebp+var_BA8], 0
00407A7A  mov     [ebp+var_BA4], 0
00407A84  mov     [ebp+var_BA0], 0
00407A8E  mov     [ebp+var_B9C], 0
00407A98  mov     [ebp+var_B98], 0
00407AA2  mov     [ebp+var_B94], 0
00407AAC  mov     [ebp+var_B90], 1
00407AB6  rep movsd
00407AB8  mov     [esp+0Ch+lpdwDisposition], 0; lpdwDisposition
00407AC0  mov     [esp+0Ch+phkResult], eax; phkResult
00407AC4  lea     edi, [ebp+var_908]
00407ACA  mov     [esp+0Ch+hTemplateFile], 0; lpSecurityAttributes
00407AD2  mov     [esp+0Ch+dwFlagsAndAttributes], 0F003Fh; samDesired
00407ADA  mov     esi, offset off_4182E0
00407ADF  mov     dword ptr [esp+10h], 0; dwOptions
00407AE7  mov     [esp+0Ch+lpSecurityAttributes], 0; lpClass
00407AEF  mov     [esp+0Ch+lpName], 0; Reserved
00407AF7  mov     [esp+0Ch+bInitialOwner], offset SubKey; "SoftWare\\MineSweeperRush\\20250412"
00407AFF  mov     [esp+0Ch+lpMutexAttributes], 80000001h; hKey
00407B06  mov     [ebp+var_B68], 0
00407B10  mov     [ebp+var_B40], 0AFAFAFh
00407B1A  mov     [ebp+var_B3C], 0
00407B21  call    RegCreateKeyExA
00407B26  lea     eax, [ebp+var_B34]
00407B2C  sub     esp, 24h
00407B2F  mov     [esp+0Ch+lpdwDisposition], 0; lpdwDisposition
00407B37  mov     [esp+0Ch+hTemplateFile], 0; lpSecurityAttributes
00407B3F  mov     [esp+0Ch+phkResult], eax; phkResult
00407B43  mov     [esp+0Ch+dwFlagsAndAttributes], 0F003Fh; samDesired
00407B4B  mov     dword ptr [esp+10h], 0; dwOptions
00407B53  mov     [esp+0Ch+lpSecurityAttributes], 0; lpClass
00407B5B  mov     [esp+0Ch+lpName], 0; Reserved
00407B63  mov     [esp+0Ch+bInitialOwner], offset aSoftwareMinesw_0; "SoftWare\\MineSweeperRush\\20250412\\bo"...
00407B6B  mov     [esp+0Ch+lpMutexAttributes], 80000001h; hKey
00407B72  call    RegCreateKeyExA
00407B77  lea     ecx, [ebp+var_B18]
00407B7D  sub     esp, 24h
00407B80  call    sub_40D04C
00407B85  lea     ecx, [ebp+var_AD0]
00407B8B  call    sub_40EE22
00407B90  lea     edx, [ebp+var_770]
00407B96  mov     [ebp+var_978], 37EFB0h
00407BA0  mov     [ebp+var_973], 0
00407BA7  mov     [ebp+var_970], 0
00407BB1  mov     [ebp+var_96C], 1
00407BBB  mov     ecx, 1Ah
00407BC0  mov     [ebp+var_968], 2
00407BCA  mov     [ebp+var_964], 3
00407BD4  xor     eax, eax
00407BD6  mov     [ebp+var_960], 4
00407BE0  mov     [ebp+var_95C], 5
00407BEA  mov     [ebp+var_958], 6
00407BF4  mov     [ebp+var_954], 7
00407BFE  mov     [ebp+var_950], 8
00407C08  mov     [ebp+var_94C], 9
00407C12  mov     [ebp+var_948], 0Ah
00407C1C  mov     [ebp+var_944], 0Bh
00407C26  mov     [ebp+var_940], 0Ch
00407C30  mov     [ebp+var_93C], 0Dh
00407C3A  mov     [ebp+var_938], 0Eh
00407C44  mov     [ebp+var_934], 0Fh
00407C4E  mov     [ebp+var_930], 10h
00407C58  mov     [ebp+var_92C], 11h
00407C62  mov     [ebp+var_928], 12h
00407C6C  mov     [ebp+var_924], 13h
00407C76  mov     [ebp+var_920], 14h
00407C80  mov     [ebp+var_91C], 15h
00407C8A  mov     [ebp+var_918], 16h
00407C94  mov     [ebp+var_914], 17h
00407C9E  mov     [ebp+var_910], 18h
00407CA8  mov     [ebp+var_90C], 19h
00407CB2  rep movsd
00407CB4  mov     [ebp+var_884], 0
00407CBE  mov     [ebp+var_880], 1
00407CC8  lea     edi, [ebp+var_854]
00407CCE  mov     [ebp+var_87C], 2
00407CD8  mov     esi, offset off_418360
00407CDD  mov     [ebp+var_878], 3
00407CE7  mov     [ebp+var_874], 4
00407CF1  mov     [ebp+var_870], 5
00407CFB  mov     ecx, 13h
00407D00  mov     [ebp+var_86C], 6
00407D0A  mov     [ebp+var_868], 0
00407D14  mov     [ebp+var_864], 3
00407D1E  mov     [ebp+var_860], 6
00407D28  mov     [ebp+var_85C], 9
00407D32  mov     [ebp+var_858], 0Ch
00407D3C  fld     ds:flt_41977C
00407D42  rep movsd
00407D44  mov     [ebp+var_7BC], 0
00407D4B  lea     edi, [ebp+var_7B8]
00407D51  mov     esi, offset off_4183C0
00407D56  mov     ecx, 0Fh
00407D5B  rep movsd
00407D5D  mov     edi, edx
00407D5F  lea     edx, [ebp+var_6F8]
00407D65  mov     ecx, 1Eh
00407D6A  fstp    [ebp+var_360]
00407D70  mov     [ebp+var_77C], 14h
00407D7A  mov     [ebp+var_778], 0Fh
00407D84  mov     [ebp+var_774], 1
00407D8E  mov     [ebp+var_368], 1
00407D95  rep stosd
00407D97  mov     edi, edx
00407D99  lea     edx, [ebp+var_590]
00407D9F  mov     ecx, 5Ah
00407DA4  rep stosd
00407DA6  mov     edi, edx
00407DA8  lea     edx, [ebp+var_580]
00407DAE  mov     ecx, 4
00407DB3  rep stosd
00407DB5  mov     edi, edx
00407DB7  lea     edx, [ebp+var_560]
00407DBD  mov     ecx, 8
00407DC2  rep stosd
00407DC4  mov     edi, edx
00407DC6  lea     edx, [ebp+var_548]
00407DCC  mov     ecx, 6
00407DD1  rep stosd
00407DD3  mov     edi, edx
00407DD5  lea     edx, [ebp+var_4D0]
00407DDB  mov     ecx, 1Eh
00407DE0  rep stosd
00407DE2  mov     edi, edx
00407DE4  mov     ecx, 5Ah
00407DE9  rep stosd
00407DEB  mov     [esp+0Ch+bInitialOwner], 2580h; SizeOfElements
00407DF3  mov     [esp+0Ch+lpMutexAttributes], 3; NumOfElements
00407DFA  call    calloc
00407DFF  mov     [esp+0Ch+lpMutexAttributes], 37EFB0h
00407E06  mov     [ebp+var_364], eax
00407E0C  call    ds:SteamAPI_RestartAppIfNecessary
00407E12  test    al, al
00407E14  jz      short loc_407E4D
00407E16  mov     eax, [ebp+var_9D8]
00407E1C  mov     edx, [ebp+var_9D4]
00407E22  mov     [esp+0Ch+lpSecurityAttributes], 40h; uType
00407E2A  mov     edx, [eax+edx*4]
00407E2D  mov     [esp+0Ch+lpName], edx; lpCaption
00407E31  mov     edx, [ebp+var_9CC]
00407E37  mov     eax, [eax+edx*4]
00407E3A  mov     [esp+0Ch+lpMutexAttributes], 0; hWnd
00407E41  mov     [esp+0Ch+bInitialOwner], eax; lpText
00407E45  call    MessageBoxW
00407E4A  sub     esp, 10h
00407E4D  call    ds:SteamAPI_Init
00407E53  test    al, al
00407E55  mov     [ebp+var_974], al
00407E5B  jnz     short loc_407E94
00407E5D  mov     eax, [ebp+var_9D8]
00407E63  mov     edx, [ebp+var_9D4]
00407E69  mov     [esp+0Ch+lpSecurityAttributes], 30h; uType
00407E71  mov     edx, [eax+edx*4]
00407E74  mov     [esp+0Ch+lpName], edx; lpCaption
00407E78  mov     edx, [ebp+var_9C8]
00407E7E  mov     eax, [eax+edx*4]
00407E81  mov     [esp+0Ch+lpMutexAttributes], 0; hWnd
00407E88  mov     [esp+0Ch+bInitialOwner], eax; lpText
00407E8C  call    MessageBoxW
00407E91  sub     esp, 10h
00407E94  cmp     [ebp+var_974], 0
00407E9B  jz      loc_407F33
00407EA1  call    sub_40E63C
00407EA6  mov     edx, [eax]
00407EA8  mov     ecx, eax
00407EAA  call    dword ptr [edx+24h]
00407EAD  cmp     eax, [ebp+var_978]
00407EB3  jz      short loc_407EDC
00407EB5  mov     [esp+0Ch+lpSecurityAttributes], 40h; uType
00407EBD  mov     [esp+0Ch+lpName], offset Caption; "MineSweeper Rush"
00407EC5  mov     [esp+0Ch+bInitialOwner], offset Text; "The old game MineSweeper Tetris is reti"...
00407ECD  mov     [esp+0Ch+lpMutexAttributes], 0; hWnd
00407ED4  call    MessageBoxA
00407ED9  sub     esp, 10h
00407EDC  cmp     [ebp+var_974], 0
00407EE3  jz      short loc_407F33
00407EE5  call    sub_40E63C
00407EEA  mov     edx, [eax]
00407EEC  mov     ecx, eax
00407EEE  call    dword ptr [edx+5Ch]
00407EF1  mov     [esp+0Ch+lpMutexAttributes], offset off_4184D4
00407EF8  mov     edi, eax
00407EFA  call    ds:SteamInternal_ContextInit
00407F00  mov     ecx, [eax]
00407F02  mov     eax, [ecx]
00407F04  call    dword ptr [eax+10h]
00407F07  mov     esi, eax
00407F09  mov     eax, [ebp+Str2]
00407F0F  mov     [esp+0Ch+lpMutexAttributes], esi; Str1
00407F12  mov     [esp+0Ch+bInitialOwner], eax; Str2
00407F16  call    strcmp
00407F1B  test    eax, eax
00407F1D  jnz     short loc_407F24
00407F1F  mov     [esp+0Ch+lpMutexAttributes], edi
00407F22  jmp     short loc_407F27
00407F24  mov     [esp+0Ch+lpMutexAttributes], esi; char *
00407F27  lea     ecx, [ebp+var_AD0]
00407F2D  call    sub_40EB14
00407F32  push    eax
00407F33  mov     [ebp+Memory], 0
00407F3D  lea     edi, [ebp+var_334]
00407F43  mov     esi, offset off_418400
00407F48  mov     ecx, 8
00407F4D  rep movsd
00407F4F  mov     [ebp+var_314], 0
00407F59  mov     [ebp+var_310], 1
00407F63  lea     edi, [ebp+var_230]
00407F69  mov     [ebp+var_30C], 2
00407F73  mov     [ebp+var_308], 3
00407F7D  mov     esi, offset unk_418420
00407F82  mov     [ebp+var_304], 4
00407F8C  mov     [ebp+var_300], 5
00407F96  mov     ecx, 0Dh
00407F9B  mov     [ebp+var_2FC], 6
00407FA5  mov     [ebp+var_2F8], 7
00407FAF  mov     [ebp+var_2F4], 0
00407FB9  mov     byte ptr [ebp+var_2F0], 1
00407FC0  mov     byte ptr [ebp+var_2F0+1], 1
00407FC7  mov     [ebp+var_2EC], 0FFFFFF00h
00407FD1  mov     [ebp+var_2C8], 0
00407FDB  mov     [ebp+var_2C4], 0
00407FE5  mov     [ebp+var_2BC], 0
00407FEF  mov     [ebp+var_2B8], 0
00407FF6  mov     [ebp+var_250], 1
00408000  mov     [ebp+var_24C], 0
0040800A  mov     [ebp+var_244], 0
00408014  mov     [ebp+var_238], 1
0040801E  rep movsd
00408020  lea     edi, [ebp+var_1FC]
00408026  mov     esi, offset unk_418460
0040802B  mov     ecx, 0Dh
00408030  rep movsd
00408032  lea     edi, [ebp+var_1C8]
00408038  mov     esi, offset unk_4184A0
0040803D  mov     ecx, 0Dh
00408042  rep movsd
00408044  mov     [esp+0Ch+bInitialOwner], 50h; SizeOfElements
0040804C  mov     [esp+0Ch+lpMutexAttributes], 4000h; NumOfElements
00408053  mov     [ebp+var_194], 0
0040805A  call    calloc
0040805F  mov     [esp+0Ch+bInitialOwner], 200h; SizeOfElements
00408067  mov     [esp+0Ch+lpMutexAttributes], 80h; NumOfElements
0040806E  mov     [ebp+var_140], eax
00408074  call    calloc
00408079  mov     [esp+0Ch+lpMutexAttributes], 0; Time
00408080  mov     [ebp+var_138], eax
00408086  call    time
0040808B  mov     esi, eax
0040808D  call    clock
00408092  add     esi, eax
00408094  mov     [esp+0Ch+lpMutexAttributes], esi; Seed
00408097  call    srand
0040809C  lea     ecx, [ebp+var_130]
004080A2  call    sub_40D04C
004080A7  fld1
004080A9  lea     eax, [ebp+CriticalSection]
004080AC  mov     [ebp+var_EC], 6
004080B6  mov     [ebp+var_E8], 0
004080C0  mov     byte ptr [ebp+var_E4], 1
004080C7  fstp    [ebp+var_C8]
004080CD  mov     byte ptr [ebp+var_E4+1], 0
004080D4  mov     byte ptr [ebp+var_E4+2], 0
004080DB  mov     [ebp+var_E0], 0
004080E5  mov     [ebp+var_DC], 0
004080EF  mov     [ebp+var_D8], 258h
004080F9  mov     [ebp+var_D4], 320h
00408103  mov     [ebp+var_D0], 0
0040810D  mov     [ebp+var_94], 0
00408114  mov     [ebp+var_93], 0
0040811B  mov     [ebp+var_90], 0
00408125  mov     [ebp+var_8C], 0
0040812F  mov     [ebp+var_88], 0
00408139  fldz
0040813B  mov     [ebp+var_84], 0
00408145  mov     [ebp+var_70], 0
0040814C  mov     [ebp+var_6C], 0
00408153  mov     [ebp+var_68], 0
0040815A  fst     qword ptr [ebp+dwNewLong]
0040815D  mov     [ebp+var_64], 0
00408164  mov     byte ptr [ebp+var_60], 1
00408168  mov     [ebp+var_5C], 0
0040816F  mov     [ebp+var_58], 0
00408173  mov     [ebp+var_57], 0
00408177  mov     [ebp+var_54], 0FFFFFFFFh
0040817E  mov     [ebp+var_50], 0FFFFFFFFh
00408185  mov     byte ptr [ebp+hKey], 0
00408189  mov     [ebp+lpValueName], 0
00408190  mov     byte ptr [ebp+Reserved], 0
00408194  mov     [ebp+hWnd], 0
0040819B  fstp    dword ptr [ebp+var_11F8]
004081A1  mov     [esp+0Ch+lpMutexAttributes], eax; lpCriticalSection
004081A4  call    InitializeCriticalSection
004081A9  mov     ecx, [ebp+var_B78]
004081AF  push    eax
004081B0  mov     edx, [ebp+var_B84]
004081B6  mov     eax, [ebp+var_B8C]
004081BC  mov     [ebp+var_B50], ecx
004081C2  mov     ecx, [ebp+var_B74]
004081C8  mov     [ebp+var_B5C], edx
004081CE  mov     edx, [ebp+var_B80]
004081D4  mov     [ebp+var_B64], eax
004081DA  mov     eax, [ebp+var_B88]
004081E0  mov     [ebp+var_B4C], ecx
004081E6  mov     ecx, [ebp+var_B70]
004081EC  mov     [ebp+var_B58], edx
004081F2  mov     edx, [ebp+var_B7C]
004081F8  mov     [ebp+var_B60], eax
004081FE  mov     [ebp+var_B40], eax
00408204  lea     eax, [ebp+pvParam]
00408207  mov     [ebp+var_B48], ecx
0040820D  mov     ecx, [ebp+var_B6C]
00408213  mov     [esp+0Ch+lpSecurityAttributes], 0; fWinIni
0040821B  mov     [esp+0Ch+lpName], eax; pvParam
0040821F  mov     [esp+0Ch+bInitialOwner], 0; uiParam
00408227  mov     [esp+0Ch+lpMutexAttributes], 30h; uiAction
0040822E  mov     [ebp+var_B54], edx
00408234  mov     [ebp+var_260], edx
0040823A  mov     [ebp+var_B44], ecx
00408240  call    SystemParametersInfoA
00408245  mov     eax, [ebp+var_78]
00408248  sub     eax, [ebp+pvParam]
0040824B  sub     esp, 10h
0040824E  lea     ecx, [ebp+var_B38]
00408254  mov     [esp+0Ch+bInitialOwner], offset aMult; "mult"
0040825C  mov     [ebp+var_68], eax
0040825F  mov     eax, [ebp+var_74]
00408262  sub     eax, [ebp+var_7C]
00408265  mov     [ebp+var_64], eax
00408268  mov     eax, dword ptr [ebp+FileName]
0040826E  mov     [ebp+var_90], eax
00408274  mov     eax, [ebp+var_E14]
0040827A  mov     [ebp+var_8C], eax
00408280  lea     eax, [ebp+var_D0]
00408286  mov     [esp+0Ch+lpName], eax; int
0040828A  mov     eax, [ebp+var_B38]
00408290  mov     [esp+0Ch+lpMutexAttributes], eax; HKEY
00408293  call    sub_40EAC4
00408298  mov     ecx, ebx
0040829A  sub     esp, 0Ch
0040829D  call    sub_40FA4C
004082A2  fild    [ebp+pvParam]
004082A5  fstp    [ebp+var_11E8]
004082AB  fild    [ebp+var_90]
004082B1  fmul    [ebp+var_C8]
004082B7  fisubr  [ebp+var_68]
004082BA  fstp    [ebp+var_11F0]
004082C0  call    sub_412DB9
004082C5  add     eax, eax
004082C7  fld     [ebp+var_11F0]
004082CD  mov     dword ptr [ebp+var_11D8], eax
004082D3  fisub   dword ptr [ebp+var_11D8]
004082D9  fld     ds:flt_419780
004082DF  fmul    st(1), st
004082E1  fld     dword ptr [ebp+var_11F8]
004082E7  fld     st
004082E9  fucom   st(3)
004082EB  fnstsw  ax
004082ED  fstp    st(3)
004082EF  fxch    st(1)
004082F1  fstp    [ebp+var_11D8]
004082F7  sahf
004082F8  fstp    [ebp+var_11F0]
004082FE  ja      short loc_408336
00408300  fstp    st
00408302  fild    [ebp+var_90]
00408308  fmul    [ebp+var_C8]
0040830E  fisubr  [ebp+var_68]
00408311  fstp    [ebp+var_1200]
00408317  call    sub_412DB9
0040831C  add     eax, eax
0040831E  fld     [ebp+var_1200]
00408324  mov     dword ptr [ebp+var_11F8], eax
0040832A  fisub   dword ptr [ebp+var_11F8]
00408330  fmul    [ebp+var_11D8]
00408336  fadd    [ebp+var_11E8]
0040833C  fnstcw  [ebp+var_11C2]
00408342  mov     ax, [ebp+var_11C2]
00408349  or      ah, 0Ch
0040834C  mov     [ebp+var_11C4], ax
00408353  fldcw   [ebp+var_11C4]
00408359  fistp   [ebp+var_88]
0040835F  fldcw   [ebp+var_11C2]
00408365  fild    [ebp+var_7C]
00408368  fstp    [ebp+var_11E8]
0040836E  fild    [ebp+var_8C]
00408374  fmul    [ebp+var_C8]
0040837A  fisubr  [ebp+var_64]
0040837D  fstp    [ebp+var_1200]
00408383  call    sub_412D92
00408388  add     eax, eax
0040838A  fld     [ebp+var_1200]
00408390  mov     dword ptr [ebp+var_11F8], eax
00408396  fisub   dword ptr [ebp+var_11F8]
0040839C  fstp    [ebp+var_1200]
004083A2  call    sub_412E16
004083A7  fld     [ebp+var_1200]
004083AD  mov     dword ptr [ebp+var_11F8], eax
004083B3  fisub   dword ptr [ebp+var_11F8]
004083B9  fmul    [ebp+var_11D8]
004083BF  fldz
004083C1  fld     [ebp+var_11F0]
004083C7  fucomp  st(2)
004083C9  fnstsw  ax
004083CB  fstp    st(1)
004083CD  sahf
004083CE  ja      short loc_408423
004083D0  fstp    st
004083D2  fild    [ebp+var_8C]
004083D8  fmul    [ebp+var_C8]
004083DE  fisubr  [ebp+var_64]
004083E1  fstp    [ebp+var_11F8]
004083E7  call    sub_412D92
004083EC  fld     [ebp+var_11F8]
004083F2  add     eax, eax
004083F4  mov     dword ptr [ebp+var_11F0], eax
004083FA  fisub   dword ptr [ebp+var_11F0]
00408400  fstp    [ebp+var_11F8]
00408406  call    sub_412E16
0040840B  fld     [ebp+var_11F8]
00408411  mov     dword ptr [ebp+var_11F0], eax
00408417  fisub   dword ptr [ebp+var_11F0]
0040841D  fmul    [ebp+var_11D8]
00408423  fadd    [ebp+var_11E8]
00408429  fnstcw  [ebp+var_11C2]
0040842F  mov     ax, [ebp+var_11C2]
00408436  mov     edx, [ebp+var_B60]
0040843C  mov     ecx, [ebp+var_88]
00408442  mov     [esp+0Ch+bInitialOwner], 0; dwFlags
0040844A  mov     [esp+0Ch+lpMutexAttributes], 0FDE9h; CodePage
00408451  or      ah, 0Ch
00408454  mov     [esp+0Ch+dwFlagsAndAttributes], 7Fh; cchWideChar
0040845C  mov     [esp+0Ch+lpSecurityAttributes], 0FFFFFFFFh; cbMultiByte
00408464  mov     [ebp+var_11C4], ax
0040846B  lea     eax, [ebp+WideCharStr]
00408471  mov     dword ptr [ebp+var_11F8], edx
00408477  mov     dword ptr [ebp+var_11F0], ecx
0040847D  mov     [esp+0Ch+lpName], offset MultiByteStr; "MineSweeperRushClass"
00408485  fldcw   [ebp+var_11C4]
0040848B  fistp   [ebp+var_11C8]
00408491  fldcw   [ebp+var_11C2]
00408497  mov     dword ptr [ebp+var_11D8], eax
0040849D  mov     [esp+10h], eax; lpWideCharStr
004084A1  mov     ebx, [ebp+var_11C8]
004084A7  fld     [ebp+var_C8]
004084AD  mov     [ebp+var_84], ebx
004084B3  fld     st
004084B5  fimul   [ebp+var_8C]
004084BB  fldcw   [ebp+var_11C4]
004084C1  fistp   [ebp+var_11E8]
004084C7  fldcw   [ebp+var_11C2]
004084CD  fimul   [ebp+var_90]
004084D3  fldcw   [ebp+var_11C4]
004084D9  fistp   [ebp+var_11D0]
004084DF  fldcw   [ebp+var_11C2]
004084E5  mov     esi, dword ptr [ebp+var_11D0]
004084EB  call    MultiByteToWideChar
004084F0  mov     eax, dword ptr [ebp+var_11D8]
004084F6  mov     edx, dword ptr [ebp+var_11F8]
004084FC  sub     esp, 18h
004084FF  mov     ecx, dword ptr [ebp+var_11F0]
00408505  mov     [esp+0Ch+dwFlagsAndAttributes], 0; lpThreadId
0040850D  mov     dword ptr [esp+10h], 0; dwCreationFlags
00408515  mov     [esp+0Ch+lpSecurityAttributes], 0; lpParameter
0040851D  mov     lpClassName, eax
00408522  mov     eax, dword ptr [ebp+var_11E8]
00408528  mov     [esp+0Ch+lpName], offset StartAddress; lpStartAddress
00408530  mov     [esp+0Ch+bInitialOwner], 0; dwStackSize
00408538  mov     [esp+0Ch+lpMutexAttributes], 0; lpThreadAttributes
0040853F  mov     ds:dword_4561A0, esi
00408545  mov     ds:dword_4561A4, eax
0040854A  mov     ds:X, ecx
00408550  mov     ds:Y, ebx
00408556  mov     ds:color, edx
0040855C  mov     ds:dword_41E048, edx
00408562  mov     ds:dwStyle, 10C80000h
0040856C  call    CreateThread
00408571  sub     esp, 18h
00408574  cmp     ds:byte_41E168, 0
0040857B  jnz     short loc_40858C
0040857D  mov     [esp+0Ch+lpMutexAttributes], 1; dwMilliseconds
00408584  call    Sleep
00408589  push    eax
0040858A  jmp     short loc_408574
0040858C  mov     eax, ds:hdc
00408591  mov     [esp+0Ch+bInitialOwner], 1; mode
00408599  mov     [esp+0Ch+lpMutexAttributes], eax; hdc
0040859C  call    SetBkMode
004085A1  push    eax
004085A2  push    eax
004085A3  xor     edx, edx
004085A5  xor     eax, eax
004085A7  call    sub_4124DF
004085AC  mov     edx, [ebp+var_8C]
004085B2  mov     eax, [ebp+var_90]
004085B8  call    sub_412A2E
004085BD  fnstcw  [ebp+var_11C2]
004085C3  fld     [ebp+var_C8]
004085C9  mov     [ebp+var_E0], eax
004085CF  mov     ax, [ebp+var_11C2]
004085D6  mov     ecx, [ebp+var_B40]
004085DC  fld     st
004085DE  fimul   [ebp+var_8C]
004085E4  or      ah, 0Ch
004085E7  mov     [esp+0Ch+lpMutexAttributes], ecx
004085EA  mov     [ebp+var_11C4], ax
004085F1  fldcw   [ebp+var_11C4]
004085F7  fistp   [ebp+var_11D0]
004085FD  fldcw   [ebp+var_11C2]
00408603  mov     eax, dword ptr [ebp+var_11D0]
00408609  fimul   [ebp+var_90]
0040860F  mov     ecx, eax
00408611  xor     eax, eax
00408613  fldcw   [ebp+var_11C4]
00408619  fistp   [ebp+var_11D0]
0040861F  fldcw   [ebp+var_11C2]
00408625  mov     esi, dword ptr [ebp+var_11D0]
0040862B  mov     edx, esi
0040862D  call    sub_41251C
00408632  mov     [ebp+var_DC], eax
00408638  mov     eax, ds:hInstance
0040863D  mov     [esp+0Ch+dwFlagsAndAttributes], 0; fuLoad
00408645  mov     dword ptr [esp+10h], 0; cy
0040864D  mov     [esp+0Ch+lpSecurityAttributes], 0; cx
00408655  mov     [esp+0Ch+lpName], 1; type
0040865D  mov     [esp+0Ch+bInitialOwner], offset name; "MINESWEEPERRUSH_ICON"
00408665  mov     [esp+0Ch+lpMutexAttributes], eax; hInst
00408668  call    LoadImageA
0040866D  sub     esp, 18h
00408670  mov     [ebp+var_B28], eax
00408676  mov     [esp+0Ch+dwFlagsAndAttributes], 8050h; fuLoad
0040867E  mov     dword ptr [esp+10h], 0; cy
00408686  mov     [esp+0Ch+lpSecurityAttributes], 0; cx
0040868E  mov     [esp+0Ch+lpName], 1; type
00408696  mov     [esp+0Ch+bInitialOwner], offset aDataMinesweepe; "./data/MineSweeperRush.ico"
0040869E  mov     [esp+0Ch+lpMutexAttributes], 0; hInst
004086A5  call    LoadImageA
004086AA  mov     edx, [ebp+var_B28]
004086B0  sub     esp, 18h
004086B3  mov     [ebp+var_B24], eax
004086B9  test    edx, edx
004086BB  jz      short loc_4086C5
004086BD  mov     [ebp+lParam], edx
004086C3  jmp     short loc_4086CB
004086C5  mov     [ebp+lParam], eax
004086CB  mov     eax, [ebp+lParam]
004086D1  mov     [esp+0Ch+lpName], 1; wParam
004086D9  mov     [esp+0Ch+bInitialOwner], 80h; Msg
004086E1  mov     [esp+0Ch+lpSecurityAttributes], eax; lParam
004086E5  mov     eax, ds:hWnd
004086EA  mov     [esp+0Ch+lpMutexAttributes], eax; hWnd
004086ED  call    SendMessageA
004086F2  sub     esp, 10h
004086F5  mov     [esp+0Ch+lpMutexAttributes], 0Ah; dwMilliseconds
004086FC  call    Sleep
00408701  mov     eax, [ebp+lParam]
00408707  push    ebx
00408708  lea     ebx, [ebp+WideCharStr]
0040870E  mov     [esp+0Ch+lpName], 0; wParam
00408716  mov     [esp+0Ch+bInitialOwner], 80h; Msg
0040871E  mov     [esp+0Ch+lpSecurityAttributes], eax; lParam
00408722  mov     eax, ds:hWnd
00408727  mov     [esp+0Ch+lpMutexAttributes], eax; hWnd
0040872A  call    SendMessageA
0040872F  sub     esp, 10h
00408732  mov     [esp+0Ch+lpMutexAttributes], 0Ah; dwMilliseconds
00408739  call    Sleep
0040873E  mov     edx, [ebp+var_9D4]
00408744  mov     eax, [ebp+var_9D8]
0040874A  push    esi
0040874B  lea     esi, [ebp+FileName]
00408751  mov     eax, [eax+edx*4]
00408754  mov     [esp+0Ch+bInitialOwner], eax; lpString
00408758  mov     eax, ds:hWnd
0040875D  mov     [esp+0Ch+lpMutexAttributes], eax; hWnd
00408760  call    SetWindowTextW
00408765  push    edi
00408766  push    edi
00408767  mov     [esp+0Ch+lpSecurityAttributes], 0; fWinIni
0040876F  mov     [esp+0Ch+lpName], ebx; pvParam
00408773  mov     [esp+0Ch+bInitialOwner], 3Ch; uiParam
0040877B  mov     [esp+0Ch+lpMutexAttributes], 1Fh; uiAction
00408782  call    SystemParametersInfoA
00408787  lea     eax, [ebp+Source]
0040878D  sub     esp, 10h
00408790  mov     [esp+0Ch+lpMutexAttributes], offset pszFaceName; Dest
00408797  mov     [esp+0Ch+bInitialOwner], eax; Source
0040879B  call    strcpy
004087A0  call    sub_412D22
004087A5  mov     eax, [ebp+var_DC]
004087AB  call    sub_412C4D
004087B0  mov     ecx, esi
004087B2  mov     [esp+0Ch+lpMutexAttributes], 0FFFFFFFFh
004087B9  call    sub_413BEC
004087BE  mov     edi, [ebp+var_68]
004087C1  push    eax
004087C2  call    sub_412DB9
004087C7  add     eax, eax
004087C9  mov     ecx, 10h
004087CE  sub     edi, eax
004087D0  mov     dword ptr [ebp+var_11D8], ecx
004087D6  mov     eax, edi
004087D8  mov     edi, [ebp+var_64]
004087DB  sub     edi, [ebp+var_E04]
004087E1  cdq
004087E2  sub     edi, [ebp+var_DFC]
004087E8  idiv    ecx
004087EA  dec     eax
004087EB  mov     [ebp+var_270], eax
004087F1  call    sub_412D92
004087F6  add     eax, eax
004087F8  sub     edi, eax
004087FA  call    sub_412E16
004087FF  mov     ecx, dword ptr [ebp+var_11D8]
00408805  sub     edi, eax
00408807  mov     dword ptr [esp+14h], 0; lpThreadId
0040880F  mov     eax, edi
00408811  mov     [esp+10h+lpSecurityAttributes], 0; dwCreationFlags
00408819  mov     [esp+10h+lpName], esi; lpParameter
0040881D  cdq
0040881E  mov     [esp+10h+bInitialOwner], offset sub_40E150; lpStartAddress
00408826  mov     [esp+10h+lpMutexAttributes], 0; dwStackSize
0040882E  idiv    ecx
00408830  mov     [esp+10h+lpThreadAttributes], 0; lpThreadAttributes
00408837  mov     ds:dword_41E164, 1
00408841  dec     eax
00408842  mov     [ebp+var_26C], eax
00408848  call    CreateThread
0040884D  sub     esp, 18h
00408850  cmp     ds:byte_41E168, 0
00408857  jz      loc_408AA5
0040885D  lea     eax, [ebp+var_E4]
00408863  lea     ecx, [ebp+var_B38]
00408869  mov     [esp+10h+lpMutexAttributes], offset aHelpb; "helpb"
00408871  mov     [esp+10h+bInitialOwner], eax; int
00408875  mov     eax, [ebp+var_B38]
0040887B  mov     [esp+10h+lpThreadAttributes], eax; HKEY
0040887E  call    sub_40EAC4
00408883  lea     eax, [ebp+var_B68]
00408889  sub     esp, 0Ch
0040888C  lea     ecx, [ebp+var_B38]
00408892  mov     [esp+10h+lpMutexAttributes], offset aColori; "colori"
0040889A  mov     [esp+10h+bInitialOwner], eax; int
0040889E  mov     eax, [ebp+var_B38]
004088A4  mov     [esp+10h+lpThreadAttributes], eax; HKEY
004088A7  call    sub_40EAC4
004088AC  lea     eax, [ebp+var_5C]
004088AF  sub     esp, 0Ch
004088B2  lea     ecx, [ebp+var_B38]
004088B8  mov     [esp+10h+lpMutexAttributes], offset aMd; "md"
004088C0  mov     [esp+10h+bInitialOwner], eax; int
004088C4  mov     eax, [ebp+var_B38]
004088CA  mov     [esp+10h+lpThreadAttributes], eax; HKEY
004088CD  call    sub_40EAC4
004088D2  lea     eax, [ebp+var_2F0]
004088D8  sub     esp, 0Ch
004088DB  lea     ecx, [ebp+var_B38]
004088E1  mov     [esp+10h+lpMutexAttributes], offset aSoundb; "soundb"
004088E9  mov     [esp+10h+bInitialOwner], eax; int
004088ED  mov     eax, [ebp+var_B38]
004088F3  mov     [esp+10h+lpThreadAttributes], eax; HKEY
004088F6  call    sub_40EAC4
004088FB  lea     eax, [ebp+var_2F0+1]
00408901  sub     esp, 0Ch
00408904  lea     ecx, [ebp+var_B38]
0040890A  mov     [esp+10h+lpMutexAttributes], offset aMusicb; "musicb"
00408912  mov     [esp+10h+bInitialOwner], eax; int
00408916  mov     eax, [ebp+var_B38]
0040891C  mov     [esp+10h+lpThreadAttributes], eax; HKEY
0040891F  call    sub_40EAC4
00408924  lea     eax, [ebp+var_D0]
0040892A  sub     esp, 0Ch
0040892D  lea     ecx, [ebp+var_B38]
00408933  mov     [esp+10h+lpMutexAttributes], offset aMult; "mult"
0040893B  mov     [esp+10h+bInitialOwner], eax; int
0040893F  mov     eax, [ebp+var_B38]
00408945  mov     [esp+10h+lpThreadAttributes], eax; HKEY
00408948  call    sub_40EAC4
0040894D  lea     eax, [ebp+var_250]
00408953  sub     esp, 0Ch
00408956  lea     ecx, [ebp+var_B38]
0040895C  mov     [esp+10h+lpMutexAttributes], offset aDelayb; "delayb"
00408964  mov     [esp+10h+bInitialOwner], eax; int
00408968  mov     eax, [ebp+var_B38]
0040896E  mov     [esp+10h+lpThreadAttributes], eax; HKEY
00408971  call    sub_40EAC4
00408976  lea     eax, [ebp+var_60]
00408979  sub     esp, 0Ch
0040897C  lea     ecx, [ebp+var_B38]
00408982  mov     [esp+10h+lpMutexAttributes], offset aBarb; "barb"
0040898A  mov     [esp+10h+bInitialOwner], eax; int
0040898E  mov     eax, [ebp+var_B38]
00408994  mov     [esp+10h+lpThreadAttributes], eax; HKEY
00408997  call    sub_40EAC4
0040899C  lea     eax, [ebp+Reserved]
0040899F  sub     esp, 0Ch
004089A2  lea     ecx, [ebp+var_B38]
004089A8  mov     [esp+10h+lpMutexAttributes], offset aSingleb; "singleb"
004089B0  mov     [esp+10h+bInitialOwner], eax; int
004089B4  mov     eax, [ebp+var_B38]
004089BA  mov     [esp+10h+lpThreadAttributes], eax; HKEY
004089BD  call    sub_40EAC4
004089C2  sub     esp, 0Ch
004089C5  call    sub_40E28A
004089CA  test    eax, eax
004089CC  jz      loc_408AA5
004089D2  call    sub_40E28A
004089D7  mov     edx, [eax]
004089D9  mov     ecx, eax
004089DB  mov     [esp+10h+lpThreadAttributes], offset aRegDat; "reg.dat"
004089E2  call    dword ptr [edx+34h]
004089E5  test    al, al
004089E7  push    ecx
004089E8  jz      loc_408AA5
004089EE  xor     eax, eax
004089F0  mov     ecx, 9
004089F5  mov     edi, ebx
004089F7  rep stosd
004089F9  call    sub_40E28A
004089FE  mov     edx, [eax]
00408A00  mov     ecx, eax
00408A02  mov     [esp+14h+var_14], offset aRegDat; "reg.dat"
00408A09  call    dword ptr [edx+3Ch]
00408A0C  cmp     eax, 24h
00408A0F  push    edx
00408A10  jnz     loc_408AA5
00408A16  call    sub_40E28A
00408A1B  mov     edx, [eax]
00408A1D  mov     ecx, eax
00408A1F  mov     [esp+18h+lpThreadAttributes], 24h
00408A27  mov     [esp+18h+var_14], ebx
00408A2B  mov     [esp+18h+var_18], offset aRegDat; "reg.dat"
00408A32  call    dword ptr [edx+4]
00408A35  sub     esp, 0Ch
00408A38  cmp     dword ptr [ebp+WideCharStr], 0
00408A3F  mov     eax, [ebp+var_10AC]
00408A45  mov     [ebp+var_B68], eax
00408A4B  mov     eax, [ebp+var_10A8]
00408A51  setnz   byte ptr [ebp+var_E4]
00408A58  cmp     [ebp+var_10A4], 0
00408A5F  mov     [ebp+var_5C], eax
00408A62  mov     eax, [ebp+var_109C]
00408A68  setnz   byte ptr [ebp+var_2F0]
00408A6F  cmp     [ebp+var_10A0], 0
00408A76  mov     [ebp+var_D0], eax
00408A7C  mov     eax, [ebp+var_1098]
00408A82  setnz   byte ptr [ebp+var_2F0+1]
00408A89  cmp     dword ptr [ebp+Source], 0
00408A90  mov     [ebp+var_250], eax
00408A96  setnz   byte ptr [ebp+var_60]
00408A9A  cmp     [ebp+var_1090], 0
00408AA1  setnz   byte ptr [ebp+Reserved]
00408AA5  mov     eax, [ebp+var_9AC]
00408AAB  mov     ecx, esi
00408AAD  mov     [esp+24h+CriticalSection.OwningThread], eax
00408AB0  call    sub_413BEC
00408AB5  cmp     ds:byte_41E168, 0
00408ABC  push    eax
00408ABD  jz      loc_408DA4
00408AC3  cmp     [ebp+var_974], 0
00408ACA  jz      loc_408DA4
00408AD0  call    sub_40E2A1
00408AD5  mov     edx, [eax]
00408AD7  mov     ecx, eax
00408AD9  call    dword ptr [edx]
00408ADB  test    al, al
00408ADD  jnz     short loc_408B1B
00408ADF  mov     eax, [ebp+var_9D8]
00408AE5  mov     edx, [ebp+var_9D4]
00408AEB  mov     [esp+28h+CriticalSection.SpinCount], 30h; uType
00408AF3  mov     edx, [eax+edx*4]
00408AF6  mov     [esp+28h+CriticalSection.LockSemaphore], edx; lpCaption
00408AFA  mov     edx, [ebp+var_9C4]
00408B00  mov     eax, [eax+edx*4]
00408B03  mov     [esp+28h+CriticalSection.RecursionCount], 0; hWnd
00408B0A  mov     [esp+28h+CriticalSection.OwningThread], eax; lpText
00408B0E  call    MessageBoxW
00408B13  sub     esp, 10h
00408B16  jmp     loc_408DA4
00408B1B  cmp     [ebp+var_974], 0
00408B22  jnz     short loc_408B32
00408B24  cmp     [ebp+var_974], 0
00408B2B  jnz     short loc_408B73
00408B2D  jmp     loc_408C68
00408B32  mov     ds:dword_41E160, offset aLoadAchievemen; "Load Achievement"
00408B3C  mov     ds:dword_41E164, 2
00408B46  xor     ebx, ebx
00408B48  call    sub_40E2A1
00408B4D  lea     ecx, [ebp+ebx+var_8A0]
00408B54  mov     edx, [eax]
00408B56  mov     [esp+28h+CriticalSection.OwningThread], ecx
00408B5A  mov     ecx, [ebp+ebx*4+var_908]
00408B61  inc     ebx
00408B62  mov     [esp+28h+CriticalSection.RecursionCount], ecx
00408B65  mov     ecx, eax
00408B67  call    dword ptr [edx+18h]
00408B6A  cmp     ebx, 1Ah
00408B6D  push    eax
00408B6E  push    eax
00408B6F  jnz     short loc_408B48
00408B71  jmp     short loc_408B24
00408B73  lea     ebx, [ebp+var_808]
00408B79  lea     esi, [ebp+var_7BC]
00408B7F  mov     ds:dword_41E160, offset aLoadStatus; "Load Status"
00408B89  mov     ds:dword_41E164, 2
00408B93  mov     dword ptr [ebx], 0FFFFFFFFh
00408B99  call    sub_40E2A1
00408B9E  mov     edx, [eax]
00408BA0  mov     [esp+28h+CriticalSection.OwningThread], ebx
00408BA4  mov     ecx, [ebx-4Ch]
00408BA7  mov     [esp+28h+CriticalSection.RecursionCount], ecx
00408BAA  mov     ecx, eax
00408BAC  call    dword ptr [edx+8]
00408BAF  push    eax
00408BB0  push    eax
00408BB1  cmp     dword ptr [ebx], 0
00408BB4  jns     short loc_408BCE
00408BB6  call    sub_40E2A1
00408BBB  mov     edx, [eax]
00408BBD  mov     [esp+30h+CriticalSection.LockCount], ebx
00408BC1  mov     ecx, [ebx-4Ch]
00408BC4  mov     [esp+30h+CriticalSection.DebugInfo], ecx
00408BC7  mov     ecx, eax
00408BC9  call    dword ptr [edx+8]
00408BCC  push    edi
00408BCD  push    edi
00408BCE  cmp     dword ptr [ebx], 0
00408BD1  jns     short loc_408BE0
00408BD3  mov     dword ptr [ebx], 0
00408BD9  mov     [ebp+var_974], 0
00408BE0  add     ebx, 4
00408BE3  cmp     esi, ebx
00408BE5  jnz     short loc_408B93
00408BE7  cmp     [ebp+var_974], 0
00408BEE  jz      short loc_408C68
00408BF0  lea     edi, [ebp+var_AD0]
00408BF6  lea     ebx, [ebp+FileName]
00408BFC  mov     ecx, edi
00408BFE  mov     esi, ebx
00408C00  call    sub_40E2D4
00408C05  mov     dword ptr [ebp+var_11E8], ebx
00408C0B  mov     dword ptr [ebp+var_11F8], edi
00408C11  mov     eax, [esi+8D4h]
00408C17  or      eax, [esi+8D0h]
00408C1D  jnz     short loc_408C2A
00408C1F  mov     ecx, dword ptr [ebp+var_11F8]
00408C25  call    sub_40E732
00408C2A  mov     eax, [esi+8D4h]
00408C30  or      eax, [esi+8D0h]
00408C36  jnz     short loc_408C82
00408C38  lea     eax, [ebp+var_E00]
00408C3E  add     esi, 8
00408C41  add     dword ptr [ebp+var_11E8], 4
00408C48  cmp     eax, esi
00408C4A  jnz     short loc_408C11
00408C4C  cmp     [ebp+var_974], 0
00408C53  jz      short loc_408C68
00408C55  lea     ecx, [ebp+var_AD0]
00408C5B  call    sub_40E654
00408C60  test    al, al
00408C62  jnz     loc_408D0F
00408C68  lea     ecx, [ebp+var_AD0]
00408C6E  call    sub_40E732
00408C73  mov     ds:dword_41E160, 0
00408C7D  jmp     loc_408DA4
00408C82  mov     edi, esi
00408C84  mov     dword ptr [ebp+var_11D8], 0
00408C8E  call    sub_40E2A1
00408C93  imul    ecx, dword ptr [ebp+var_11D8], 0Ch
00408C9A  mov     edx, [eax]
00408C9C  mov     [esp+38h+CriticalSection.OwningThread], 0
00408CA4  add     edi, 18h
00408CA7  mov     [esp+38h+CriticalSection.RecursionCount], 0
00408CAF  mov     dword ptr [ebp+var_11F0], edx
00408CB5  mov     edx, dword ptr [ebp+var_11E8]
00408CBB  mov     ecx, [edx+ecx+620h]
00408CC2  mov     [esp+38h+CriticalSection.DebugInfo], 1
00408CCA  mov     [esp+38h+CriticalSection.LockCount], ecx
00408CCE  mov     ecx, [edi+8BCh]
00408CD4  mov     edx, [edi+8B8h]
00408CDA  mov     [esp+38h+dwNewLong+4], ecx
00408CDE  mov     ecx, eax
00408CE0  mov     eax, dword ptr [ebp+var_11F0]
00408CE6  mov     [esp+38h+dwNewLong], edx
00408CE9  call    dword ptr [eax+7Ch]
00408CEC  inc     dword ptr [ebp+var_11D8]
00408CF2  mov     [edi+690h], eax
00408CF8  sub     esp, 18h
00408CFB  mov     [edi+694h], edx
00408D01  cmp     dword ptr [ebp+var_11D8], 5
00408D08  jnz     short loc_408C8E
00408D0A  jmp     loc_408C38
00408D0F  mov     eax, [ebx+8D4h]
00408D15  or      eax, [ebx+8D0h]
00408D1B  jnz     short loc_408D27
00408D1D  add     ebx, 8
00408D20  cmp     esi, ebx
00408D22  jmp     loc_408C62
00408D27  xor     edi, edi
00408D29  call    sub_40E63C
00408D2E  mov     edx, [eax]
00408D30  mov     [esp+38h+CriticalSection.RecursionCount], 452h
00408D38  mov     [esp+38h+CriticalSection.LockCount], 20h
00408D40  mov     dword ptr [ebp+var_11D8], edx
00408D46  lea     edx, [ebp+var_368]
00408D4C  mov     [esp+38h+CriticalSection.OwningThread], edx
00408D50  lea     edx, [ebp+var_580]
00408D56  mov     [esp+38h+CriticalSection.DebugInfo], edx
00408D5A  mov     ecx, [ebx+edi+6ACh]
00408D61  mov     edx, [ebx+edi+6A8h]
00408D68  mov     [esp+38h+dwNewLong+4], ecx
00408D6C  mov     ecx, eax
00408D6E  mov     eax, dword ptr [ebp+var_11D8]
00408D74  mov     [esp+38h+dwNewLong], edx
00408D77  call    dword ptr [eax+34h]
00408D7A  mov     eax, [ebp+var_578]
00408D80  mov     edx, [ebp+var_574]
00408D86  sub     esp, 18h
00408D89  mov     [ebx+edi+8D0h], eax
00408D90  mov     [ebx+edi+8D4h], edx
00408D97  add     edi, 18h
00408D9A  cmp     edi, 78h
00408D9D  jnz     short loc_408D29
00408D9F  jmp     loc_408D1D
00408DA4  mov     eax, [ebp+var_9A8]
00408DAA  lea     ecx, [ebp+FileName]
00408DB0  mov     [esp+28h+CriticalSection.RecursionCount], eax
00408DB3  call    sub_413BEC
00408DB8  cmp     ds:byte_41E168, 0
00408DBF  push    ecx
00408DC0  jz      loc_408F8A
00408DC6  lea     ebx, [ebp+WideCharStr]
00408DCC  xor     esi, esi
00408DCE  mov     eax, [ebp+esi*4+var_334]
00408DD5  mov     [esp+2Ch+CriticalSection.RecursionCount], offset aDataWavSWav; "./data/wav/%s.wav"
00408DDD  mov     [esp+2Ch+CriticalSection.LockCount], ebx; Dest
00408DE0  mov     [esp+2Ch+CriticalSection.OwningThread], eax
00408DE4  call    sprintf
00408DE9  mov     eax, ds:dword_4561B0
00408DEE  mov     [esp+2Ch+CriticalSection.LockSemaphore], offset unk_419358
00408DF6  mov     [esp+2Ch+CriticalSection.OwningThread], ebx
00408DFA  mov     [esp+2Ch+CriticalSection.RecursionCount], offset aOpenSSAliasSLu; "open \"%s\"%s alias s%lu"
00408E02  mov     [esp+2Ch+CriticalSection.LockCount], offset Dest; Dest
00408E09  inc     eax
00408E0A  mov     [esp+2Ch+CriticalSection.SpinCount], eax
00408E0E  mov     ds:dword_4561B0, eax
00408E13  call    sprintf
00408E18  call    sub_40F074
00408E1D  mov     eax, ds:dword_4561B0
00408E22  mov     [ebp+esi*4+var_358], eax
00408E29  inc     esi
00408E2A  cmp     esi, 8
00408E2D  jnz     short loc_408DCE
00408E2F  mov     [esp+2Ch+CriticalSection.LockSemaphore], 0; hwndCallback
00408E37  mov     [esp+2Ch+CriticalSection.OwningThread], 0; uReturnLength
00408E3F  mov     [esp+2Ch+CriticalSection.RecursionCount], 0; lpstrReturnString
00408E47  mov     [esp+2Ch+CriticalSection.LockCount], offset strCommand; "open new type sequencer alias miditest"
00408E4E  call    mciSendStringA
00408E53  sub     esp, 10h
00408E56  mov     ebx, eax
00408E58  mov     [esp+2Ch+CriticalSection.LockSemaphore], 0; hwndCallback
00408E60  mov     [esp+2Ch+CriticalSection.OwningThread], 0; uReturnLength
00408E68  mov     [esp+2Ch+CriticalSection.RecursionCount], 0; lpstrReturnString
00408E70  mov     [esp+2Ch+CriticalSection.LockCount], offset aCloseMiditest; "close miditest"
00408E77  call    mciSendStringA
00408E7C  sub     esp, 10h
00408E7F  test    ebx, ebx
00408E81  jz      loc_408F75
00408E87  lea     ebx, [ebp+Dest]
00408E8D  lea     edi, [ebp+WideCharStr]
00408E93  mov     [ebp+var_2F4], 0
00408E9D  xor     esi, esi
00408E9F  cmp     ds:byte_41E168, 0
00408EA6  jz      loc_408F75
00408EAC  inc     esi
00408EAD  mov     [esp+2Ch+CriticalSection.RecursionCount], offset aDataMidMusicLd; "./data/mid/music%ld.mid"
00408EB5  mov     [esp+2Ch+CriticalSection.LockCount], ebx; Dest
00408EB8  mov     [esp+2Ch+CriticalSection.OwningThread], esi
00408EBC  call    sprintf
00408EC1  mov     [esp+2Ch+CriticalSection.RecursionCount], edi; lpFindFileData
00408EC5  mov     [esp+2Ch+CriticalSection.LockCount], ebx; lpFileName
00408EC8  call    FindFirstFileA
00408ECD  cmp     eax, 0FFFFFFFFh
00408ED0  push    edx
00408ED1  push    edx
00408ED2  jz      loc_408F75
00408ED8  mov     [esp+2Ch+CriticalSection.LockCount], eax; hFindFile
00408EDB  call    FindClose
00408EE0  push    eax
00408EE1  mov     eax, [ebp+var_2F4]
00408EE7  lea     eax, ds:4[eax*4]
00408EEE  mov     [esp+2Ch+CriticalSection.RecursionCount], eax; NewSize
00408EF2  mov     eax, [ebp+Memory]
00408EF8  mov     [esp+2Ch+CriticalSection.LockCount], eax; Memory
00408EFB  call    realloc
00408F00  test    eax, eax
00408F02  jz      short loc_408F75
00408F04  mov     edx, [ebp+var_2F4]
00408F0A  mov     [ebp+Memory], eax
00408F10  mov     [esp+2Ch+CriticalSection.LockSemaphore], offset aTypeSequencer; " type sequencer"
00408F18  mov     [esp+2Ch+CriticalSection.OwningThread], ebx
00408F1C  mov     [esp+2Ch+CriticalSection.RecursionCount], offset aOpenSSAliasSLu; "open \"%s\"%s alias s%lu"
00408F24  mov     [esp+2Ch+CriticalSection.LockCount], offset Dest; Dest
00408F2B  lea     edx, [eax+edx*4]
00408F2E  mov     eax, ds:dword_4561B0
00408F33  mov     ds:dword_41E160, ebx
00408F39  mov     ds:dword_41E164, 2
00408F43  mov     dword ptr [ebp+var_11D8], edx
00408F49  inc     eax
00408F4A  mov     [esp+2Ch+CriticalSection.SpinCount], eax
00408F4E  mov     ds:dword_4561B0, eax
00408F53  call    sprintf
00408F58  call    sub_40F074
00408F5D  mov     eax, ds:dword_4561B0
00408F62  mov     edx, dword ptr [ebp+var_11D8]
00408F68  mov     [edx], eax
00408F6A  inc     [ebp+var_2F4]
00408F70  jmp     loc_408E9F
00408F75  lea     ecx, [ebp+var_358]
00408F7B  call    sub_40E998
00408F80  mov     ds:dword_41E160, 0
00408F8A  mov     eax, [ebp+var_9A4]
00408F90  lea     ecx, [ebp+FileName]
00408F96  mov     [esp+2Ch+CriticalSection.LockCount], eax
00408F99  call    sub_413BEC
00408F9E  cmp     ds:byte_41E168, 0
00408FA5  push    edi
00408FA6  jz      loc_409510
00408FAC  mov     eax, [ebp+var_5C]
00408FAF  lea     ebx, [ebp+var_B18]
00408FB5  mov     [esp+30h+CriticalSection.DebugInfo], 1
00408FBC  mov     ecx, ebx
00408FBE  mov     [esp+30h+CriticalSection.LockCount], eax
00408FC2  call    sub_40BE12
00408FC7  lea     eax, [ebp+hWnd]
00408FCA  push    esi
00408FCB  push    esi
00408FCC  lea     ecx, [ebp+var_B38]
00408FD2  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
00408FD6  mov     eax, [ebp+var_B38]
00408FDC  mov     [esp+30h+CriticalSection.LockCount], offset aBoardb; "boardb"
00408FE4  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
00408FE7  call    sub_40EAC4
00408FEC  movzx   eax, byte ptr [ebp+var_E4]
00408FF3  sub     esp, 0Ch
00408FF6  cmp     [ebp+hWnd], 1
00408FFA  mov     [ebp+var_238], eax
00409000  jnz     loc_409510
00409006  lea     eax, [ebp+var_2C8]
0040900C  lea     ecx, [ebp+var_B38]
00409012  mov     [esp+30h+CriticalSection.LockCount], offset aMode; "mode"
0040901A  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
0040901E  mov     eax, [ebp+var_B34]
00409024  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
00409027  call    sub_40EAC4
0040902C  mov     eax, [ebp+var_B34]
00409032  sub     esp, 0Ch
00409035  lea     ecx, [ebp+var_B38]
0040903B  mov     [esp+30h+CriticalSection.RecursionCount], ebx; int
0040903F  mov     [esp+30h+CriticalSection.LockCount], offset aW; "w"
00409047  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
0040904A  call    sub_40EAC4
0040904F  lea     eax, [ebp+var_B14]
00409055  sub     esp, 0Ch
00409058  lea     ecx, [ebp+var_B38]
0040905E  mov     [esp+30h+CriticalSection.LockCount], offset asc_4193DC; "h"
00409066  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
0040906A  mov     eax, [ebp+var_B34]
00409070  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
00409073  call    sub_40EAC4
00409078  lea     eax, [ebp+var_B10]
0040907E  sub     esp, 0Ch
00409081  lea     ecx, [ebp+var_B38]
00409087  mov     [esp+30h+CriticalSection.LockCount], offset aN; "n"
0040908F  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
00409093  mov     eax, [ebp+var_B34]
00409099  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
0040909C  call    sub_40EAC4
004090A1  lea     eax, [ebp+var_2B4]
004090A7  sub     esp, 0Ch
004090AA  lea     ecx, [ebp+var_B38]
004090B0  mov     [esp+30h+CriticalSection.LockCount], offset aMaskj0; "maskj0"
004090B8  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
004090BC  mov     eax, [ebp+var_B34]
004090C2  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
004090C5  call    sub_40EAC4
004090CA  lea     eax, [ebp+var_B0C]
004090D0  sub     esp, 0Ch
004090D3  lea     ecx, [ebp+var_B38]
004090D9  mov     [esp+30h+CriticalSection.LockCount], offset aSit; "sit"
004090E1  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
004090E5  mov     eax, [ebp+var_B34]
004090EB  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
004090EE  call    sub_40EAC4
004090F3  lea     eax, [ebp+var_2AC]
004090F9  sub     esp, 0Ch
004090FC  lea     ecx, [ebp+var_B38]
00409102  mov     [esp+30h+CriticalSection.LockCount], offset aLine; "line"
0040910A  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
0040910E  mov     eax, [ebp+var_B34]
00409114  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
00409117  call    sub_40EAC4
0040911C  lea     eax, [ebp+var_2A8]
00409122  sub     esp, 0Ch
00409125  lea     ecx, [ebp+var_B38]
0040912B  mov     [esp+30h+CriticalSection.LockCount], offset aLevel; "level"
00409133  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
00409137  mov     eax, [ebp+var_B34]
0040913D  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
00409140  call    sub_40EAC4
00409145  lea     eax, [ebp+var_28C]
0040914B  sub     esp, 0Ch
0040914E  lea     ecx, [ebp+var_B38]
00409154  mov     [esp+30h+CriticalSection.LockCount], offset aTetrisi; "tetrisi"
0040915C  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
00409160  mov     eax, [ebp+var_B34]
00409166  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
00409169  call    sub_40EAC4
0040916E  lea     eax, [ebp+var_288]
00409174  sub     esp, 0Ch
00409177  lea     ecx, [ebp+var_B38]
0040917D  mov     [esp+30h+CriticalSection.LockCount], offset aMissi; "missi"
00409185  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
00409189  mov     eax, [ebp+var_B34]
0040918F  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
00409192  call    sub_40EAC4
00409197  lea     eax, [ebp+var_284]
0040919D  sub     esp, 0Ch
004091A0  lea     ecx, [ebp+var_B38]
004091A6  mov     [esp+30h+CriticalSection.LockCount], offset aMissline; "missline"
004091AE  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
004091B2  mov     eax, [ebp+var_B34]
004091B8  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
004091BB  call    sub_40EAC4
004091C0  lea     eax, [ebp+var_27C]
004091C6  sub     esp, 0Ch
004091C9  lea     ecx, [ebp+var_B38]
004091CF  mov     [esp+30h+CriticalSection.LockCount], offset aSum; "sum"
004091D7  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
004091DB  mov     eax, [ebp+var_B34]
004091E1  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
004091E4  call    sub_40EAC4
004091E9  lea     eax, [ebp+var_B04]
004091EF  sub     esp, 0Ch
004091F2  lea     ecx, [ebp+var_B38]
004091F8  mov     [esp+30h+CriticalSection.LockCount], offset aMaskj; "maskj"
00409200  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
00409204  mov     eax, [ebp+var_B34]
0040920A  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
0040920D  call    sub_40EAC4
00409212  lea     eax, [ebp+var_B00]
00409218  sub     esp, 0Ch
0040921B  lea     ecx, [ebp+var_B38]
00409221  mov     [esp+30h+CriticalSection.LockCount], offset aMaski; "maski"
00409229  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
0040922D  mov     eax, [ebp+var_B34]
00409233  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
00409236  call    sub_40EAC4
0040923B  lea     eax, [ebp+var_2BC]
00409241  sub     esp, 0Ch
00409244  lea     ecx, [ebp+var_B38]
0040924A  mov     [esp+30h+CriticalSection.LockCount], offset aRightb; "rightb"
00409252  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
00409256  mov     eax, [ebp+var_B34]
0040925C  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
0040925F  call    sub_40EAC4
00409264  lea     eax, [ebp+var_234]
0040926A  sub     esp, 0Ch
0040926D  lea     ecx, [ebp+var_B38]
00409273  mov     [esp+30h+CriticalSection.LockCount], offset aTuti; "tuti"
0040927B  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
0040927F  mov     eax, [ebp+var_B34]
00409285  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
00409288  call    sub_40EAC4
0040928D  lea     eax, [ebp+var_238]
00409293  sub     esp, 0Ch
00409296  lea     ecx, [ebp+var_B38]
0040929C  mov     [esp+30h+CriticalSection.LockCount], offset aTutb; "tutb"
004092A4  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
004092A8  mov     eax, [ebp+var_B34]
004092AE  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
004092B1  call    sub_40EAC4
004092B6  lea     eax, [ebp+var_29C]
004092BC  sub     esp, 0Ch
004092BF  lea     ecx, [ebp+var_B38]
004092C5  mov     [esp+30h+CriticalSection.LockCount], offset aCheckr; "checkr"
004092CD  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
004092D1  mov     eax, [ebp+var_B34]
004092D7  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
004092DA  call    sub_40EAC4
004092DF  lea     eax, [ebp+var_B08]
004092E5  sub     esp, 0Ch
004092E8  lea     ecx, [ebp+var_B38]
004092EE  mov     [esp+30h+CriticalSection.LockCount], offset aPauseb; "pauseb"
004092F6  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
004092FA  mov     eax, [ebp+var_B34]
00409300  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
00409303  call    sub_40EAC4
00409308  lea     eax, [ebp+var_240]
0040930E  sub     esp, 0Ch
00409311  lea     ecx, [ebp+var_B38]
00409317  mov     [esp+30h+CriticalSection.LockCount], offset aMx; "mx"
0040931F  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
00409323  mov     eax, [ebp+var_B34]
00409329  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
0040932C  call    sub_40EAC4
00409331  lea     eax, [ebp+var_23C]
00409337  sub     esp, 0Ch
0040933A  lea     ecx, [ebp+var_B38]
00409340  mov     [esp+30h+CriticalSection.LockCount], offset aMy; "my"
00409348  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
0040934C  mov     eax, [ebp+var_B34]
00409352  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
00409355  call    sub_40EAC4
0040935A  lea     eax, [ebp+var_280]
00409360  sub     esp, 0Ch
00409363  lea     ecx, [ebp+var_B38]
00409369  mov     [esp+30h+CriticalSection.LockCount], offset aBouns; "bouns"
00409371  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
00409375  mov     eax, [ebp+var_B34]
0040937B  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
0040937E  call    sub_40EAC4
00409383  lea     eax, [ebp+var_248]
00409389  sub     esp, 0Ch
0040938C  lea     ecx, [ebp+var_B38]
00409392  mov     [esp+30h+CriticalSection.LockCount], offset aMdb; "mdb"
0040939A  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
0040939E  mov     eax, [ebp+var_B34]
004093A4  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
004093A7  call    sub_40EAC4
004093AC  lea     eax, [ebp+var_134]
004093B2  sub     esp, 0Ch
004093B5  lea     ecx, [ebp+var_B38]
004093BB  mov     [esp+30h+CriticalSection.LockCount], offset aSolven; "solven"
004093C3  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
004093C7  mov     eax, [ebp+var_B34]
004093CD  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
004093D0  call    sub_40EAC4
004093D5  mov     eax, [ebp+lpData]
004093DB  sub     esp, 0Ch
004093DE  lea     ecx, [ebp+var_B38]
004093E4  mov     [esp+30h+CriticalSection.LockCount], offset ValueName; "flag"
004093EC  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
004093F0  mov     eax, [ebp+var_B34]
004093F6  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
004093F9  call    sub_40EA5A
004093FE  mov     eax, [ebp+var_AF0]
00409404  sub     esp, 0Ch
00409407  lea     ecx, [ebp+var_B38]
0040940D  mov     [esp+30h+CriticalSection.LockCount], offset aQstn; "qstn"
00409415  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
00409419  mov     eax, [ebp+var_B34]
0040941F  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
00409422  call    sub_40EA5A
00409427  mov     eax, [ebp+var_AEC]
0040942D  sub     esp, 0Ch
00409430  lea     ecx, [ebp+var_B38]
00409436  mov     [esp+30h+CriticalSection.LockCount], offset aMine; "mine"
0040943E  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
00409442  mov     eax, [ebp+var_B34]
00409448  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
0040944B  call    sub_40EA5A
00409450  mov     eax, [ebp+var_AE8]
00409456  sub     esp, 0Ch
00409459  lea     ecx, [ebp+var_B38]
0040945F  mov     [esp+30h+CriticalSection.LockCount], offset aBlck; "blck"
00409467  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
0040946B  mov     eax, [ebp+var_B34]
00409471  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
00409474  call    sub_40EA5A
00409479  mov     eax, [ebp+var_AE4]
0040947F  sub     esp, 0Ch
00409482  lea     ecx, [ebp+var_B38]
00409488  mov     [esp+30h+CriticalSection.LockCount], offset aMask; "mask"
00409490  mov     [esp+30h+CriticalSection.RecursionCount], eax; int
00409494  mov     eax, [ebp+var_B34]
0040949A  mov     [esp+30h+CriticalSection.DebugInfo], eax; HKEY
0040949D  call    sub_40EA5A
004094A2  sub     esp, 0Ch
004094A5  call    sub_40E28A
004094AA  test    eax, eax
004094AC  jz      short loc_4094EC
004094AE  call    sub_40E28A
004094B3  mov     edx, [eax]
004094B5  mov     ecx, eax
004094B7  mov     [esp+30h+CriticalSection.DebugInfo], offset aBoardDat; "board.dat"
004094BE  call    dword ptr [edx+34h]
004094C1  test    al, al
004094C3  push    ecx
004094C4  jz      short loc_4094EC
004094C6  call    sub_40E28A
004094CB  mov     edx, [eax]
004094CD  mov     ecx, eax
004094CF  mov     [esp+34h+dwNewLong+4], offset aBoardDat; "board.dat"
004094D6  call    dword ptr [edx+3Ch]
004094D9  cmp     eax, 14064h
004094DE  push    edx
004094DF  jnz     short loc_4094EC
004094E1  lea     ecx, [ebp+FileName]
004094E7  call    sub_413088
004094EC  lea     ecx, [ebp+var_B18]
004094F2  call    sub_40CEC4
004094F7  mov     eax, [ebp+var_B38]
004094FD  xor     ecx, ecx
004094FF  mov     edx, offset aBoardb; "boardb"
00409504  mov     [ebp+hWnd], 0
0040950B  call    sub_413F90
00409510  mov     eax, [ebp+var_9A0]
00409516  lea     ecx, [ebp+FileName]
0040951C  mov     [esp+38h+dwNewLong], eax
0040951F  call    sub_413BEC
00409524  cmp     ds:byte_41E168, 0
0040952B  push    edi
0040952C  jz      short loc_409539
0040952E  lea     ecx, [ebp+FileName]
00409534  call    sub_40D14C
00409539  mov     eax, [ebp+var_99C]
0040953F  lea     ecx, [ebp+FileName]
00409545  mov     [esp+3Ch+nIndex], eax
00409548  call    sub_413BEC
0040954D  cmp     ds:byte_41E168, 0
00409554  push    esi
00409555  jz      short loc_40958A
00409557  mov     eax, ds:hWnd
0040955C  mov     [esp+40h+dwNewLong], 10CB0000h; dwNewLong
00409564  mov     [esp+40h+nIndex], 0FFFFFFF0h; nIndex
0040956C  mov     [esp+40h+hWnd], eax; hWnd
0040956F  call    SetWindowLongA
00409574  lea     ecx, [ebp+FileName]; lpParameter
0040957A  sub     esp, 0Ch
0040957D  mov     [esp+40h+hWnd], 0; int
00409584  call    sub_4138C4
00409589  push    ebx
0040958A  mov     ds:dword_41E164, 0
00409594  cmp     ds:byte_41E168, 0
0040959B  jz      short loc_4095EB
0040959D  mov     ebx, offset unk_456184
004095A2  mov     edx, dword_4184E4
004095A8  imul    eax, edx, 1Ch
004095AB  add     eax, offset unk_41E180
004095B0  cmp     dword ptr [eax+4], 0
004095B4  jz      loc_409B89
004095BA  inc     edx
004095BB  mov     edi, offset unk_456184
004095C0  mov     ecx, 7
004095C5  cmp     edx, 1000h
004095CB  mov     esi, eax
004095CD  rep movsd
004095CF  mov     dword ptr [eax+4], 0
004095D6  jbe     loc_409DDE
004095DC  mov     dword_4184E4, 1
004095E6  jmp     loc_409DE4
004095EB  mov     eax, [ebp+hMutex]
004095F1  mov     [esp+40h+hWnd], eax; hMutex
004095F4  call    ReleaseMutex
004095F9  movzx   ecx, byte ptr [ebp+var_E4]
00409600  mov     eax, [ebp+var_B38]
00409606  mov     edx, offset aHelpb; "helpb"
0040960B  push    edi
0040960C  call    sub_413F90
00409611  mov     ecx, [ebp+var_B68]
00409617  mov     eax, [ebp+var_B38]
0040961D  mov     edx, offset aColori; "colori"
00409622  call    sub_413F90
00409627  mov     ecx, [ebp+var_5C]
0040962A  mov     eax, [ebp+var_B38]
00409630  mov     edx, offset aMd; "md"
00409635  call    sub_413F90
0040963A  movzx   ecx, byte ptr [ebp+var_2F0]
00409641  mov     eax, [ebp+var_B38]
00409647  mov     edx, offset aSoundb; "soundb"
0040964C  call    sub_413F90
00409651  movzx   ecx, byte ptr [ebp+var_2F0+1]
00409658  mov     eax, [ebp+var_B38]
0040965E  mov     edx, offset aMusicb; "musicb"
00409663  call    sub_413F90
00409668  mov     ecx, [ebp+var_D0]
0040966E  mov     eax, [ebp+var_B38]
00409674  mov     edx, offset aMult; "mult"
00409679  call    sub_413F90
0040967E  mov     ecx, [ebp+var_250]
00409684  mov     eax, [ebp+var_B38]
0040968A  mov     edx, offset aDelayb; "delayb"
0040968F  call    sub_413F90
00409694  movzx   ecx, byte ptr [ebp+var_60]
00409698  mov     eax, [ebp+var_B38]
0040969E  mov     edx, offset aBarb; "barb"
004096A3  call    sub_413F90
004096A8  movzx   ecx, byte ptr [ebp+Reserved]
004096AC  mov     eax, [ebp+var_B38]
004096B2  mov     edx, offset aSingleb; "singleb"
004096B7  call    sub_413F90
004096BC  call    sub_40E28A
004096C1  test    eax, eax
004096C3  jz      loc_409758
004096C9  movzx   eax, byte ptr [ebp+var_E4]
004096D0  mov     dword ptr [ebp+WideCharStr], eax
004096D6  mov     eax, [ebp+var_B68]
004096DC  mov     [ebp+var_10AC], eax
004096E2  mov     eax, [ebp+var_5C]
004096E5  mov     [ebp+var_10A8], eax
004096EB  movzx   eax, byte ptr [ebp+var_2F0]
004096F2  mov     [ebp+var_10A4], eax
004096F8  movzx   eax, byte ptr [ebp+var_2F0+1]
004096FF  mov     [ebp+var_10A0], eax
00409705  mov     eax, [ebp+var_D0]
0040970B  mov     [ebp+var_109C], eax
00409711  mov     eax, [ebp+var_250]
00409717  mov     [ebp+var_1098], eax
0040971D  movzx   eax, byte ptr [ebp+var_60]
00409721  mov     dword ptr [ebp+Source], eax
00409727  movzx   eax, byte ptr [ebp+Reserved]
0040972B  mov     [ebp+var_1090], eax
00409731  call    sub_40E28A
00409736  mov     edx, [eax]
00409738  lea     ecx, [ebp+WideCharStr]
0040973E  mov     [esp+40h+dwNewLong], 24h
00409746  mov     [esp+40h+hWnd], offset aRegDat; "reg.dat"
0040974D  mov     [esp+40h+nIndex], ecx
00409751  mov     ecx, eax
00409753  call    dword ptr [edx]
00409755  sub     esp, 0Ch
00409758  cmp     byte ptr [ebp+var_E4+1], 0
0040975F  jnz     loc_409AFC
00409765  cmp     [ebp+var_194], 0
0040976C  jnz     loc_409AFC
00409772  mov     eax, [ebp+var_B0C]
00409778  dec     eax
00409779  cmp     eax, 2
0040977C  ja      loc_409AFC
00409782  cmp     [ebp+var_238], 0
00409789  jnz     short loc_409795
0040978B  mov     [ebp+var_B08], 1
00409795  mov     ecx, [ebp+var_2C8]
0040979B  mov     eax, [ebp+var_B34]
004097A1  mov     edx, offset aMode; "mode"
004097A6  call    sub_413F90
004097AB  mov     ecx, [ebp+var_B18]
004097B1  mov     eax, [ebp+var_B34]
004097B7  mov     edx, offset aW; "w"
004097BC  call    sub_413F90
004097C1  mov     ecx, [ebp+var_B14]
004097C7  mov     eax, [ebp+var_B34]
004097CD  mov     edx, offset asc_4193DC; "h"
004097D2  call    sub_413F90
004097D7  mov     ecx, [ebp+var_B10]
004097DD  mov     eax, [ebp+var_B34]
004097E3  mov     edx, offset aN; "n"
004097E8  call    sub_413F90
004097ED  mov     ecx, [ebp+var_2B4]
004097F3  mov     eax, [ebp+var_B34]
004097F9  mov     edx, offset aMaskj0; "maskj0"
004097FE  call    sub_413F90
00409803  mov     ecx, [ebp+var_B0C]
00409809  mov     eax, [ebp+var_B34]
0040980F  mov     edx, offset aSit; "sit"
00409814  call    sub_413F90
00409819  mov     ecx, [ebp+var_2AC]
0040981F  mov     eax, [ebp+var_B34]
00409825  mov     edx, offset aLine; "line"
0040982A  call    sub_413F90
0040982F  mov     ecx, [ebp+var_2A8]
00409835  mov     eax, [ebp+var_B34]
0040983B  mov     edx, offset aLevel; "level"
00409840  call    sub_413F90
00409845  mov     ecx, [ebp+var_28C]
0040984B  mov     eax, [ebp+var_B34]
00409851  mov     edx, offset aTetrisi; "tetrisi"
00409856  call    sub_413F90
0040985B  mov     ecx, [ebp+var_288]
00409861  mov     eax, [ebp+var_B34]
00409867  mov     edx, offset aMissi; "missi"
0040986C  call    sub_413F90
00409871  mov     ecx, [ebp+var_284]
00409877  mov     eax, [ebp+var_B34]
0040987D  mov     edx, offset aMissline; "missline"
00409882  call    sub_413F90
00409887  mov     ecx, [ebp+var_27C]
0040988D  mov     eax, [ebp+var_B34]
00409893  mov     edx, offset aSum; "sum"
00409898  call    sub_413F90
0040989D  mov     ecx, [ebp+var_B04]
004098A3  mov     eax, [ebp+var_B34]
004098A9  mov     edx, offset aMaskj; "maskj"
004098AE  call    sub_413F90
004098B3  mov     ecx, [ebp+var_B00]
004098B9  mov     eax, [ebp+var_B34]
004098BF  mov     edx, offset aMaski; "maski"
004098C4  call    sub_413F90
004098C9  mov     ecx, [ebp+var_2BC]
004098CF  mov     eax, [ebp+var_B34]
004098D5  mov     edx, offset aRightb; "rightb"
004098DA  call    sub_413F90
004098DF  mov     ecx, [ebp+var_234]
004098E5  mov     eax, [ebp+var_B34]
004098EB  mov     edx, offset aTuti; "tuti"
004098F0  call    sub_413F90
004098F5  mov     ecx, [ebp+var_238]
004098FB  mov     eax, [ebp+var_B34]
00409901  mov     edx, offset aTutb; "tutb"
00409906  call    sub_413F90
0040990B  mov     ecx, [ebp+var_29C]
00409911  mov     eax, [ebp+var_B34]
00409917  mov     edx, offset aCheckr; "checkr"
0040991C  call    sub_413F90
00409921  mov     ecx, [ebp+var_B08]
00409927  mov     eax, [ebp+var_B34]
0040992D  mov     edx, offset aPauseb; "pauseb"
00409932  call    sub_413F90
00409937  mov     ecx, [ebp+var_240]
0040993D  mov     eax, [ebp+var_B34]
00409943  mov     edx, offset aMx; "mx"
00409948  call    sub_413F90
0040994D  mov     ecx, [ebp+var_23C]
00409953  mov     eax, [ebp+var_B34]
00409959  mov     edx, offset aMy; "my"
0040995E  call    sub_413F90
00409963  mov     ecx, [ebp+var_280]
00409969  mov     eax, [ebp+var_B34]
0040996F  mov     edx, offset aBouns; "bouns"
00409974  call    sub_413F90
00409979  mov     ecx, [ebp+var_248]
0040997F  mov     eax, [ebp+var_B34]
00409985  mov     edx, offset aMdb; "mdb"
0040998A  call    sub_413F90
0040998F  mov     ecx, [ebp+var_134]
00409995  mov     eax, [ebp+var_B34]
0040999B  mov     edx, offset aSolven; "solven"
004099A0  call    sub_413F90
004099A5  mov     eax, [ebp+lpData]
004099AB  mov     [esp+4Ch+dwNewLong], 4000h; cbData
004099B3  mov     [esp+4Ch+hWnd], 3; dwType
004099BB  mov     [esp+4Ch+Reserved], 0; Reserved
004099C3  mov     [esp+4Ch+lpValueName], offset ValueName; "flag"
004099CB  mov     [esp+4Ch+nIndex], eax; lpData
004099CF  mov     eax, [ebp+var_B34]
004099D5  mov     [esp+4Ch+hKey], eax; hKey
004099D8  call    RegSetValueExA
004099DD  mov     eax, [ebp+var_AF0]
004099E3  sub     esp, 18h
004099E6  mov     [esp+4Ch+dwNewLong], 4000h; cbData
004099EE  mov     [esp+4Ch+hWnd], 3; dwType
004099F6  mov     [esp+4Ch+Reserved], 0; Reserved
004099FE  mov     [esp+4Ch+lpValueName], offset aQstn; "qstn"
00409A06  mov     [esp+4Ch+nIndex], eax; lpData
00409A0A  mov     eax, [ebp+var_B34]
00409A10  mov     [esp+4Ch+hKey], eax; hKey
00409A13  call    RegSetValueExA
00409A18  mov     eax, [ebp+var_AEC]
00409A1E  sub     esp, 18h
00409A21  mov     [esp+4Ch+dwNewLong], 4000h; cbData
00409A29  mov     [esp+4Ch+hWnd], 3; dwType
00409A31  mov     [esp+4Ch+Reserved], 0; Reserved
00409A39  mov     [esp+4Ch+lpValueName], offset aMine; "mine"
00409A41  mov     [esp+4Ch+nIndex], eax; lpData
00409A45  mov     eax, [ebp+var_B34]
00409A4B  mov     [esp+4Ch+hKey], eax; hKey
00409A4E  call    RegSetValueExA
00409A53  mov     eax, [ebp+var_AE8]
00409A59  sub     esp, 18h
00409A5C  mov     [esp+4Ch+dwNewLong], 4000h; cbData
00409A64  mov     [esp+4Ch+hWnd], 3; dwType
00409A6C  mov     [esp+4Ch+Reserved], 0; Reserved
00409A74  mov     [esp+4Ch+lpValueName], offset aBlck; "blck"
00409A7C  mov     [esp+4Ch+nIndex], eax; lpData
00409A80  mov     eax, [ebp+var_B34]
00409A86  mov     [esp+4Ch+hKey], eax; hKey
00409A89  call    RegSetValueExA
00409A8E  mov     eax, [ebp+var_AE4]
00409A94  sub     esp, 18h
00409A97  mov     [esp+4Ch+dwNewLong], 4000h; cbData
00409A9F  mov     [esp+4Ch+hWnd], 3; dwType
00409AA7  mov     [esp+4Ch+Reserved], 0; Reserved
00409AAF  mov     [esp+4Ch+lpValueName], offset aMask; "mask"
00409AB7  mov     [esp+4Ch+nIndex], eax; lpData
00409ABB  mov     eax, [ebp+var_B34]
00409AC1  mov     [esp+4Ch+hKey], eax; hKey
00409AC4  call    RegSetValueExA
00409AC9  sub     esp, 18h
00409ACC  call    sub_40E28A
00409AD1  test    eax, eax
00409AD3  jz      short loc_409AE0
00409AD5  lea     ecx, [ebp+FileName]
00409ADB  call    sub_412EC8
00409AE0  mov     eax, [ebp+var_B38]
00409AE6  mov     ecx, 1
00409AEB  mov     edx, offset aBoardb; "boardb"
00409AF0  mov     [ebp+hWnd], 1
00409AF7  call    sub_413F90
00409AFC  lea     eax, [ebp+CriticalSection]
00409AFF  mov     [esp+4Ch+hKey], eax; lpCriticalSection
00409B02  call    DeleteCriticalSection
00409B07  cmp     [ebp+var_974], 0
00409B0E  push    esi
00409B0F  jz      short loc_409B23
00409B11  call    sub_40E2A1
00409B16  mov     edx, [eax]
00409B18  mov     ecx, eax
00409B1A  call    dword ptr [edx+28h]
00409B1D  call    ds:SteamAPI_Shutdown
00409B23  mov     eax, [ebp+var_B38]
00409B29  mov     [esp+4Ch+hKey], eax; hKey
00409B2C  call    RegCloseKey
00409B31  mov     eax, [ebp+var_B34]
00409B37  push    ecx
00409B38  mov     [esp+4Ch+hKey], eax; hKey
00409B3B  call    RegCloseKey
00409B40  push    ebx
00409B41  jmp     loc_40AAC7
00409B46  mov     ecx, ebx
00409B48  call    sub_40EE22
00409B4D  mov     eax, [ebp+var_D20]
00409B53  mov     edx, [ebp+var_D1C]
00409B59  mov     [esp+0Ch+lpSecurityAttributes], 40h; uType
00409B61  mov     edx, [eax+edx*4]
00409B64  mov     [esp+0Ch+lpName], edx; lpCaption
00409B68  mov     edx, [ebp+var_D18]
00409B6E  mov     eax, [eax+edx*4]
00409B71  mov     [esp+0Ch+lpMutexAttributes], 0; hWnd
00409B78  mov     [esp+0Ch+bInitialOwner], eax; lpText
00409B7C  call    MessageBoxW
00409B81  sub     esp, 10h
00409B84  jmp     loc_40AAC7
00409B89  mov     eax, ds:dword_4561B4
00409B8E  cmp     ds:dword_456180, eax
00409B94  jz      short loc_409BCD
00409B96  inc     eax
00409B97  mov     edi, offset unk_456184
00409B9C  mov     ecx, 7
00409BA1  and     eax, 0FFFh
00409BA6  mov     ds:dword_4561B4, eax
00409BAB  imul    eax, 1Ch
00409BAE  add     eax, offset unk_43A180
00409BB3  mov     esi, eax
00409BB5  rep movsd
00409BB7  cmp     ds:dword_456188, 0
00409BBE  jnz     loc_409DE4
00409BC4  mov     ecx, 7
00409BC9  mov     edi, ebx
00409BCB  jmp     short loc_409BB3
00409BCD  mov     eax, [ebp+var_B0C]
00409BD3  mov     [ebp+var_24C], 0
00409BDD  dec     eax
00409BDE  cmp     eax, 2
00409BE1  ja      loc_409D03
00409BE7  cmp     [ebp+var_B08], 0
00409BEE  jnz     loc_409D03
00409BF4  cmp     [ebp+var_238], 0
00409BFB  jnz     loc_409D14
00409C01  call    sub_412E2B
00409C06  fld     ds:flt_41977C
00409C0C  fld     st
00409C0E  fiadd   [ebp+var_2A8]
00409C14  fdivp   st(1), st
00409C16  fadd    [ebp+var_2E0]
00409C1C  fxch    st(1)
00409C1E  fucompp
00409C20  fnstsw  ax
00409C22  sahf
00409C23  jbe     loc_409D14
00409C29  call    sub_412E2B
00409C2E  fld     ds:dbl_419798
00409C34  fiadd   [ebp+var_2A8]
00409C3A  fdivr   ds:dbl_419798
00409C40  fadd    [ebp+var_2E0]
00409C46  fxch    st(1)
00409C48  fucomp  st(1)
00409C4A  fnstsw  ax
00409C4C  sahf
00409C4D  jbe     short loc_409C9C
00409C4F  mov     eax, [ebp+var_B00]
00409C55  fstp    [ebp+var_2E0]
00409C5B  inc     eax
00409C5C  cmp     eax, [ebp+var_B18]
00409C62  mov     [ebp+var_B00], eax
00409C68  jnz     short loc_409C29
00409C6A  lea     ecx, [ebp+var_B18]
00409C70  mov     [esp+40h+hWnd], 1
00409C77  mov     [ebp+var_B00], 0
00409C81  call    sub_40C342
00409C86  push    eax
00409C87  lea     ecx, [ebp+var_B18]
00409C8D  mov     [esp+40h+hWnd], 1
00409C94  call    sub_40CA82
00409C99  push    eax
00409C9A  jmp     short loc_409C29
00409C9C  fstp    st
00409C9E  lea     ecx, [ebp+var_B18]
00409CA4  call    sub_40BAC0
00409CA9  lea     ecx, [ebp+FileName]
00409CAF  call    sub_413B76
00409CB4  call    sub_412E2B
00409CB9  fld     ds:dbl_419788
00409CBF  fadd    qword ptr [ebp+dwNewLong]
00409CC2  fxch    st(1)
00409CC4  fucompp
00409CC6  fnstsw  ax
00409CC8  sahf
00409CC9  jbe     short loc_409D14
00409CCB  mov     eax, ds:hWnd
00409CD0  mov     [esp+40h+dwNewLong], 0; bErase
00409CD8  mov     [esp+40h+nIndex], 0; lpRect
00409CE0  mov     [esp+40h+hWnd], eax; hWnd
00409CE3  call    InvalidateRect
00409CE8  mov     eax, ds:hWnd
00409CED  sub     esp, 0Ch
00409CF0  mov     [esp+40h+hWnd], eax; hWnd
00409CF3  call    UpdateWindow
00409CF8  push    eax
00409CF9  call    sub_412E2B
00409CFE  fstp    qword ptr [ebp+dwNewLong]
00409D01  jmp     short loc_409D14
00409D03  call    sub_412E2B
00409D08  fsub    [ebp+var_2D0]
00409D0E  fstp    [ebp+var_2E0]
00409D14  cmp     byte ptr [ebp+var_2F0+1], 0
00409D1B  jz      loc_409DCC
00409D21  mov     eax, [ebp+var_2EC]
00409D27  test    eax, eax
00409D29  js      loc_409DCC
00409D2F  cmp     eax, [ebp+var_2F4]
00409D35  jge     loc_409DCC
00409D3B  call    sub_412E2B
00409D40  fld     [ebp+var_2E8]
00409D46  fxch    st(1)
00409D48  fucompp
00409D4A  fnstsw  ax
00409D4C  sahf
00409D4D  jbe     short loc_409DCC
00409D4F  mov     edx, [ebp+var_2EC]
00409D55  mov     eax, [ebp+Memory]
00409D5B  mov     eax, [eax+edx*4]
00409D5E  mov     [esp+40h+nIndex], offset aStatusSLuPosit; "status s%lu position"
00409D66  mov     [esp+40h+hWnd], offset Dest; Dest
00409D6D  mov     [esp+40h+dwNewLong], eax
00409D71  call    sprintf
00409D76  call    sub_40F074
00409D7B  mov     edx, [ebp+var_2EC]
00409D81  mov     ebx, eax
00409D83  mov     eax, [ebp+Memory]
00409D89  mov     eax, [eax+edx*4]
00409D8C  mov     [esp+40h+nIndex], offset aStatusSLuLengt; "status s%lu length"
00409D94  mov     [esp+40h+hWnd], offset Dest; Dest
00409D9B  mov     [esp+40h+dwNewLong], eax
00409D9F  call    sprintf
00409DA4  call    sub_40F074
00409DA9  cmp     eax, ebx
00409DAB  jbe     short loc_409DC1
00409DAD  fld     ds:flt_419790
00409DB3  fadd    [ebp+var_2E8]
00409DB9  fstp    [ebp+var_2E8]
00409DBF  jmp     short loc_409DCC
00409DC1  lea     ecx, [ebp+var_358]
00409DC7  call    sub_40E998
00409DCC  mov     [esp+40h+hWnd], 1; dwMilliseconds
00409DD3  call    Sleep
00409DD8  push    eax
00409DD9  jmp     loc_409594
00409DDE  mov     dword_4184E4, edx
00409DE4  cmp     [ebp+var_24C], 0
00409DEB  jnz     loc_4095A2
00409DF1  mov     [esp+40h+hWnd], 1; vKey
00409DF8  call    GetAsyncKeyState
00409DFD  push    edx
00409DFE  test    ax, ax
00409E01  setnz   [ebp+var_58]
00409E05  mov     [esp+40h+hWnd], 2; vKey
00409E0C  call    GetAsyncKeyState
00409E11  push    ecx
00409E12  test    ax, ax
00409E15  mov     eax, 201h
00409E1A  setnz   [ebp+var_57]
00409E1E  call    sub_41246A
00409E23  test    al, al
00409E25  jz      short loc_409E62
00409E27  mov     byte ptr [ebp+hKey], 1
00409E2B  mov     [ebp+var_54], 0FFFFFFFFh
00409E32  mov     [ebp+var_50], 0FFFFFFFFh
00409E39  call    sub_40F128
00409E3E  mov     ebx, eax
00409E40  call    sub_412DE0
00409E45  lea     ecx, [ebp+FileName]; lpParameter
00409E4B  mov     [esp+40h+dwNewLong], 1; int
00409E53  mov     [esp+40h+nIndex], ebx; int
00409E57  mov     [esp+40h+hWnd], eax; int
00409E5A  call    sub_4107AC
00409E5F  sub     esp, 0Ch
00409E62  mov     eax, 204h
00409E67  call    sub_41246A
00409E6C  test    al, al
00409E6E  jz      short loc_409EAB
00409E70  mov     byte ptr [ebp+hKey], 1
00409E74  mov     [ebp+var_54], 0FFFFFFFFh
00409E7B  mov     [ebp+var_50], 0FFFFFFFFh
00409E82  call    sub_40F128
00409E87  mov     ebx, eax
00409E89  call    sub_412DE0
00409E8E  lea     ecx, [ebp+FileName]; lpParameter
00409E94  mov     [esp+40h+dwNewLong], 2; int
00409E9C  mov     [esp+40h+nIndex], ebx; int
00409EA0  mov     [esp+40h+hWnd], eax; int
00409EA3  call    sub_4107AC
00409EA8  sub     esp, 0Ch
00409EAB  mov     eax, 200h
00409EB0  call    sub_41246A
00409EB5  test    al, al
00409EB7  jz      loc_409F3D
00409EBD  mov     ebx, [ebp+var_5C]
00409EC0  cmp     ebx, 1
00409EC3  jle     short loc_409F3D
00409EC5  cmp     [ebp+var_238], 0
00409ECC  jnz     short loc_409F3D
00409ECE  cmp     byte ptr [ebp+hKey], 0
00409ED2  jz      short loc_409F3D
00409ED4  cmp     [ebp+var_58], 0
00409ED8  jz      short loc_409F07
00409EDA  call    sub_40F128
00409EDF  mov     esi, eax
00409EE1  call    sub_412DE0
00409EE6  lea     ecx, [ebp+FileName]; lpParameter
00409EEC  mov     [esp+40h+dwNewLong+4], ebx; int
00409EF0  mov     [esp+40h+dwNewLong], 1; int
00409EF8  mov     [esp+40h+nIndex], esi; int
00409EFC  mov     [esp+40h+hWnd], eax; int
00409EFF  call    sub_4106BE
00409F04  sub     esp, 10h
00409F07  cmp     [ebp+var_57], 0
00409F0B  jz      short loc_409F3D
00409F0D  mov     esi, [ebp+var_5C]
00409F10  call    sub_40F128
00409F15  mov     ebx, eax
00409F17  call    sub_412DE0
00409F1C  lea     ecx, [ebp+FileName]; lpParameter
00409F22  mov     [esp+40h+dwNewLong+4], esi; int
00409F26  mov     [esp+40h+dwNewLong], 2; int
00409F2E  mov     [esp+40h+nIndex], ebx; int
00409F32  mov     [esp+40h+hWnd], eax; int
00409F35  call    sub_4106BE
00409F3A  sub     esp, 10h
00409F3D  mov     eax, 100h
00409F42  call    sub_41246A
00409F47  test    al, al
00409F49  jnz     short loc_409FB2
00409F4B  jmp     short loc_409F77
00409F4D  cmp     ebx, 21h
00409F50  jz      loc_40A21A
00409F56  cmp     ebx, 22h
00409F59  jz      loc_40A23C
00409F5F  cmp     byte ptr [ebp+var_E4+1], 0
00409F66  jnz     loc_40A392
00409F6C  lea     ecx, [ebp+FileName]
00409F72  call    sub_413B76
00409F77  mov     eax, 0Fh
00409F7C  call    sub_41246A
00409F81  test    al, al
00409F83  jnz     loc_40A9A6
00409F89  mov     eax, 0A1h
00409F8E  call    sub_41246A
00409F93  test    al, al
00409F95  jnz     loc_40A9A6
00409F9B  mov     eax, 112h
00409FA0  call    sub_41246A
00409FA5  test    al, al
00409FA7  jnz     loc_40A9A6
00409FAD  jmp     loc_40959D
00409FB2  xor     ebx, ebx
00409FB4  cmp     ds:dword_456188, 100h
00409FBE  jz      loc_40A75A
00409FC4  cmp     ebx, 43h
00409FC7  jnz     short loc_409FE0
00409FC9  cmp     byte ptr [ebp+var_E4+1], 0
00409FD0  jz      short loc_409FE0
00409FD2  cmp     [ebp+var_974], 0
00409FD9  jz      short loc_409FE0
00409FDB  call    sub_40E2B8
00409FE0  cmp     [ebp+var_E8], 0FFFFFFFEh
00409FE7  jnz     short loc_40A012
00409FE9  cmp     ebx, 9
00409FEC  jnz     short loc_40A012
00409FEE  mov     eax, [ebp+lpValueName]
00409FF1  mov     ecx, 5
00409FF6  inc     eax
00409FF7  cdq
00409FF8  idiv    ecx
00409FFA  mov     eax, [ebp+var_308]
0040A000  lea     ecx, [ebp+var_358]
0040A006  mov     [esp+40h+hWnd], eax
0040A009  mov     [ebp+lpValueName], edx
0040A00C  call    sub_40EA0C
0040A011  push    edi
0040A012  cmp     [ebp+var_E8], 0
0040A019  jnz     loc_40A69D
0040A01F  cmp     [ebp+var_240], 0FFFFFFFFh
0040A026  jnz     short loc_40A074
0040A028  cmp     [ebp+var_23C], 0FFFFFFFFh
0040A02F  jnz     short loc_40A074
0040A031  cmp     ebx, 41h
0040A034  jz      short loc_40A051
0040A036  cmp     ebx, 44h
0040A039  jz      short loc_40A051
0040A03B  mov     eax, ebx
0040A03D  and     eax, 0FFFFFFFBh
0040A040  cmp     eax, 53h
0040A043  jz      short loc_40A051
0040A045  mov     eax, ebx
0040A047  and     eax, 0FFFFFFFDh
0040A04A  cmp     eax, 0BCh
0040A04F  jnz     short loc_40A074
0040A051  mov     eax, [ebp+var_B18]
0040A057  mov     ecx, 2
0040A05C  cdq
0040A05D  idiv    ecx
0040A05F  mov     [ebp+var_240], eax
0040A065  mov     eax, [ebp+var_B14]
0040A06B  sub     eax, 3
0040A06E  mov     [ebp+var_23C], eax
0040A074  cmp     ebx, 44h
0040A077  jz      loc_40A272
0040A07D  jg      short loc_40A0C4
0040A07F  cmp     ebx, 25h
0040A082  jz      loc_40A1D4
0040A088  jg      short loc_40A09E
0040A08A  cmp     ebx, 20h
0040A08D  jz      loc_40A18E
0040A093  jg      loc_409F4D
0040A099  cmp     ebx, 1Bh
0040A09C  jmp     short loc_40A0DD
0040A09E  cmp     ebx, 27h
0040A0A1  jz      loc_40A1F2
0040A0A7  jl      loc_40A1FA
0040A0AD  cmp     ebx, 28h
0040A0B0  jz      loc_40A202
0040A0B6  cmp     ebx, 41h
0040A0B9  jz      loc_40A25E
0040A0BF  jmp     loc_409F5F
0040A0C4  cmp     ebx, 6Bh
0040A0C7  jz      loc_40A212
0040A0CD  jg      short loc_40A104
0040A0CF  cmp     ebx, 53h
0040A0D2  jz      loc_40A2A5
0040A0D8  jg      short loc_40A0ED
0040A0DA  cmp     ebx, 51h
0040A0DD  jnz     loc_409F5F
0040A0E3  call    sub_412E98
0040A0E8  jmp     loc_409F5F
0040A0ED  cmp     ebx, 55h
0040A0F0  jz      loc_40A32F
0040A0F6  cmp     ebx, 57h
0040A0F9  jz      loc_40A291
0040A0FF  jmp     loc_409F5F
0040A104  cmp     ebx, 0BCh
0040A10A  jz      loc_40A2C4
0040A110  jg      short loc_40A12C
0040A112  cmp     ebx, 6Dh
0040A115  jz      loc_40A20A
0040A11B  cmp     ebx, 0BBh
0040A121  jz      loc_40A212
0040A127  jmp     loc_409F5F
0040A12C  cmp     ebx, 0BDh
0040A132  jz      loc_40A20A
0040A138  cmp     ebx, 0BEh
0040A13E  jnz     loc_409F5F
0040A144  lea     ecx, [ebp+FileName]; lpParameter
0040A14A  mov     [esp+40h+dwNewLong], 1; int
0040A152  mov     [esp+40h+nIndex], 0; int
0040A15A  mov     [esp+40h+hWnd], 0; int
0040A161  mov     [ebp+var_54], 0FFFFFFFFh
0040A168  mov     [ebp+var_50], 0FFFFFFFFh
0040A16F  call    sub_4139D4
0040A174  mov     eax, [ebp+var_5C]
0040A177  sub     esp, 0Ch
0040A17A  mov     [esp+40h+dwNewLong], 2
0040A182  add     eax, 4
0040A185  mov     [esp+40h+dwNewLong+4], eax
0040A189  jmp     loc_40A309
0040A18E  mov     eax, [ebp+var_B0C]
0040A194  dec     eax
0040A195  cmp     eax, 2
0040A198  ja      loc_409F5F
0040A19E  lea     ecx, [ebp+var_B18]
0040A1A4  call    sub_4121C4
0040A1A9  mov     eax, [ebp+var_2F8]
0040A1AF  lea     ecx, [ebp+var_358]
0040A1B5  mov     [esp+40h+hWnd], eax
0040A1B8  call    sub_40EA0C
0040A1BD  mov     eax, [ebp+var_964]
0040A1C3  push    esi
0040A1C4  lea     ecx, [ebp+var_AD0]
0040A1CA  mov     [esp+40h+hWnd], eax
0040A1CD  call    sub_40E31E
0040A1D2  jmp     short loc_40A1EC
0040A1D4  dec     [ebp+var_B18]
0040A1DA  lea     ecx, [ebp+FileName]
0040A1E0  mov     [esp+40h+hWnd], 1
0040A1E7  call    sub_40FEF6
0040A1EC  push    ecx
0040A1ED  jmp     loc_409F5F
0040A1F2  inc     [ebp+var_B18]
0040A1F8  jmp     short loc_40A1DA
0040A1FA  dec     [ebp+var_B14]
0040A200  jmp     short loc_40A1DA
0040A202  inc     [ebp+var_B14]
0040A208  jmp     short loc_40A1DA
0040A20A  dec     [ebp+var_B10]
0040A210  jmp     short loc_40A1DA
0040A212  inc     [ebp+var_B10]
0040A218  jmp     short loc_40A1DA
0040A21A  mov     edx, [ebp+var_B14]
0040A220  mov     eax, [ebp+var_2B4]
0040A226  lea     ecx, [edx-3]
0040A229  cmp     ecx, eax
0040A22B  jg      short loc_40A230
0040A22D  lea     eax, [edx-4]
0040A230  dec     eax
0040A231  test    eax, eax
0040A233  jg      short loc_40A253
0040A235  mov     eax, 1
0040A23A  jmp     short loc_40A253
0040A23C  mov     edx, [ebp+var_B14]
0040A242  mov     eax, [ebp+var_2B4]
0040A248  lea     ecx, [edx-3]
0040A24B  inc     eax
0040A24C  cmp     eax, ecx
0040A24E  jl      short loc_40A253
0040A250  lea     eax, [edx-4]
0040A253  mov     [ebp+var_2B4], eax
0040A259  jmp     loc_40A1DA
0040A25E  dec     [ebp+var_240]
0040A264  mov     eax, [ebp+var_240]
0040A26A  test    eax, eax
0040A26C  jns     short loc_40A286
0040A26E  xor     eax, eax
0040A270  jmp     short loc_40A286
0040A272  mov     eax, [ebp+var_240]
0040A278  mov     edx, [ebp+var_B18]
0040A27E  inc     eax
0040A27F  cmp     eax, edx
0040A281  jl      short loc_40A286
0040A283  lea     eax, [edx-1]
0040A286  mov     [ebp+var_240], eax
0040A28C  jmp     loc_409F5F
0040A291  dec     [ebp+var_23C]
0040A297  mov     eax, [ebp+var_23C]
0040A29D  test    eax, eax
0040A29F  jns     short loc_40A2B9
0040A2A1  xor     eax, eax
0040A2A3  jmp     short loc_40A2B9
0040A2A5  mov     eax, [ebp+var_23C]
0040A2AB  mov     edx, [ebp+var_B14]
0040A2B1  inc     eax
0040A2B2  cmp     eax, edx
0040A2B4  jl      short loc_40A2B9
0040A2B6  lea     eax, [edx-1]
0040A2B9  mov     [ebp+var_23C], eax
0040A2BF  jmp     loc_409F5F
0040A2C4  lea     ecx, [ebp+FileName]; lpParameter
0040A2CA  mov     [esp+40h+dwNewLong], 1; int
0040A2D2  mov     [esp+40h+nIndex], 0; int
0040A2DA  mov     [esp+40h+hWnd], 0; int
0040A2E1  mov     [ebp+var_54], 0FFFFFFFFh
0040A2E8  mov     [ebp+var_50], 0FFFFFFFFh
0040A2EF  call    sub_4139D4
0040A2F4  mov     eax, [ebp+var_5C]
0040A2F7  sub     esp, 0Ch
0040A2FA  mov     [esp+40h+dwNewLong], 1
0040A302  add     eax, 4
0040A305  mov     [esp+40h+dwNewLong+4], eax
0040A309  mov     eax, [ebp+var_23C]
0040A30F  lea     ecx, [ebp+FileName]
0040A315  mov     [esp+40h+nIndex], eax
0040A319  mov     eax, [ebp+var_240]
0040A31F  mov     [esp+40h+hWnd], eax
0040A322  call    sub_410270
0040A327  sub     esp, 10h
0040A32A  jmp     loc_409F5F
0040A32F  cmp     [ebp+var_238], 0
0040A336  jnz     loc_409F5F
0040A33C  lea     ecx, [ebp+var_B18]
0040A342  mov     [esp+40h+hWnd], 1
0040A349  call    sub_40C342
0040A34E  push    eax
0040A34F  mov     eax, [ebp+var_308]
0040A355  lea     ecx, [ebp+var_358]
0040A35B  mov     [esp+40h+hWnd], eax
0040A35E  call    sub_40EA0C
0040A363  lea     ecx, [ebp+FileName]
0040A369  push    eax
0040A36A  call    sub_413B76
0040A36F  lea     ecx, [ebp+var_B18]
0040A375  mov     [esp+40h+hWnd], 1
0040A37C  call    sub_40CA82
0040A381  lea     ecx, [ebp+var_B18]
0040A387  push    edx
0040A388  call    sub_40BAC0
0040A38D  jmp     loc_409F5F
0040A392  cmp     ebx, 36h
0040A395  jz      short loc_40A3FD
0040A397  jg      short loc_40A3AE
0040A399  cmp     ebx, 34h
0040A39C  jz      short loc_40A3D6
0040A39E  jg      short loc_40A3E6
0040A3A0  cmp     ebx, 30h
0040A3A3  jz      loc_40A644
0040A3A9  jmp     loc_40A66F
0040A3AE  cmp     ebx, 38h
0040A3B1  jz      loc_40A46D
0040A3B7  jl      short loc_40A431
0040A3B9  cmp     ebx, 39h
0040A3BC  jz      loc_40A4DD
0040A3C2  cmp     ebx, 56h
0040A3C5  jnz     loc_40A66F
0040A3CB  inc     [ebp+var_2A8]
0040A3D1  jmp     loc_40A66F
0040A3D6  lea     ecx, [ebp+var_B18]
0040A3DC  call    sub_40C132
0040A3E1  jmp     loc_40A66F
0040A3E6  lea     ecx, [ebp+var_B18]
0040A3EC  mov     [esp+40h+hWnd], 1
0040A3F3  call    sub_40C498
0040A3F8  jmp     loc_40A66E
0040A3FD  mov     [ebp+var_2A2], 1
0040A404  cmp     [ebp+var_2A2], 0
0040A40B  jz      loc_40A66F
0040A411  lea     ecx, [ebp+var_B18]
0040A417  mov     [esp+40h+hWnd], 0
0040A41E  call    sub_40CA82
0040A423  lea     ecx, [ebp+var_B18]
0040A429  push    eax
0040A42A  call    sub_40C132
0040A42F  jmp     short loc_40A404
0040A431  mov     [ebp+var_2A1], 1
0040A438  cmp     [ebp+var_2A1], 0
0040A43F  jz      loc_40A66F
0040A445  lea     ecx, [ebp+var_B18]
0040A44B  mov     [esp+40h+hWnd], 0
0040A452  call    sub_40CA82
0040A457  push    eax
0040A458  lea     ecx, [ebp+var_B18]
0040A45E  mov     [esp+40h+hWnd], 1
0040A465  call    sub_40C498
0040A46A  push    eax
0040A46B  jmp     short loc_40A438
0040A46D  mov     [ebp+var_2A0], 1
0040A474  cmp     [ebp+var_2A0], 0
0040A47B  jz      loc_40A66F
0040A481  lea     ecx, [ebp+var_B18]
0040A487  mov     [esp+40h+hWnd], 0
0040A48E  call    sub_40CA82
0040A493  lea     ecx, [ebp+var_B18]
0040A499  push    esi
0040A49A  call    sub_40C132
0040A49F  lea     ecx, [ebp+var_B18]
0040A4A5  mov     [esp+40h+hWnd], 0
0040A4AC  call    sub_40CA82
0040A4B1  push    edi
0040A4B2  lea     ecx, [ebp+var_B18]
0040A4B8  mov     [esp+40h+hWnd], 1
0040A4BF  call    sub_40C498
0040A4C4  push    eax
0040A4C5  mov     al, [ebp+var_2A2]
0040A4CB  test    al, al
0040A4CD  jnz     short loc_40A4D5
0040A4CF  mov     al, [ebp+var_2A1]
0040A4D5  mov     [ebp+var_2A0], al
0040A4DB  jmp     short loc_40A474
0040A4DD  mov     [ebp+var_2A4], 1
0040A4E4  cmp     [ebp+var_2A4], 0
0040A4EB  jz      loc_40A66F
0040A4F1  mov     eax, [ebp+var_B0C]
0040A4F7  mov     [ebp+var_2A4], 0
0040A4FE  dec     eax
0040A4FF  cmp     eax, 2
0040A502  ja      short loc_40A4E4
0040A504  mov     edi, [ebp+var_B08]
0040A50A  test    edi, edi
0040A50C  jnz     short loc_40A4E4
0040A50E  mov     esi, [ebp+var_B18]
0040A514  cmp     esi, edi
0040A516  jle     loc_40A5A8
0040A51C  mov     eax, edi
0040A51E  mov     edx, edi
0040A520  mov     esi, 2
0040A525  shl     eax, 9
0040A528  shl     edx, 7
0040A52B  mov     dword ptr [ebp+var_11D8], eax
0040A531  cmp     [ebp+var_B14], esi
0040A537  jle     short loc_40A5A2
0040A539  mov     ecx, [ebp+var_AE4]
0040A53F  add     ecx, esi
0040A541  cmp     byte ptr [ecx+edx], 0
0040A545  jnz     short loc_40A59F
0040A547  mov     ecx, [ebp+var_AEC]
0040A54D  add     ecx, esi
0040A54F  cmp     byte ptr [ecx+edx], 0
0040A553  jnz     short loc_40A59F
0040A555  lea     ecx, ds:0[esi*4]
0040A55C  add     ecx, [ebp+var_AE0]
0040A562  mov     eax, dword ptr [ebp+var_11D8]
0040A568  cmp     dword ptr [ecx+eax], 0
0040A56C  jnz     short loc_40A59F
0040A56E  lea     ecx, [ebp+var_B18]
0040A574  mov     [esp+40h+dwNewLong+4], 3
0040A57C  mov     [esp+40h+dwNewLong], 0
0040A584  mov     [esp+40h+nIndex], esi
0040A588  mov     [esp+40h+hWnd], edi
0040A58B  mov     dword ptr [ebp+var_11E8], edx
0040A591  call    sub_4122D0
0040A596  mov     edx, dword ptr [ebp+var_11E8]
0040A59C  sub     esp, 10h
0040A59F  inc     esi
0040A5A0  jmp     short loc_40A531
0040A5A2  inc     edi
0040A5A3  jmp     loc_40A50E
0040A5A8  dec     esi
0040A5A9  mov     eax, esi
0040A5AB  mov     edx, esi
0040A5AD  shl     eax, 7
0040A5B0  shl     edx, 9
0040A5B3  test    esi, esi
0040A5B5  js      loc_40A4E4
0040A5BB  mov     edi, [ebp+var_B14]
0040A5C1  dec     edi
0040A5C2  cmp     edi, 1
0040A5C5  jle     short loc_40A635
0040A5C7  mov     ecx, [ebp+var_AE4]
0040A5CD  add     ecx, edi
0040A5CF  cmp     byte ptr [ecx+eax], 0
0040A5D3  jnz     short loc_40A5C1
0040A5D5  mov     ecx, [ebp+var_AEC]
0040A5DB  add     ecx, edi
0040A5DD  cmp     byte ptr [ecx+eax], 0
0040A5E1  jnz     short loc_40A5C1
0040A5E3  lea     ecx, ds:0[edi*4]
0040A5EA  add     ecx, [ebp+var_AE0]
0040A5F0  cmp     dword ptr [ecx+edx], 0
0040A5F4  jnz     short loc_40A5C1
0040A5F6  lea     ecx, [ebp+var_B18]
0040A5FC  mov     [esp+40h+dwNewLong+4], 3
0040A604  mov     [esp+40h+dwNewLong], 0
0040A60C  mov     [esp+40h+nIndex], edi
0040A610  mov     [esp+40h+hWnd], esi
0040A613  mov     dword ptr [ebp+var_11E8], eax
0040A619  mov     dword ptr [ebp+var_11D8], edx
0040A61F  call    sub_4122D0
0040A624  mov     eax, dword ptr [ebp+var_11E8]
0040A62A  sub     esp, 10h
0040A62D  mov     edx, dword ptr [ebp+var_11D8]
0040A633  jmp     short loc_40A5C1
0040A635  dec     esi
0040A636  add     eax, 0FFFFFF80h
0040A639  sub     edx, 200h
0040A63F  jmp     loc_40A5B3
0040A644  mov     eax, [ebp+var_B0C]
0040A64A  dec     eax
0040A64B  cmp     eax, 2
0040A64E  ja      short loc_40A66F
0040A650  cmp     [ebp+var_B08], 0
0040A657  jnz     short loc_40A66F
0040A659  mov     eax, [ebp+var_B14]
0040A65F  lea     ecx, [ebp+var_B18]
0040A665  dec     eax
0040A666  mov     [esp+40h+hWnd], eax
0040A669  call    sub_411B10
0040A66E  push    ecx
0040A66F  sub     ebx, 31h
0040A672  cmp     ebx, 2
0040A675  jbe     loc_409F6C
0040A67B  lea     ecx, [ebp+FileName]
0040A681  call    sub_413B76
0040A686  lea     ecx, [ebp+var_B18]
0040A68C  mov     [esp+40h+hWnd], 1
0040A693  call    sub_40CA82
0040A698  jmp     loc_40A754
0040A69D  cmp     ebx, 0Dh
0040A6A0  jz      short loc_40A6B1
0040A6A2  cmp     ebx, 20h
0040A6A5  jz      short loc_40A6B1
0040A6A7  cmp     ebx, 1Bh
0040A6AA  jz      short loc_40A6B1
0040A6AC  cmp     ebx, 51h
0040A6AF  jnz     short loc_40A6C4
0040A6B1  lea     ecx, [ebp+FileName]; lpParameter
0040A6B7  mov     [esp+40h+hWnd], 0; int
0040A6BE  call    sub_4138C4
0040A6C3  push    edx
0040A6C4  mov     eax, [ebp+var_E8]
0040A6CA  test    eax, eax
0040A6CC  jle     loc_409F6C
0040A6D2  cmp     ebx, 25h
0040A6D5  jnz     short loc_40A6FD
0040A6D7  cmp     eax, 1
0040A6DA  jz      loc_409F6C
0040A6E0  dec     eax
0040A6E1  lea     ecx, [ebp+var_358]
0040A6E7  mov     [ebp+var_E8], eax
0040A6ED  mov     eax, [ebp+var_308]
0040A6F3  mov     [esp+40h+hWnd], eax
0040A6F6  call    sub_40EA0C
0040A6FB  jmp     short loc_40A754
0040A6FD  cmp     ebx, 27h
0040A700  jnz     loc_409F6C
0040A706  cmp     eax, [ebp+var_EC]
0040A70C  jge     loc_409F6C
0040A712  inc     eax
0040A713  lea     ecx, [ebp+var_358]
0040A719  mov     [ebp+var_E8], eax
0040A71F  mov     eax, [ebp+var_308]
0040A725  mov     [esp+40h+hWnd], eax
0040A728  call    sub_40EA0C
0040A72D  push    eax
0040A72E  mov     eax, [ebp+var_EC]
0040A734  cmp     [ebp+var_E8], eax
0040A73A  jnz     loc_409F6C
0040A740  mov     eax, [ebp+var_960]
0040A746  lea     ecx, [ebp+var_AD0]
0040A74C  mov     [esp+40h+hWnd], eax
0040A74F  call    sub_40E31E
0040A754  push    eax
0040A755  jmp     loc_409F6C
0040A75A  mov     eax, ds:dword_456190
0040A75F  mov     ebx, ds:dword_45618C
0040A765  cdq
0040A766  or      ebx, edx
0040A768  cmp     ebx, 52h
0040A76B  jz      loc_40A8C7
0040A771  jg      short loc_40A7E3
0040A773  cmp     ebx, 47h
0040A776  jz      loc_40A8B7
0040A77C  jg      short loc_40A7AE
0040A77E  cmp     ebx, 33h
0040A781  jz      loc_40A95C
0040A787  jg      short loc_40A7A0
0040A789  cmp     ebx, 31h
0040A78C  jz      loc_40A916
0040A792  cmp     ebx, 32h
0040A795  jz      loc_40A939
0040A79B  jmp     loc_409FC4
0040A7A0  cmp     ebx, 42h
0040A7A3  jz      loc_40A877
0040A7A9  cmp     ebx, 45h
0040A7AC  jmp     short loc_40A810
0040A7AE  cmp     ebx, 4Dh
0040A7B1  jz      loc_40A8A7
0040A7B7  jg      short loc_40A7D0
0040A7B9  cmp     ebx, 48h
0040A7BC  jz      loc_40A86E
0040A7C2  cmp     ebx, 4Bh
0040A7C5  jz      loc_40A85E
0040A7CB  jmp     loc_409FC4
0040A7D0  cmp     ebx, 4Eh
0040A7D3  jz      loc_40A8D3
0040A7D9  cmp     ebx, 50h
0040A7DC  jz      short loc_40A84E
0040A7DE  jmp     loc_409FC4
0040A7E3  cmp     ebx, 73h
0040A7E6  jz      loc_40A880
0040A7EC  jg      short loc_40A81F
0040A7EE  cmp     ebx, 70h
0040A7F1  jz      short loc_40A86E
0040A7F3  jg      short loc_40A808
0040A7F5  cmp     ebx, 53h
0040A7F8  jz      loc_40A897
0040A7FE  cmp     ebx, 54h
0040A801  jz      short loc_40A880
0040A803  jmp     loc_409FC4
0040A808  cmp     ebx, 71h
0040A80B  jz      short loc_40A877
0040A80D  cmp     ebx, 72h
0040A810  jnz     loc_409FC4
0040A816  mov     [esp+40h+hWnd], 0FFFFFFFDh
0040A81D  jmp     short loc_40A887
0040A81F  cmp     ebx, 76h
0040A822  jz      loc_40A8B7
0040A828  jg      short loc_40A839
0040A82A  cmp     ebx, 74h
0040A82D  jz      short loc_40A897
0040A82F  cmp     ebx, 75h
0040A832  jz      short loc_40A8A7
0040A834  jmp     loc_409FC4
0040A839  cmp     ebx, 7Ah
0040A83C  jz      short loc_40A85E
0040A83E  cmp     ebx, 7Bh
0040A841  jz      short loc_40A84E
0040A843  cmp     ebx, 77h
0040A846  jnz     loc_409FC4
0040A84C  jmp     short loc_40A8C7
0040A84E  lea     ecx, [ebp+FileName]
0040A854  call    sub_413700
0040A859  jmp     loc_409FC4
0040A85E  lea     ecx, [ebp+FileName]
0040A864  call    sub_413BC8
0040A869  jmp     loc_409FC4
0040A86E  mov     [esp+40h+hWnd], 1
0040A875  jmp     short loc_40A887
0040A877  mov     [esp+40h+hWnd], 0FFFFFFFFh
0040A87E  jmp     short loc_40A887
0040A880  mov     [esp+40h+hWnd], 0FFFFFFFEh; int
0040A887  lea     ecx, [ebp+FileName]; lpParameter
0040A88D  call    sub_4138C4
0040A892  jmp     loc_40A9A0
0040A897  lea     ecx, [ebp+var_358]
0040A89D  call    sub_40EA30
0040A8A2  jmp     loc_409FC4
0040A8A7  lea     ecx, [ebp+var_358]
0040A8AD  call    sub_40F0C0
0040A8B2  jmp     loc_409FC4
0040A8B7  lea     ecx, [ebp+FileName]
0040A8BD  call    sub_4136DC
0040A8C2  jmp     loc_409FC4
0040A8C7  xor     byte ptr [ebp+Reserved], 1
0040A8CB  mov     eax, [ebp+var_308]
0040A8D1  jmp     short loc_40A8EC
0040A8D3  cmp     [ebp+var_238], 0
0040A8DA  jle     short loc_40A8FF
0040A8DC  mov     eax, [ebp+var_304]
0040A8E2  mov     [ebp+var_238], 2
0040A8EC  lea     ecx, [ebp+var_358]
0040A8F2  mov     [esp+40h+hWnd], eax
0040A8F5  call    sub_40EA0C
0040A8FA  jmp     loc_40A9A0
0040A8FF  lea     ecx, [ebp+var_B18]
0040A905  mov     [ebp+var_E8], 0
0040A90F  call    sub_40BBDE
0040A914  jmp     short loc_40A98E
0040A916  cmp     [ebp+var_238], 0
0040A91D  jg      short loc_40A8DC
0040A91F  mov     eax, [ebp+var_5C]
0040A922  mov     [ebp+var_E8], 0
0040A92C  mov     [esp+40h+hWnd], 1
0040A933  mov     [esp+40h+nIndex], eax
0040A937  jmp     short loc_40A981
0040A939  cmp     [ebp+var_238], 0
0040A940  jg      short loc_40A8DC
0040A942  mov     eax, [ebp+var_5C]
0040A945  mov     [ebp+var_E8], 0
0040A94F  mov     [esp+40h+hWnd], 2
0040A956  mov     [esp+40h+nIndex], eax
0040A95A  jmp     short loc_40A981
0040A95C  cmp     [ebp+var_238], 0
0040A963  jg      loc_40A8DC
0040A969  mov     eax, [ebp+var_5C]
0040A96C  mov     [ebp+var_E8], 0
0040A976  mov     [esp+40h+hWnd], 3
0040A97D  mov     [esp+40h+nIndex], eax
0040A981  lea     ecx, [ebp+var_B18]
0040A987  call    sub_40BE12
0040A98C  push    eax
0040A98D  push    eax
0040A98E  lea     ecx, [ebp+FileName]
0040A994  mov     [esp+40h+hWnd], 0
0040A99B  call    sub_40FEF6
0040A9A0  push    eax
0040A9A1  jmp     loc_409FC4
0040A9A6  mov     eax, ds:hWnd
0040A9AB  mov     [esp+40h+hWnd], eax; hWnd
0040A9AE  call    IsZoomed
0040A9B3  test    eax, eax
0040A9B5  mov     eax, ds:hWnd
0040A9BA  push    esi
0040A9BB  setnz   [ebp+var_94]
0040A9C2  mov     [esp+40h+hWnd], eax; hWnd
0040A9C5  call    IsIconic
0040A9CA  test    eax, eax
0040A9CC  push    edi
0040A9CD  jnz     loc_40AA5B
0040A9D3  mov     al, [ebp+var_93]
0040A9D9  cmp     [ebp+var_94], al
0040A9DF  jnz     loc_40AA6B
0040A9E5  fld     [ebp+var_C8]
0040A9EB  mov     eax, ds:dword_4561A0
0040A9F0  xor     edx, edx
0040A9F2  mov     dword ptr [ebp+var_11D8+4], edx
0040A9F8  fld     st
0040A9FA  mov     dword ptr [ebp+var_11D8], eax
0040AA00  fimul   [ebp+var_90]
0040AA06  fild    [ebp+var_11D8]
0040AA0C  fsubp   st(1), st
0040AA0E  fabs
0040AA10  fld1
0040AA12  fxch    st(1)
0040AA14  fucomp  st(1)
0040AA16  fnstsw  ax
0040AA18  sahf
0040AA19  ja      short loc_40AA49
0040AA1B  fxch    st(1)
0040AA1D  fimul   [ebp+var_8C]
0040AA23  mov     eax, ds:dword_4561A4
0040AA28  xor     edx, edx
0040AA2A  mov     dword ptr [ebp+var_11D8+4], edx
0040AA30  mov     dword ptr [ebp+var_11D8], eax
0040AA36  fild    [ebp+var_11D8]
0040AA3C  fsubp   st(1), st
0040AA3E  fabs
0040AA40  fucompp
0040AA42  fnstsw  ax
0040AA44  sahf
0040AA45  jbe     short loc_40AA5B
0040AA47  jmp     short loc_40AA4D
0040AA49  fstp    st
0040AA4B  fstp    st
0040AA4D  mov     eax, 0A1h
0040AA52  call    sub_41246A
0040AA57  test    al, al
0040AA59  jnz     short loc_40AA6B
0040AA5B  lea     ecx, [ebp+FileName]
0040AA61  call    sub_413B76
0040AA66  jmp     loc_40959D
0040AA6B  mov     eax, ds:hWnd
0040AA70  mov     [esp+40h+nIndex], 9; nCmdShow
0040AA78  mov     [esp+40h+hWnd], eax; hWnd
0040AA7B  call    ShowWindow
0040AA80  movzx   eax, [ebp+var_94]
0040AA87  push    edx
0040AA88  lea     ecx, [ebp+FileName]
0040AA8E  push    edx
0040AA8F  mov     [esp+40h+hWnd], 0
0040AA96  mov     [ebp+var_D0], eax
0040AA9C  call    sub_40FEF6
0040AAA1  mov     eax, [ebp+var_304]
0040AAA7  push    ecx
0040AAA8  lea     ecx, [ebp+var_358]
0040AAAE  mov     [esp+40h+hWnd], eax
0040AAB1  call    sub_40EA0C
0040AAB6  mov     [ebp+var_94], 0
0040AABD  push    ebx
0040AABE  mov     [ebp+var_93], 0
0040AAC5  jmp     short loc_40AA5B
0040AAC7  mov     eax, [ebp+hMutex]
0040AACD  mov     [esp+4Ch+hKey], eax; hObject
0040AAD0  call    CloseHandle
0040AAD5  push    eax
0040AAD6  lea     esp, [ebp-0Ch]
0040AAD9  xor     eax, eax
0040AADB  pop     ebx
0040AADC  pop     esi
0040AADD  pop     edi
0040AADE  pop     ebp
0040AADF  retn    10h

; Failed pseudocode: 0x0040AAE4 sub_40AAE4
0040AAE4  push    ebp
0040AAE5  mov     ebp, esp
0040AAE7  push    edi
0040AAE8  push    esi
0040AAE9  push    ebx
0040AAEA  mov     ebx, ecx
0040AAEC  sub     esp, 7Ch
0040AAEF  mov     eax, [ebp+arg_0]
0040AAF2  mov     [ebp+var_4C], eax
0040AAF5  lea     eax, [ecx+0DE8h]
0040AAFB  mov     [esp+88h+lpCriticalSection], eax; lpCriticalSection
0040AAFE  mov     [ebp+var_40], eax
0040AB01  call    EnterCriticalSection
0040AB06  mov     edx, [ebx+2B8h]
0040AB0C  push    esi
0040AB0D  xor     eax, eax
0040AB0F  call    sub_4124DF
0040AB14  mov     edx, [ebx+2D8h]
0040AB1A  mov     eax, [ebx+0D3Ch]
0040AB20  call    sub_4124DF
0040AB25  mov     ecx, [ebx+10h]
0040AB28  mov     edx, [ebx+0D88h]
0040AB2E  xor     eax, eax
0040AB30  mov     esi, [ebx+14h]
0040AB33  sub     edx, ecx
0040AB35  cmp     dword ptr [ebx+0D30h], 0FFFFFFFFh
0040AB3C  setz    al
0040AB3F  add     eax, 30h
0040AB42  mov     eax, [ebx+eax*4+4]
0040AB46  mov     [esp+88h+var_84], esi
0040AB4A  mov     [esp+88h+lpCriticalSection], ecx
0040AB4D  xor     ecx, ecx
0040AB4F  call    sub_41284E
0040AB54  mov     ecx, [ebx+10h]
0040AB57  mov     edx, [ebx+0D88h]
0040AB5D  mov     esi, [ebx+14h]
0040AB60  lea     eax, [ecx+ecx]
0040AB63  sub     edx, eax
0040AB65  xor     eax, eax
0040AB67  cmp     dword ptr [ebx+0D30h], 0
0040AB6E  setnle  al
0040AB71  add     eax, 2Ch
0040AB74  mov     eax, [ebx+eax*4+0Ch]
0040AB78  mov     [esp+88h+var_84], esi
0040AB7C  mov     [esp+88h+lpCriticalSection], ecx
0040AB7F  xor     ecx, ecx
0040AB81  call    sub_41284E
0040AB86  mov     ecx, [ebx+10h]
0040AB89  xor     eax, eax
0040AB8B  mov     esi, [ebx+14h]
0040AB8E  imul    edx, ecx, -3
0040AB91  add     edx, [ebx+0D88h]
0040AB97  cmp     dword ptr [ebx+0D30h], 0FFFFFFFDh
0040AB9E  setz    al
0040ABA1  add     eax, 38h
0040ABA4  mov     eax, [ebx+eax*4+4]
0040ABA8  mov     [esp+88h+var_84], esi
0040ABAC  mov     [esp+88h+lpCriticalSection], ecx
0040ABAF  xor     ecx, ecx
0040ABB1  call    sub_41284E
0040ABB6  mov     ecx, [ebx+10h]
0040ABB9  mov     edx, [ebx+0D88h]
0040ABBF  mov     esi, [ebx+14h]
0040ABC2  lea     eax, ds:0[ecx*4]
0040ABC9  sub     edx, eax
0040ABCB  xor     eax, eax
0040ABCD  cmp     dword ptr [ebx+0D30h], 0FFFFFFFEh
0040ABD4  setz    al
0040ABD7  add     eax, 34h
0040ABDA  mov     eax, [ebx+eax*4+0Ch]
0040ABDE  mov     [esp+88h+var_84], esi
0040ABE2  mov     [esp+88h+lpCriticalSection], ecx
0040ABE5  xor     ecx, ecx
0040ABE7  call    sub_41284E
0040ABEC  mov     ecx, [ebx+10h]
0040ABEF  mov     esi, [ebx+14h]
0040ABF2  mov     eax, [ebx+148h]
0040ABF8  imul    edx, ecx, -5
0040ABFB  add     edx, [ebx+0D88h]
0040AC01  mov     [esp+88h+var_84], esi
0040AC05  mov     [esp+88h+lpCriticalSection], ecx
0040AC08  xor     ecx, ecx
0040AC0A  call    sub_41284E
0040AC0F  xor     eax, eax
0040AC11  cmp     dword ptr [ebx+0B50h], 1
0040AC18  mov     edx, [ebx+14h]
0040AC1B  setz    al
0040AC1E  xor     ecx, ecx
0040AC20  add     eax, 28h
0040AC23  mov     eax, [ebx+eax*4+4]
0040AC27  mov     [esp+88h+var_84], edx
0040AC2B  mov     edx, [ebx+10h]
0040AC2E  mov     [esp+88h+lpCriticalSection], edx
0040AC31  xor     edx, edx
0040AC33  call    sub_41284E
0040AC38  xor     eax, eax
0040AC3A  cmp     dword ptr [ebx+0B50h], 2
0040AC41  mov     edx, [ebx+10h]
0040AC44  mov     ecx, [ebx+14h]
0040AC47  setz    al
0040AC4A  add     eax, 28h
0040AC4D  mov     eax, [ebx+eax*4+0Ch]
0040AC51  mov     [esp+88h+var_84], ecx
0040AC55  xor     ecx, ecx
0040AC57  mov     [esp+88h+lpCriticalSection], edx
0040AC5A  call    sub_41284E
0040AC5F  xor     eax, eax
0040AC61  cmp     dword ptr [ebx+0B50h], 3
0040AC68  mov     ecx, [ebx+10h]
0040AC6B  mov     esi, [ebx+14h]
0040AC6E  lea     edx, [ecx+ecx]
0040AC71  setz    al
0040AC74  add     eax, 2Ch
0040AC77  mov     eax, [ebx+eax*4+4]
0040AC7B  mov     [esp+88h+lpCriticalSection], ecx
0040AC7E  xor     ecx, ecx
0040AC80  mov     [esp+88h+var_84], esi
0040AC84  call    sub_41284E
0040AC89  cmp     dword ptr [ebx+0D30h], 0
0040AC90  jz      short loc_40AC9E
0040AC92  mov     ecx, ebx
0040AC94  call    sub_401460
0040AC99  jmp     loc_40B998
0040AC9E  lea     edi, [ebp+var_30]
0040ACA1  mov     esi, offset unk_418500
0040ACA6  mov     ecx, 6
0040ACAB  rep movsd
0040ACAD  mov     esi, [ebx+30Ch]
0040ACB3  cmp     esi, 1
0040ACB6  jnz     short loc_40ACC6
0040ACB8  cmp     dword ptr [ebx+0B7Ch], 1
0040ACBF  jnz     short loc_40ACC6
0040ACC1  mov     esi, 2
0040ACC6  cmp     dword ptr [ebx+310h], 0
0040ACCD  jle     short loc_40ACD4
0040ACCF  mov     esi, 5
0040ACD4  mov     eax, [ebx+0D88h]
0040ACDA  sub     eax, [ebx+18h]
0040ACDD  mov     edi, 2
0040ACE2  mov     ecx, [ebx+14h]
0040ACE5  cdq
0040ACE6  idiv    edi
0040ACE8  mov     edx, [ebx+1Ch]
0040ACEB  mov     edi, eax
0040ACED  mov     eax, [ebp+esi*4+var_30]
0040ACF1  mov     esi, [ebx+18h]
0040ACF4  mov     eax, [ebx+eax*4+130h]
0040ACFB  mov     [esp+88h+var_84], edx
0040ACFF  mov     edx, edi
0040AD01  mov     [esp+88h+lpCriticalSection], esi
0040AD04  call    sub_41284E
0040AD09  movzx   eax, byte ptr [ebx+0DD4h]
0040AD10  mov     edx, [ebx+0B6Ch]
0040AD16  test    al, al
0040AD18  jz      short loc_40AD20
0040AD1A  sub     edx, [ebx+0B94h]
0040AD20  mov     ecx, [ebx+34h]
0040AD23  add     eax, eax
0040AD25  cmp     edx, 270Fh
0040AD2B  mov     [esp+88h+var_78], eax
0040AD2F  mov     [esp+88h+var_80], 0
0040AD37  mov     [esp+88h+var_7C], ecx
0040AD3B  jg      short loc_40AD47
0040AD3D  mov     [esp+88h+var_84], 4
0040AD45  jmp     short loc_40AD61
0040AD47  cmp     edx, 1869Fh
0040AD4D  jg      short loc_40AD59
0040AD4F  mov     [esp+88h+var_84], 5
0040AD57  jmp     short loc_40AD61
0040AD59  mov     [esp+88h+var_84], 6
0040AD61  mov     [esp+88h+lpCriticalSection], edx
0040AD64  mov     ecx, ebx
0040AD66  call    sub_40FA06
0040AD6B  movzx   eax, byte ptr [ebx+0DD4h]
0040AD72  sub     esp, 14h
0040AD75  mov     edx, [ebx+0B70h]
0040AD7B  test    al, al
0040AD7D  jz      short loc_40AD85
0040AD7F  mov     edx, [ebx+0CE4h]
0040AD85  mov     esi, [ebx+34h]
0040AD88  add     eax, eax
0040AD8A  cmp     edx, 63h
0040AD8D  mov     ecx, [ebx+0D88h]
0040AD93  mov     edi, [ebx+28h]
0040AD96  mov     [esp+88h+var_78], eax
0040AD9A  mov     [esp+88h+var_7C], esi
0040AD9E  jg      short loc_40ADB2
0040ADA0  add     edi, edi
0040ADA2  mov     [esp+88h+var_84], 2
0040ADAA  sub     ecx, edi
0040ADAC  mov     [esp+88h+var_80], ecx
0040ADB0  jmp     short loc_40ADF9
0040ADB2  cmp     edx, 3E7h
0040ADB8  jg      short loc_40ADCD
0040ADBA  imul    edi, -3
0040ADBD  mov     [esp+88h+var_84], 3
0040ADC5  add     ecx, edi
0040ADC7  mov     [esp+88h+var_80], ecx
0040ADCB  jmp     short loc_40ADF9
0040ADCD  cmp     edx, 270Fh
0040ADD3  jg      short loc_40ADE8
0040ADD5  shl     edi, 2
0040ADD8  mov     [esp+88h+var_84], 4
0040ADE0  sub     ecx, edi
0040ADE2  mov     [esp+88h+var_80], ecx
0040ADE6  jmp     short loc_40ADF9
0040ADE8  imul    edi, -5
0040ADEB  mov     [esp+88h+var_84], 5
0040ADF3  add     ecx, edi
0040ADF5  mov     [esp+88h+var_80], ecx
0040ADF9  mov     [esp+88h+lpCriticalSection], edx
0040ADFC  mov     ecx, ebx
0040ADFE  call    sub_40FA06
0040AE03  mov     eax, [ebx+1Ch]
0040AE06  sub     esp, 14h
0040AE09  mov     ecx, ebx
0040AE0B  mov     [esp+88h+var_84], 0
0040AE13  mov     [esp+88h+var_80], eax
0040AE17  lea     eax, [ebx+300h]
0040AE1D  mov     [esp+88h+lpCriticalSection], eax
0040AE20  call    sub_40F672
0040AE25  mov     edi, [ebx+0BD8h]
0040AE2B  sub     esp, 0Ch
0040AE2E  test    edi, edi
0040AE30  js      short loc_40AE77
0040AE32  mov     edx, [ebx+0BDCh]
0040AE38  test    edx, edx
0040AE3A  js      short loc_40AE77
0040AE3C  cmp     byte ptr [ebx+0DB8h], 0
0040AE43  jz      short loc_40AE77
0040AE45  mov     eax, [ebx+20h]
0040AE48  mov     esi, [ebx+24h]
0040AE4B  lea     ecx, [eax-1]
0040AE4E  imul    eax, edi
0040AE51  mov     edi, [ebx+288h]
0040AE57  imul    edx, esi
0040AE5A  add     edx, [ebx+14h]
0040AE5D  dec     esi
0040AE5E  add     edx, [ebx+1Ch]
0040AE61  mov     [esp+88h+lpCriticalSection], esi
0040AE64  mov     [esp+88h+var_80], edi
0040AE68  mov     edi, [ebx+2BCh]
0040AE6E  mov     [esp+88h+var_84], edi
0040AE72  call    sub_412A48
0040AE77  cmp     dword ptr [ebx+0BE0h], 0
0040AE7E  jle     loc_40B998
0040AE84  cmp     dword ptr [ebx+310h], 0
0040AE8B  jnz     loc_40B998
0040AE91  mov     eax, [ebx+70h]
0040AE94  mov     ecx, ebx
0040AE96  mov     [esp+88h+lpCriticalSection], eax
0040AE99  call    sub_413658
0040AE9E  mov     eax, [ebx+0BE4h]
0040AEA4  push    ecx
0040AEA5  cmp     eax, 0Ch
0040AEA8  jg      loc_40AF31
0040AEAE  lea     eax, [ebx+eax*4]
0040AEB1  mov     edx, [ebx+24h]
0040AEB4  mov     edi, [eax+0BE8h]
0040AEBA  mov     esi, [eax+0C1Ch]
0040AEC0  mov     eax, [ebx+20h]
0040AEC3  imul    edx, esi
0040AEC6  add     edx, [ebx+14h]
0040AEC9  lea     ecx, [eax-1]
0040AECC  add     edx, [ebx+1Ch]
0040AECF  imul    eax, edi
0040AED2  mov     [ebp+var_50], eax
0040AED5  mov     eax, [ebx+288h]
0040AEDB  mov     [esp+88h+var_80], eax
0040AEDF  mov     eax, [ebx+2C4h]
0040AEE5  mov     [esp+88h+var_84], eax
0040AEE9  mov     eax, [ebx+24h]
0040AEEC  dec     eax
0040AEED  mov     [esp+88h+lpCriticalSection], eax
0040AEF0  mov     eax, [ebp+var_50]
0040AEF3  call    sub_412A48
0040AEF8  imul    esi, [ebx+24h]
0040AEFC  mov     edx, [ebx+1Ch]
0040AEFF  mov     eax, [ebx+20h]
0040AF02  add     esi, [ebx+14h]
0040AF05  lea     ecx, [eax-3]
0040AF08  imul    eax, edi
0040AF0B  mov     edi, [ebx+24h]
0040AF0E  add     edx, esi
0040AF10  mov     esi, [ebx+288h]
0040AF16  sub     edi, 3
0040AF19  inc     edx
0040AF1A  inc     eax
0040AF1B  mov     [esp+88h+lpCriticalSection], edi
0040AF1E  mov     [esp+88h+var_80], esi
0040AF22  mov     esi, [ebx+2C4h]
0040AF28  mov     [esp+88h+var_84], esi
0040AF2C  call    sub_412A48
0040AF31  mov     eax, [ebx+0BE4h]
0040AF37  dec     eax
0040AF38  cmp     eax, 0Dh; switch 14 cases
0040AF3B  ja      loc_40B785; jumptable 0040AF41 default case
0040AF41  jmp     ds:off_4197A0[eax*4]; switch jump
0040AF48  mov     esi, [ebx+24h]; jumptable 0040AF41 case 0
0040AF4B  mov     edi, [ebx+288h]
0040AF51  mov     eax, [ebx+20h]
0040AF54  imul    edx, esi, 0Fh
0040AF57  add     edx, [ebx+14h]
0040AF5A  mov     [esp+88h+var_80], edi
0040AF5E  add     edx, [ebx+1Ch]
0040AF61  mov     edi, [ebx+2C8h]
0040AF67  lea     esi, [esi+esi*2]
0040AF6A  lea     ecx, [eax+eax*2]
0040AF6D  lea     eax, ds:0FFFFFFFFh[eax*4]
0040AF74  inc     esi
0040AF75  inc     ecx
0040AF76  mov     [esp+88h+lpCriticalSection], esi
0040AF79  mov     [esp+88h+var_84], edi
0040AF7D  dec     edx
0040AF7E  call    sub_412A48
0040AF83  mov     esi, [ebx+24h]
0040AF86  mov     eax, [ebx+20h]
0040AF89  imul    edx, esi, 0Fh
0040AF8C  add     edx, [ebx+14h]
0040AF8F  lea     ecx, [eax+1]
0040AF92  add     edx, [ebx+1Ch]
0040AF95  lea     eax, ds:0FFFFFFFEh[eax*4]
0040AF9C  lea     ecx, [ecx+ecx*2]
0040AF9F  sub     edx, 2
0040AFA2  jmp     loc_40B153
0040AFA7  mov     esi, [ebx+24h]; jumptable 0040AF41 case 1
0040AFAA  mov     edi, [ebx+288h]
0040AFB0  mov     eax, [ebx+20h]
0040AFB3  mov     edx, esi
0040AFB5  mov     [esp+88h+var_80], edi
0040AFB9  mov     edi, [ebx+2C8h]
0040AFBF  shl     edx, 4
0040AFC2  add     edx, [ebx+14h]
0040AFC5  lea     ecx, [eax+1]
0040AFC8  add     edx, [ebx+1Ch]
0040AFCB  lea     eax, [eax+eax*2]
0040AFCE  inc     esi
0040AFCF  mov     [esp+88h+var_84], edi
0040AFD3  mov     [esp+88h+lpCriticalSection], esi
0040AFD6  dec     eax
0040AFD7  dec     edx
0040AFD8  call    sub_412A48
0040AFDD  mov     esi, [ebx+24h]
0040AFE0  mov     eax, [ebx+20h]
0040AFE3  mov     edi, [ebx+288h]
0040AFE9  mov     edx, esi
0040AFEB  lea     ecx, [eax+3]
0040AFEE  lea     eax, [eax+eax*2]
0040AFF1  shl     edx, 4
0040AFF4  add     edx, [ebx+14h]
0040AFF7  mov     [esp+88h+var_80], edi
0040AFFB  add     edx, [ebx+1Ch]
0040AFFE  mov     edi, [ebx+2C8h]
0040B004  sub     eax, 2
0040B007  sub     edx, 2
0040B00A  mov     [esp+88h+var_84], edi
0040B00E  add     esi, 3
0040B011  mov     [esp+88h+lpCriticalSection], esi
0040B014  call    sub_412A48
0040B019  jmp     loc_40B785; jumptable 0040AF41 default case
0040B01E  mov     esi, [ebx+24h]; jumptable 0040AF41 case 2
0040B021  mov     edi, [ebx+288h]
0040B027  mov     eax, [ebx+20h]
0040B02A  imul    edx, esi, 12h
0040B02D  add     edx, [ebx+14h]
0040B030  mov     [esp+88h+var_80], edi
0040B034  add     edx, [ebx+1Ch]
0040B037  mov     edi, [ebx+2C8h]
0040B03D  add     esi, esi
0040B03F  lea     ecx, [eax-1]
0040B042  dec     esi
0040B043  lea     eax, [eax+eax*8]
0040B046  mov     [esp+88h+lpCriticalSection], esi
0040B049  mov     [esp+88h+var_84], edi
0040B04D  call    sub_412A48
0040B052  mov     esi, [ebx+24h]
0040B055  mov     edi, [ebx+288h]
0040B05B  mov     eax, [ebx+20h]
0040B05E  imul    edx, esi, 12h
0040B061  add     edx, [ebx+14h]
0040B064  mov     [esp+88h+var_80], edi
0040B068  add     edx, [ebx+1Ch]
0040B06B  mov     edi, [ebx+2C8h]
0040B071  lea     ecx, [eax-3]
0040B074  add     esi, esi
0040B076  lea     eax, [eax+eax*8]
0040B079  sub     esi, 3
0040B07C  inc     eax
0040B07D  mov     [esp+88h+var_84], edi
0040B081  mov     [esp+88h+lpCriticalSection], esi
0040B084  inc     edx
0040B085  call    sub_412A48
0040B08A  mov     esi, [ebx+24h]
0040B08D  mov     edi, [ebx+288h]
0040B093  mov     eax, [ebx+20h]
0040B096  imul    edx, esi, 11h
0040B099  add     edx, [ebx+14h]
0040B09C  mov     [esp+88h+var_80], edi
0040B0A0  add     edx, [ebx+1Ch]
0040B0A3  mov     edi, [ebx+2CCh]
0040B0A9  lea     esi, [esi+esi*2]
0040B0AC  lea     ecx, [eax+1]
0040B0AF  lea     eax, [eax+eax*8]
0040B0B2  inc     esi
0040B0B3  dec     eax
0040B0B4  mov     [esp+88h+lpCriticalSection], esi
0040B0B7  mov     [esp+88h+var_84], edi
0040B0BB  dec     edx
0040B0BC  call    sub_412A48
0040B0C1  mov     eax, [ebx+20h]
0040B0C4  mov     esi, [ebx+24h]
0040B0C7  lea     ecx, [eax+3]
0040B0CA  imul    edx, esi, 11h
0040B0CD  add     edx, [ebx+14h]
0040B0D0  lea     eax, [eax+eax*8]
0040B0D3  add     edx, [ebx+1Ch]
0040B0D6  sub     eax, 2
0040B0D9  sub     edx, 2
0040B0DC  mov     edi, [ebx+288h]
0040B0E2  mov     [esp+88h+var_80], edi
0040B0E6  mov     edi, [ebx+2CCh]
0040B0EC  inc     esi
0040B0ED  mov     [esp+88h+var_84], edi
0040B0F1  lea     esi, [esi+esi*2]
0040B0F4  jmp     loc_40B011
0040B0F9  mov     esi, [ebx+24h]; jumptable 0040AF41 case 3
0040B0FC  mov     eax, [ebx+20h]
0040B0FF  mov     edi, [ebx+288h]
0040B105  mov     edx, esi
0040B107  lea     ecx, [eax+eax*2]
0040B10A  lea     esi, [esi+esi*2]
0040B10D  shl     edx, 4
0040B110  add     edx, [ebx+14h]
0040B113  mov     [esp+88h+var_80], edi
0040B117  add     edx, [ebx+1Ch]
0040B11A  mov     edi, [ebx+2C8h]
0040B120  inc     esi
0040B121  imul    eax, 7
0040B124  inc     ecx
0040B125  mov     [esp+88h+lpCriticalSection], esi
0040B128  mov     [esp+88h+var_84], edi
0040B12C  dec     edx
0040B12D  dec     eax
0040B12E  call    sub_412A48
0040B133  mov     esi, [ebx+24h]
0040B136  mov     eax, [ebx+20h]
0040B139  mov     edx, esi
0040B13B  lea     ecx, [eax+1]
0040B13E  shl     edx, 4
0040B141  add     edx, [ebx+14h]
0040B144  add     edx, [ebx+1Ch]
0040B147  lea     ecx, [ecx+ecx*2]
0040B14A  imul    eax, 7
0040B14D  sub     edx, 2
0040B150  sub     eax, 2
0040B153  mov     edi, [ebx+288h]
0040B159  mov     [esp+88h+var_80], edi
0040B15D  mov     edi, [ebx+2C8h]
0040B163  jmp     short loc_40B0EC
0040B165  mov     esi, [ebx+24h]; jumptable 0040AF41 case 4
0040B168  mov     edi, [ebx+288h]
0040B16E  mov     eax, [ebx+20h]
0040B171  imul    edx, esi, 13h
0040B174  add     edx, [ebx+14h]
0040B177  mov     [esp+88h+var_80], edi
0040B17B  add     edx, [ebx+1Ch]
0040B17E  mov     edi, [ebx+2CCh]
0040B184  lea     ecx, [eax+1]
0040B187  lea     eax, [eax+eax*8]
0040B18A  inc     esi
0040B18B  mov     [esp+88h+lpCriticalSection], esi
0040B18E  dec     eax
0040B18F  mov     [esp+88h+var_84], edi
0040B193  dec     edx
0040B194  call    sub_412A48
0040B199  mov     esi, [ebx+24h]
0040B19C  mov     eax, [ebx+20h]
0040B19F  mov     edi, [ebx+288h]
0040B1A5  imul    edx, esi, 13h
0040B1A8  add     edx, [ebx+14h]
0040B1AB  lea     ecx, [eax+3]
0040B1AE  add     edx, [ebx+1Ch]
0040B1B1  lea     eax, [eax+eax*8]
0040B1B4  mov     [esp+88h+var_80], edi
0040B1B8  mov     edi, [ebx+2CCh]
0040B1BE  sub     eax, 2
0040B1C1  sub     edx, 2
0040B1C4  jmp     loc_40B00A
0040B1C9  mov     esi, [ebx+24h]; jumptable 0040AF41 case 5
0040B1CC  mov     edi, [ebx+288h]
0040B1D2  mov     eax, [ebx+20h]
0040B1D5  imul    edx, esi, 11h
0040B1D8  add     edx, [ebx+14h]
0040B1DB  mov     [esp+88h+var_80], edi
0040B1DF  add     edx, [ebx+1Ch]
0040B1E2  mov     edi, [ebx+2CCh]
0040B1E8  lea     esi, [esi+esi*2]
0040B1EB  lea     ecx, [eax+eax*2]
0040B1EE  lea     eax, ds:0FFFFFFFFh[eax*8]
0040B1F5  inc     esi
0040B1F6  inc     ecx
0040B1F7  mov     [esp+88h+lpCriticalSection], esi
0040B1FA  mov     [esp+88h+var_84], edi
0040B1FE  dec     edx
0040B1FF  call    sub_412A48
0040B204  mov     esi, [ebx+24h]
0040B207  mov     eax, [ebx+20h]
0040B20A  imul    edx, esi, 11h
0040B20D  add     edx, [ebx+14h]
0040B210  lea     ecx, [eax+1]
0040B213  add     edx, [ebx+1Ch]
0040B216  lea     eax, ds:0FFFFFFFEh[eax*8]
0040B21D  lea     ecx, [ecx+ecx*2]
0040B220  sub     edx, 2
0040B223  jmp     loc_40B0DC
0040B228  mov     esi, [ebx+24h]; jumptable 0040AF41 case 6
0040B22B  mov     edi, [ebx+288h]
0040B231  mov     eax, [ebx+20h]
0040B234  imul    edx, esi, 11h
0040B237  add     edx, [ebx+14h]
0040B23A  mov     [esp+88h+var_80], edi
0040B23E  add     edx, [ebx+1Ch]
0040B241  mov     edi, [ebx+2CCh]
0040B247  lea     esi, [esi+esi*2]
0040B24A  lea     ecx, [eax+eax*2]
0040B24D  lea     eax, [eax+eax*8]
0040B250  inc     esi
0040B251  inc     ecx
0040B252  dec     eax
0040B253  mov     [esp+88h+lpCriticalSection], esi
0040B256  dec     edx
0040B257  mov     [esp+88h+var_84], edi
0040B25B  call    sub_412A48
0040B260  mov     eax, [ebx+20h]
0040B263  mov     esi, [ebx+24h]
0040B266  lea     ecx, [eax+1]
0040B269  lea     ecx, [ecx+ecx*2]
0040B26C  jmp     loc_40B0CA
0040B271  mov     esi, [ebx+24h]; jumptable 0040AF41 case 7
0040B274  mov     edi, [ebx+288h]
0040B27A  mov     eax, [ebx+20h]
0040B27D  imul    edx, esi, 12h
0040B280  add     edx, [ebx+14h]
0040B283  mov     [esp+88h+var_80], edi
0040B287  add     edx, [ebx+1Ch]
0040B28A  mov     edi, [ebx+2C8h]
0040B290  add     esi, esi
0040B292  lea     ecx, [eax-1]
0040B295  dec     esi
0040B296  add     eax, eax
0040B298  mov     [esp+88h+lpCriticalSection], esi
0040B29B  mov     [esp+88h+var_84], edi
0040B29F  call    sub_412A48
0040B2A4  mov     esi, [ebx+24h]
0040B2A7  mov     edi, [ebx+288h]
0040B2AD  mov     eax, [ebx+20h]
0040B2B0  imul    edx, esi, 12h
0040B2B3  add     edx, [ebx+14h]
0040B2B6  mov     [esp+88h+var_80], edi
0040B2BA  add     edx, [ebx+1Ch]
0040B2BD  mov     edi, [ebx+2C8h]
0040B2C3  add     esi, esi
0040B2C5  lea     ecx, [eax-3]
0040B2C8  dec     esi
0040B2C9  add     eax, eax
0040B2CB  inc     eax
0040B2CC  mov     [esp+88h+lpCriticalSection], esi
0040B2CF  mov     [esp+88h+var_84], edi
0040B2D3  inc     edx
0040B2D4  call    sub_412A48
0040B2D9  mov     esi, [ebx+24h]
0040B2DC  mov     edi, [ebx+288h]
0040B2E2  mov     eax, [ebx+20h]
0040B2E5  imul    edx, esi, 11h
0040B2E8  add     edx, [ebx+14h]
0040B2EB  mov     [esp+88h+var_80], edi
0040B2EF  add     edx, [ebx+1Ch]
0040B2F2  mov     edi, [ebx+2CCh]
0040B2F8  lea     esi, [esi+esi*2]
0040B2FB  lea     ecx, [eax+1]
0040B2FE  add     eax, eax
0040B300  inc     esi
0040B301  dec     eax
0040B302  mov     [esp+88h+lpCriticalSection], esi
0040B305  mov     [esp+88h+var_84], edi
0040B309  dec     edx
0040B30A  call    sub_412A48
0040B30F  mov     esi, [ebx+24h]
0040B312  mov     eax, [ebx+20h]
0040B315  imul    edx, esi, 11h
0040B318  lea     ecx, [eax+3]
0040B31B  jmp     short loc_40B367
0040B31D  mov     esi, [ebx+24h]; jumptable 0040AF41 case 9
0040B320  mov     edi, [ebx+288h]
0040B326  mov     eax, [ebx+20h]
0040B329  mov     edx, esi
0040B32B  mov     [esp+88h+var_80], edi
0040B32F  lea     esi, [esi+esi*2]
0040B332  shl     edx, 4
0040B335  add     edx, [ebx+14h]
0040B338  mov     edi, [ebx+2CCh]
0040B33E  add     edx, [ebx+1Ch]
0040B341  lea     ecx, [eax+eax*2]
0040B344  inc     esi
0040B345  add     eax, eax
0040B347  mov     [esp+88h+lpCriticalSection], esi
0040B34A  inc     ecx
0040B34B  dec     eax
0040B34C  mov     [esp+88h+var_84], edi
0040B350  dec     edx
0040B351  call    sub_412A48
0040B356  mov     eax, [ebx+20h]
0040B359  mov     esi, [ebx+24h]
0040B35C  lea     ecx, [eax+1]
0040B35F  mov     edx, esi
0040B361  shl     edx, 4
0040B364  lea     ecx, [ecx+ecx*2]
0040B367  add     edx, [ebx+14h]
0040B36A  dec     eax
0040B36B  add     edx, [ebx+1Ch]
0040B36E  add     eax, eax
0040B370  sub     edx, 2
0040B373  jmp     loc_40B0DC
0040B378  mov     esi, [ebx+24h]; jumptable 0040AF41 case 10
0040B37B  mov     edi, [ebx+288h]
0040B381  mov     eax, [ebx+20h]
0040B384  imul    edx, esi, 12h
0040B387  add     edx, [ebx+14h]
0040B38A  mov     [esp+88h+var_80], edi
0040B38E  add     edx, [ebx+1Ch]
0040B391  mov     edi, [ebx+2C8h]
0040B397  lea     ecx, [eax+eax*2]
0040B39A  add     esi, esi
0040B39C  add     eax, eax
0040B39E  inc     esi
0040B39F  inc     ecx
0040B3A0  dec     eax
0040B3A1  mov     [esp+88h+var_84], edi
0040B3A5  mov     [esp+88h+lpCriticalSection], esi
0040B3A8  dec     edx
0040B3A9  call    sub_412A48
0040B3AE  mov     esi, [ebx+24h]
0040B3B1  mov     eax, [ebx+20h]
0040B3B4  mov     edi, [ebx+288h]
0040B3BA  imul    edx, esi, 12h
0040B3BD  add     edx, [ebx+14h]
0040B3C0  lea     ecx, [eax+1]
0040B3C3  add     edx, [ebx+1Ch]
0040B3C6  mov     [esp+88h+var_80], edi
0040B3CA  add     esi, esi
0040B3CC  mov     edi, [ebx+2C8h]
0040B3D2  add     esi, 3
0040B3D5  lea     ecx, [ecx+ecx*2]
0040B3D8  dec     eax
0040B3D9  mov     [esp+88h+lpCriticalSection], esi
0040B3DC  add     eax, eax
0040B3DE  sub     edx, 2
0040B3E1  mov     [esp+88h+var_84], edi
0040B3E5  call    sub_412A48
0040B3EA  mov     eax, [ebx+24h]
0040B3ED  mov     esi, [ebx+288h]
0040B3F3  imul    ecx, [ebx+20h], 0Ch
0040B3F7  imul    edx, eax, 6
0040B3FA  add     edx, [ebx+14h]
0040B3FD  mov     [esp+88h+var_80], esi
0040B401  add     edx, [ebx+1Ch]
0040B404  mov     esi, [ebx+2C4h]
0040B40A  add     eax, eax
0040B40C  inc     eax
0040B40D  mov     [esp+88h+lpCriticalSection], eax
0040B410  or      eax, 0FFFFFFFFh
0040B413  inc     ecx
0040B414  mov     [esp+88h+var_84], esi
0040B418  dec     edx
0040B419  call    sub_412A48
0040B41E  imul    ecx, [ebx+20h], 0Ch
0040B422  mov     eax, [ebx+24h]
0040B425  mov     esi, [ebx+288h]
0040B42B  imul    edx, eax, 6
0040B42E  mov     [esp+88h+var_80], esi
0040B432  mov     esi, [ebx+2C4h]
0040B438  add     ecx, 3
0040B43B  add     edx, [ebx+14h]
0040B43E  add     eax, eax
0040B440  add     edx, [ebx+1Ch]
0040B443  add     eax, 3
0040B446  mov     [esp+88h+var_84], esi
0040B44A  mov     [esp+88h+lpCriticalSection], eax
0040B44D  mov     eax, 0FFFFFFFEh
0040B452  sub     edx, 2
0040B455  jmp     loc_40B014
0040B45A  mov     esi, [ebx+24h]; jumptable 0040AF41 case 11
0040B45D  mov     edi, [ebx+288h]
0040B463  mov     eax, [ebx+20h]
0040B466  imul    edx, esi, 12h
0040B469  add     edx, [ebx+14h]
0040B46C  mov     [esp+88h+var_80], edi
0040B470  add     edx, [ebx+1Ch]
0040B473  mov     edi, [ebx+2C8h]
0040B479  lea     ecx, [eax+eax*2]
0040B47C  add     esi, esi
0040B47E  dec     eax
0040B47F  inc     esi
0040B480  inc     ecx
0040B481  mov     [esp+88h+var_84], edi
0040B485  mov     [esp+88h+lpCriticalSection], esi
0040B488  dec     edx
0040B489  call    sub_412A48
0040B48E  mov     esi, [ebx+24h]
0040B491  mov     edi, [ebx+288h]
0040B497  mov     eax, [ebx+20h]
0040B49A  imul    edx, esi, 12h
0040B49D  add     edx, [ebx+14h]
0040B4A0  mov     [esp+88h+var_80], edi
0040B4A4  add     edx, [ebx+1Ch]
0040B4A7  mov     edi, [ebx+2C8h]
0040B4AD  lea     ecx, [eax+1]
0040B4B0  add     esi, esi
0040B4B2  sub     eax, 2
0040B4B5  lea     ecx, [ecx+ecx*2]
0040B4B8  mov     [esp+88h+var_84], edi
0040B4BC  sub     edx, 2
0040B4BF  jmp     loc_40B00E
0040B4C4  mov     eax, [ebx+24h]; jumptable 0040AF41 case 12
0040B4C7  mov     esi, [ebx+288h]
0040B4CD  imul    ecx, [ebx+20h], 0Ch
0040B4D1  imul    edx, eax, 12h
0040B4D4  add     edx, [ebx+14h]
0040B4D7  mov     [esp+88h+var_80], esi
0040B4DB  add     edx, [ebx+1Ch]
0040B4DE  mov     esi, [ebx+2C4h]
0040B4E4  add     eax, eax
0040B4E6  inc     eax
0040B4E7  mov     [esp+88h+lpCriticalSection], eax
0040B4EA  or      eax, 0FFFFFFFFh
0040B4ED  inc     ecx
0040B4EE  mov     [esp+88h+var_84], esi
0040B4F2  dec     edx
0040B4F3  call    sub_412A48
0040B4F8  mov     eax, [ebx+24h]
0040B4FB  mov     esi, [ebx+288h]
0040B501  imul    ecx, [ebx+20h], 0Ch
0040B505  imul    edx, eax, 12h
0040B508  add     edx, [ebx+14h]
0040B50B  mov     [esp+88h+var_80], esi
0040B50F  add     edx, [ebx+1Ch]
0040B512  mov     esi, [ebx+2C4h]
0040B518  add     eax, eax
0040B51A  add     eax, 3
0040B51D  mov     [esp+88h+lpCriticalSection], eax
0040B520  mov     eax, 0FFFFFFFEh
0040B525  add     ecx, 3
0040B528  mov     [esp+88h+var_84], esi
0040B52C  sub     edx, 2
0040B52F  call    sub_412A48
0040B534  mov     eax, [ebx+28h]
0040B537  mov     edx, [ebx+14h]
0040B53A  lea     ecx, ds:0[eax*4]
0040B541  mov     eax, [ebx+288h]
0040B547  mov     [esp+88h+var_80], eax
0040B54B  mov     eax, [ebx+2C4h]
0040B551  mov     [esp+88h+var_84], eax
0040B555  mov     eax, [ebx+34h]
0040B558  mov     [esp+88h+lpCriticalSection], eax
0040B55B  xor     eax, eax
0040B55D  call    sub_412A48
0040B562  mov     eax, [ebx+28h]
0040B565  lea     ecx, ds:0FFFFFFFEh[eax*4]
0040B56C  mov     eax, [ebx+14h]
0040B56F  lea     edx, [eax+1]
0040B572  mov     eax, [ebx+288h]
0040B578  mov     [esp+88h+var_80], eax
0040B57C  mov     eax, [ebx+2C4h]
0040B582  mov     [esp+88h+var_84], eax
0040B586  mov     eax, [ebx+34h]
0040B589  sub     eax, 2
0040B58C  mov     [esp+88h+lpCriticalSection], eax
0040B58F  mov     eax, 1
0040B594  call    sub_412A48
0040B599  mov     esi, [ebx+288h]
0040B59F  mov     ecx, [ebx+28h]
0040B5A2  mov     eax, [ebx+0D88h]
0040B5A8  mov     edx, [ebx+14h]
0040B5AB  mov     [esp+88h+var_80], esi
0040B5AF  mov     esi, [ebx+2C4h]
0040B5B5  add     ecx, ecx
0040B5B7  sub     eax, ecx
0040B5B9  mov     [esp+88h+var_84], esi
0040B5BD  mov     esi, [ebx+34h]
0040B5C0  mov     [esp+88h+lpCriticalSection], esi
0040B5C3  call    sub_412A48
0040B5C8  mov     esi, [ebx+288h]
0040B5CE  mov     eax, [ebx+28h]
0040B5D1  mov     edi, [ebx+34h]
0040B5D4  mov     [esp+88h+var_80], esi
0040B5D8  mov     esi, [ebx+2C4h]
0040B5DE  lea     ecx, [eax-1]
0040B5E1  mov     eax, [ebx+14h]
0040B5E4  add     ecx, ecx
0040B5E6  mov     [esp+88h+var_84], esi
0040B5EA  lea     esi, [edi-2]
0040B5ED  lea     edx, [eax+1]
0040B5F0  mov     eax, ecx
0040B5F2  not     eax
0040B5F4  mov     [esp+88h+lpCriticalSection], esi
0040B5F7  add     eax, [ebx+0D88h]
0040B5FD  jmp     loc_40B6D2
0040B602  mov     esi, [ebx+288h]; jumptable 0040AF41 case 13
0040B608  mov     ecx, [ebx+28h]
0040B60B  mov     eax, [ebx+0D88h]
0040B611  mov     edx, [ebx+14h]
0040B614  mov     [esp+88h+var_80], esi
0040B618  mov     esi, [ebx+2C4h]
0040B61E  add     ecx, ecx
0040B620  sub     eax, ecx
0040B622  mov     [esp+88h+var_84], esi
0040B626  mov     esi, [ebx+34h]
0040B629  mov     [esp+88h+lpCriticalSection], esi
0040B62C  call    sub_412A48
0040B631  mov     eax, [ebx+28h]
0040B634  mov     esi, [ebx+288h]
0040B63A  mov     edi, [ebx+34h]
0040B63D  lea     ecx, [eax-1]
0040B640  mov     eax, [ebx+14h]
0040B643  mov     [esp+88h+var_80], esi
0040B647  mov     esi, [ebx+2C4h]
0040B64D  add     ecx, ecx
0040B64F  lea     edx, [eax+1]
0040B652  mov     eax, ecx
0040B654  not     eax
0040B656  add     eax, [ebx+0D88h]
0040B65C  mov     [esp+88h+var_84], esi
0040B660  lea     esi, [edi-2]
0040B663  mov     [esp+88h+lpCriticalSection], esi
0040B666  call    sub_412A48
0040B66B  mov     eax, [ebx+24h]
0040B66E  mov     esi, [ebx+288h]
0040B674  imul    ecx, [ebx+20h], 0Ch
0040B678  imul    edx, eax, 7
0040B67B  add     edx, [ebx+14h]
0040B67E  mov     [esp+88h+var_80], esi
0040B682  add     edx, [ebx+1Ch]
0040B685  mov     esi, [ebx+2C4h]
0040B68B  inc     eax
0040B68C  mov     [esp+88h+lpCriticalSection], eax
0040B68F  or      eax, 0FFFFFFFFh
0040B692  inc     ecx
0040B693  mov     [esp+88h+var_84], esi
0040B697  dec     edx
0040B698  call    sub_412A48
0040B69D  mov     eax, [ebx+24h]
0040B6A0  mov     esi, [ebx+288h]
0040B6A6  imul    ecx, [ebx+20h], 0Ch
0040B6AA  imul    edx, eax, 7
0040B6AD  add     edx, [ebx+14h]
0040B6B0  mov     [esp+88h+var_80], esi
0040B6B4  add     edx, [ebx+1Ch]
0040B6B7  mov     esi, [ebx+2C4h]
0040B6BD  add     eax, 3
0040B6C0  mov     [esp+88h+lpCriticalSection], eax
0040B6C3  mov     eax, 0FFFFFFFEh
0040B6C8  add     ecx, 3
0040B6CB  mov     [esp+88h+var_84], esi
0040B6CF  sub     edx, 2
0040B6D2  call    sub_412A48
0040B6D7  cmp     dword ptr [ebx+0BE0h], 1
0040B6DE  jg      loc_40B785; jumptable 0040AF41 default case
0040B6E4  imul    ecx, [ebx+20h], 0Ch
0040B6E8  mov     edi, [ebx+40h]
0040B6EB  mov     esi, 2
0040B6F0  mov     [esp+88h+var_84], edi
0040B6F4  sub     ecx, edi
0040B6F6  mov     eax, ecx
0040B6F8  cdq
0040B6F9  idiv    esi
0040B6FB  imul    edi, [ebx+24h], 0Ah
0040B6FF  mov     edx, [ebx+44h]
0040B702  add     edi, [ebx+14h]
0040B705  add     edi, [ebx+1Ch]
0040B708  mov     [esp+88h+var_80], edx
0040B70C  mov     ecx, eax
0040B70E  mov     edx, ds:dword_4561C0
0040B714  mov     eax, [ebx+248h]
0040B71A  mov     [esp+88h+lpCriticalSection], edi
0040B71D  call    sub_4128C0
0040B722  mov     eax, [ebx+2C0h]
0040B728  mov     edx, [ebx+40h]
0040B72B  mov     ecx, ebx
0040B72D  mov     [esp+88h+var_6C], eax
0040B731  mov     eax, [ebx+2BCh]
0040B737  mov     [esp+88h+var_78], edx
0040B73B  mov     [esp+88h+var_70], eax
0040B73F  mov     eax, [ebx+44h]
0040B742  mov     [esp+88h+var_74], eax
0040B746  imul    eax, [ebx+24h], 0Ah
0040B74A  add     eax, [ebx+14h]
0040B74D  add     eax, [ebx+1Ch]
0040B750  mov     [esp+88h+var_7C], eax
0040B754  imul    eax, [ebx+20h], 0Ch
0040B758  sub     eax, edx
0040B75A  cdq
0040B75B  idiv    esi
0040B75D  mov     edx, [ebx+468h]
0040B763  mov     [esp+88h+var_80], eax
0040B767  mov     eax, [ebx+440h]
0040B76D  mov     eax, [eax+edx*4]
0040B770  mov     [esp+88h+var_84], eax
0040B774  mov     eax, [ebx+0D3Ch]
0040B77A  mov     [esp+88h+lpCriticalSection], eax
0040B77D  call    sub_41344A
0040B782  sub     esp, 20h
0040B785  mov     eax, [ebx+74h]; jumptable 0040AF41 default case
0040B788  mov     ecx, ebx
0040B78A  mov     [esp+88h+lpCriticalSection], eax
0040B78D  call    sub_413658
0040B792  push    eax
0040B793  mov     eax, [ebx+2B8h]
0040B799  mov     ecx, ebx
0040B79B  mov     edx, [ebx+440h]
0040B7A1  mov     [esp+88h+var_68], 10h; UINT
0040B7A9  mov     [esp+88h+var_80], 0; int
0040B7B1  mov     [esp+88h+var_6C], eax; int
0040B7B5  mov     eax, [ebx+2BCh]
0040B7BB  mov     [esp+88h+var_70], eax; int
0040B7BF  mov     eax, [ebx+74h]
0040B7C2  shl     eax, 3
0040B7C5  mov     [esp+88h+var_74], eax; int
0040B7C9  imul    eax, [ebx+20h], 0Ch
0040B7CD  mov     [esp+88h+var_78], eax; int
0040B7D1  mov     eax, [ebx+1Ch]
0040B7D4  add     eax, [ebx+14h]
0040B7D7  mov     [esp+88h+var_7C], eax; int
0040B7DB  mov     eax, [ebx+0BE4h]
0040B7E1  add     eax, [ebx+48Ch]
0040B7E7  mov     eax, [edx+eax*4]
0040B7EA  mov     [esp+88h+var_84], eax; int
0040B7EE  mov     eax, [ebx+0D3Ch]
0040B7F4  mov     [esp+88h+lpCriticalSection], eax; int
0040B7F7  call    sub_413552
0040B7FC  mov     eax, [ebx+70h]
0040B7FF  sub     esp, 24h
0040B802  mov     ecx, ebx
0040B804  mov     [esp+88h+lpCriticalSection], eax
0040B807  call    sub_413658
0040B80C  cmp     dword ptr [ebx+0BE0h], 2
0040B813  push    edx
0040B814  jnz     loc_40B998
0040B81A  mov     eax, [ebx+2B8h]
0040B820  mov     edx, [ebx+494h]
0040B826  mov     ecx, ebx
0040B828  mov     [esp+88h+var_80], 0
0040B830  mov     [esp+88h+var_6C], eax
0040B834  mov     eax, [ebx+2BCh]
0040B83A  mov     [esp+88h+var_70], eax
0040B83E  mov     eax, [ebx+74h]
0040B841  shl     eax, 3
0040B844  mov     [esp+88h+var_74], eax
0040B848  imul    eax, [ebx+20h], 0Ch
0040B84C  mov     [esp+88h+var_78], eax
0040B850  mov     eax, [ebx+1Ch]
0040B853  add     eax, [ebx+14h]
0040B856  mov     [esp+88h+var_7C], eax
0040B85A  mov     eax, [ebx+440h]
0040B860  mov     eax, [eax+edx*4]
0040B863  mov     [esp+88h+var_84], eax
0040B867  mov     eax, [ebx+0D3Ch]
0040B86D  mov     [esp+88h+lpCriticalSection], eax
0040B870  call    sub_41344A
0040B875  mov     edx, [ebx+44h]
0040B878  sub     esp, 20h
0040B87B  mov     eax, [ebx+248h]
0040B881  xor     ecx, ecx
0040B883  mov     [esp+88h+var_80], edx
0040B887  imul    edx, [ebx+20h], 6
0040B88B  dec     edx
0040B88C  mov     [esp+88h+var_84], edx
0040B890  imul    edx, [ebx+24h], 0Ah
0040B894  add     edx, [ebx+14h]
0040B897  add     edx, [ebx+1Ch]
0040B89A  mov     [esp+88h+lpCriticalSection], edx
0040B89D  mov     edx, ds:dword_4561C0
0040B8A3  call    sub_4128C0
0040B8A8  imul    ecx, [ebx+20h], 6
0040B8AC  mov     edx, [ebx+44h]
0040B8AF  mov     eax, [ebx+248h]
0040B8B5  mov     [esp+88h+var_80], edx
0040B8B9  lea     edx, [ecx-1]
0040B8BC  mov     [esp+88h+var_84], edx
0040B8C0  imul    edx, [ebx+24h], 0Ah
0040B8C4  add     edx, [ebx+14h]
0040B8C7  add     edx, [ebx+1Ch]
0040B8CA  mov     [esp+88h+lpCriticalSection], edx
0040B8CD  mov     edx, ds:dword_4561C0
0040B8D3  call    sub_4128C0
0040B8D8  mov     eax, [ebx+2C0h]
0040B8DE  mov     edx, [ebx+494h]
0040B8E4  mov     ecx, ebx
0040B8E6  mov     [esp+88h+var_80], 0
0040B8EE  mov     [esp+88h+var_6C], eax
0040B8F2  mov     eax, [ebx+2BCh]
0040B8F8  mov     [esp+88h+var_70], eax
0040B8FC  mov     eax, [ebx+44h]
0040B8FF  mov     [esp+88h+var_74], eax
0040B903  imul    eax, [ebx+20h], 6
0040B907  dec     eax
0040B908  mov     [esp+88h+var_78], eax
0040B90C  imul    eax, [ebx+24h], 0Ah
0040B910  add     eax, [ebx+14h]
0040B913  add     eax, [ebx+1Ch]
0040B916  mov     [esp+88h+var_7C], eax
0040B91A  mov     eax, [ebx+440h]
0040B920  mov     eax, [eax+edx*4+4]
0040B924  mov     [esp+88h+var_84], eax
0040B928  mov     eax, [ebx+0D3Ch]
0040B92E  mov     [esp+88h+lpCriticalSection], eax
0040B931  call    sub_41344A
0040B936  mov     eax, [ebx+2C0h]
0040B93C  sub     esp, 20h
0040B93F  mov     ecx, ebx
0040B941  imul    edx, [ebx+20h], 6
0040B945  mov     [esp+88h+var_6C], eax
0040B949  mov     eax, [ebx+2BCh]
0040B94F  mov     [esp+88h+var_70], eax
0040B953  mov     eax, [ebx+44h]
0040B956  mov     [esp+88h+var_80], edx
0040B95A  mov     [esp+88h+var_74], eax
0040B95E  lea     eax, [edx-1]
0040B961  mov     edx, [ebx+494h]
0040B967  mov     [esp+88h+var_78], eax
0040B96B  imul    eax, [ebx+24h], 0Ah
0040B96F  add     eax, [ebx+14h]
0040B972  add     eax, [ebx+1Ch]
0040B975  mov     [esp+88h+var_7C], eax
0040B979  mov     eax, [ebx+440h]
0040B97F  mov     eax, [eax+edx*4+8]
0040B983  mov     [esp+88h+var_84], eax
0040B987  mov     eax, [ebx+0D3Ch]
0040B98D  mov     [esp+88h+lpCriticalSection], eax
0040B990  call    sub_41344A
0040B995  sub     esp, 20h
0040B998  fld1
0040B99A  fld     qword ptr [ebx+0D50h]
0040B9A0  fucompp
0040B9A2  fnstsw  ax
0040B9A4  sahf
0040B9A5  jbe     loc_40BA3C
0040B9AB  mov     eax, [ebx+0D88h]
0040B9B1  mov     ecx, [ebx+0D8Ch]
0040B9B7  mov     edx, [ebx+0D38h]
0040B9BD  mov     [esp+88h+lpCriticalSection], 0
0040B9C4  mov     [esp+88h+var_7C], eax
0040B9C8  mov     [esp+88h+var_84], eax
0040B9CC  mov     eax, ds:dword_4561C0
0040B9D1  mov     [esp+88h+var_78], ecx
0040B9D5  mov     [esp+88h+var_80], ecx
0040B9D9  xor     ecx, ecx
0040B9DB  call    sub_413F44
0040B9E0  fnstcw  [ebp+var_3A]
0040B9E3  fld     qword ptr [ebx+0D50h]
0040B9E9  mov     dx, [ebp+var_3A]
0040B9ED  xor     ecx, ecx
0040B9EF  mov     eax, [ebx+0D38h]
0040B9F5  mov     [esp+88h+lpCriticalSection], 0
0040B9FC  fld     st
0040B9FE  or      dh, 0Ch
0040BA01  fimul   dword ptr [ebx+0D8Ch]
0040BA07  mov     [ebp+var_3C], dx
0040BA0B  mov     edx, ds:dword_4561C0
0040BA11  fldcw   [ebp+var_3C]
0040BA14  fistp   [ebp+var_48]
0040BA17  fldcw   [ebp+var_3A]
0040BA1A  mov     esi, dword ptr [ebp+var_48]
0040BA1D  fimul   dword ptr [ebx+0D88h]
0040BA23  mov     [esp+88h+var_80], esi
0040BA27  fldcw   [ebp+var_3C]
0040BA2A  fistp   [ebp+var_48]
0040BA2D  fldcw   [ebp+var_3A]
0040BA30  mov     esi, dword ptr [ebp+var_48]
0040BA33  mov     [esp+88h+var_84], esi
0040BA37  call    sub_4128C0
0040BA3C  fld     qword ptr [ebx+0D50h]
0040BA42  mov     edx, [ebx+2D8h]
0040BA48  fnstcw  [ebp+var_3A]
0040BA4B  mov     eax, [ebx+0D3Ch]
0040BA51  mov     [esp+88h+lpCriticalSection], 0
0040BA58  fld     st
0040BA5A  mov     [esp+88h+var_7C], edx
0040BA5E  mov     dx, [ebp+var_3A]
0040BA62  fimul   dword ptr [ebx+0D8Ch]
0040BA68  or      dh, 0Ch
0040BA6B  mov     [ebp+var_3C], dx
0040BA6F  mov     edx, ds:dword_4561C0
0040BA75  fldcw   [ebp+var_3C]
0040BA78  fistp   [ebp+var_48]
0040BA7B  fldcw   [ebp+var_3A]
0040BA7E  mov     esi, dword ptr [ebp+var_48]
0040BA81  fimul   dword ptr [ebx+0D88h]
0040BA87  mov     [esp+88h+var_80], esi
0040BA8B  fldcw   [ebp+var_3C]
0040BA8E  fistp   [ebp+var_48]
0040BA91  fldcw   [ebp+var_3A]
0040BA94  mov     ecx, dword ptr [ebp+var_48]
0040BA97  mov     [esp+88h+var_84], ecx
0040BA9B  xor     ecx, ecx
0040BA9D  call    sub_412875
0040BAA2  cmp     byte ptr [ebp+var_4C], 0
0040BAA6  jz      short loc_40BAAD
0040BAA8  call    sub_4117A3
0040BAAD  mov     eax, [ebp+var_40]
0040BAB0  mov     [ebp+arg_0], eax
0040BAB3  lea     esp, [ebp-0Ch]
0040BAB6  pop     ebx
0040BAB7  pop     esi
0040BAB8  pop     edi
0040BAB9  pop     ebp
0040BABA  jmp     LeaveCriticalSection

; Failed pseudocode: 0x0040EA5A sub_40EA5A
0040EA5A  push    ebp
0040EA5B  mov     eax, 4030h
0040EA60  mov     ebp, esp
0040EA62  push    edi
0040EA63  push    esi
0040EA64  call    sub_414DF0
0040EA69  sub     esp, eax
0040EA6B  lea     eax, [ebp+cbData]
0040EA71  lea     esi, [ebp+Data]
0040EA77  add     ecx, 8
0040EA7A  mov     [esp+8+lpReserved], 0; lpReserved
0040EA82  mov     [ebp+cbData], 4000h
0040EA8C  mov     [esp+8+arg_4], eax; lpcbData
0040EA90  mov     eax, [ebp+arg_4]
0040EA93  mov     [esp+8+arg_0], esi; lpData
0040EA97  mov     [esp+0Ch], ecx; lpType
0040EA9B  mov     [esp+8+lpValueName], eax; lpValueName
0040EA9F  mov     eax, [ebp+arg_0]
0040EAA2  mov     [esp+8+hKey], eax; hKey
0040EAA5  call    RegQueryValueExA
0040EAAA  sub     esp, 18h
0040EAAD  test    eax, eax
0040EAAF  jnz     short loc_40EABB
0040EAB1  mov     ecx, 1000h
0040EAB6  mov     edi, [ebp+arg_8]
0040EAB9  rep movsd
0040EABB  lea     esp, [ebp-8]
0040EABE  pop     esi
0040EABF  pop     edi
0040EAC0  pop     ebp
0040EAC1  retn    0Ch

; Failed pseudocode: 0x004115E6 sub_4115E6
004115E6  push    ebp
004115E7  mov     ebp, esp
004115E9  push    edi
004115EA  push    esi
004115EB  push    ebx
004115EC  sub     esp, 2Ch
004115EF  mov     ebx, [ebp+arg_4]
004115F2  mov     eax, [ebp+arg_C]
004115F5  mov     esi, [ebp+hWnd]
004115F8  mov     edi, [ebp+arg_8]
004115FB  cmp     ebx, 10h
004115FE  mov     [ebp+var_1C], eax
00411601  jz      loc_41170F
00411607  ja      short loc_411631
00411609  cmp     ebx, 2
0041160C  jz      loc_411719
00411612  cmp     ebx, 5
00411615  jz      short loc_411672
00411617  cmp     ebx, 1
0041161A  jnz     loc_411768
00411620  mov     [esp+38h+uPeriod], 1; uPeriod
00411627  call    timeBeginPeriod
0041162C  jmp     loc_411767
00411631  cmp     ebx, 86h
00411637  jz      short loc_411650
00411639  cmp     ebx, 400h
0041163F  jz      loc_4116D3
00411645  cmp     ebx, 20h
00411648  jnz     loc_411768
0041164E  jmp     short loc_411692
00411650  test    edi, 0Bh
00411656  jz      loc_411768
0041165C  mov     [esp+38h+uPeriod], esi; hWnd
0041165F  call    IsIconic
00411664  test    eax, eax
00411666  push    edx
00411667  jnz     loc_41174D
0041166D  jmp     loc_411768
00411672  mov     eax, [ebp+var_1C]
00411675  mov     ecx, 10000h
0041167A  cdq
0041167B  idiv    ecx
0041167D  mov     ds:dword_4561A0, edx
00411683  mov     ds:dword_4561A4, eax
00411688  call    sub_411371
0041168D  jmp     loc_411768
00411692  call    sub_412DE0
00411697  test    eax, eax
00411699  js      loc_411768
0041169F  call    sub_40F128
004116A4  test    eax, eax
004116A6  js      loc_411768
004116AC  call    sub_412DE0
004116B1  cmp     eax, ds:dword_4561A0
004116B7  jg      loc_411768
004116BD  call    sub_40F128
004116C2  cmp     eax, ds:dword_4561A4
004116C8  jle     loc_411783
004116CE  jmp     loc_411768
004116D3  mov     eax, dword_4186B8
004116D8  mov     ecx, [ebp+var_1C]
004116DB  imul    edx, eax, 1Ch
004116DE  inc     eax
004116DF  cmp     eax, 1000h
004116E4  mov     ds:dword_41E184[edx], 400h
004116EE  mov     ds:dword_41E188[edx], edi
004116F4  mov     ds:dword_41E18C[edx], ecx
004116FA  ja      short loc_411703
004116FC  mov     dword_4186B8, eax
00411701  jmp     short loc_411768
00411703  mov     dword_4186B8, 1
0041170D  jmp     short loc_411768
0041170F  mov     [esp+38h+uPeriod], esi; hWnd
00411712  call    DestroyWindow
00411717  jmp     short loc_411767
00411719  mov     [esp+38h+uPeriod], 1; uPeriod
00411720  call    timeEndPeriod
00411725  push    eax
00411726  mov     ds:hWnd, 0
00411730  mov     ds:hdc, 0
0041173A  mov     ds:byte_41E168, 0
00411741  mov     [esp+38h+uPeriod], 0; dwExitCode
00411748  call    ExitThread
0041174D  mov     [esp+38h+nCmdShow], 5; nCmdShow
00411755  mov     [esp+38h+uPeriod], esi; hWnd
00411758  call    ShowWindow
0041175D  push    eax
0041175E  push    eax
0041175F  mov     [esp+38h+uPeriod], esi; hWnd
00411762  call    SetForegroundWindow
00411767  push    ecx
00411768  mov     eax, [ebp+var_1C]
0041176B  mov     [ebp+arg_8], edi
0041176E  mov     [ebp+arg_4], ebx
00411771  mov     [ebp+hWnd], esi
00411774  mov     [ebp+arg_C], eax
00411777  lea     esp, [ebp-0Ch]
0041177A  pop     ebx
0041177B  pop     esi
0041177C  pop     edi
0041177D  pop     ebp
0041177E  jmp     DefWindowProcW
00411783  mov     [esp+38h+nCmdShow], 7F00h; lpCursorName
0041178B  mov     [esp+38h+uPeriod], 0; hInstance
00411792  call    LoadCursorA
00411797  push    edx
00411798  push    edx
00411799  mov     [esp+38h+uPeriod], eax; hCursor
0041179C  call    SetCursor
004117A1  jmp     short loc_411767

; Failed pseudocode: 0x00413BEC sub_413BEC
00413BEC  push    ebp
00413BED  lea     eax, [ecx+0DE8h]
00413BF3  mov     ebp, esp
00413BF5  push    edi
00413BF6  push    esi
00413BF7  push    ebx
00413BF8  mov     ebx, ecx
00413BFA  sub     esp, 3Ch
00413BFD  mov     [ebp+var_20], eax
00413C00  mov     esi, [ebp+arg_0]
00413C03  mov     [esp+48h+lpCriticalSection], eax; lpCriticalSection
00413C06  call    EnterCriticalSection
00413C0B  mov     edx, [ebx+2B8h]
00413C11  push    eax
00413C12  xor     eax, eax
00413C14  mov     ds:dword_45E500, esi
00413C1A  call    sub_4124DF
00413C1F  mov     edx, [ebx+2D8h]
00413C25  mov     eax, [ebx+0D3Ch]
00413C2B  call    sub_4124DF
00413C30  test    esi, esi
00413C32  jns     short loc_413C44
00413C34  mov     eax, offset aDataPngTitlePn; "./data/png/title.png"
00413C39  call    sub_4128EE
00413C3E  mov     [ebx+98h], eax
00413C44  mov     eax, [ebx]
00413C46  sub     eax, [ebx+8]
00413C49  mov     edi, 2
00413C4E  cdq
00413C4F  idiv    edi
00413C51  mov     edx, [ebx+2B4h]
00413C57  mov     [esp+48h+var_3C], edx
00413C5B  mov     edx, [ebx+0Ch]
00413C5E  mov     ecx, eax
00413C60  mov     eax, [ebx+98h]
00413C66  mov     [esp+48h+var_40], edx
00413C6A  mov     edx, [ebx+8]
00413C6D  mov     [esp+48h+var_44], edx
00413C71  mov     edx, [ebx+68h]
00413C74  mov     [esp+48h+lpCriticalSection], edx
00413C77  mov     edx, ds:dword_4561C0
00413C7D  call    sub_412875
00413C82  mov     eax, [ebx+6Ch]
00413C85  mov     ecx, ebx
00413C87  mov     [esp+48h+lpCriticalSection], eax
00413C8A  call    sub_413658
00413C8F  mov     edx, [ebx+2B8h]
00413C95  push    eax
00413C96  mov     ecx, [ebx+68h]
00413C99  mov     eax, [ebx+6Ch]
00413C9C  mov     [esp+48h+var_40], 0
00413CA4  mov     [esp+48h+var_2C], edx
00413CA8  mov     edx, [ebx+2BCh]
00413CAE  sub     ecx, eax
00413CB0  mov     [esp+48h+var_34], eax
00413CB4  mov     eax, [ebx+440h]
00413CBA  mov     [esp+48h+var_3C], ecx
00413CBE  mov     ecx, ebx
00413CC0  mov     [esp+48h+var_30], edx
00413CC4  mov     edx, [ebx]
00413CC6  mov     [esp+48h+var_38], edx
00413CCA  mov     edx, [ebx+444h]
00413CD0  mov     eax, [eax+edx*4]
00413CD3  mov     [esp+48h+var_44], eax
00413CD7  mov     eax, [ebx+0D3Ch]
00413CDD  mov     [esp+48h+lpCriticalSection], eax
00413CE0  call    sub_41344A
00413CE5  sub     esp, 20h
00413CE8  test    esi, esi
00413CEA  js      loc_413DBD
00413CF0  mov     eax, [ebx+6Ch]
00413CF3  mov     ecx, ebx
00413CF5  mov     [esp+48h+lpCriticalSection], eax
00413CF8  call    sub_413658
00413CFD  push    edx
00413CFE  mov     edx, [ebx+2B8h]
00413D04  mov     eax, [ebx+6Ch]
00413D07  mov     ecx, [ebx+0Ch]
00413D0A  add     ecx, [ebx+68h]
00413D0D  mov     [esp+48h+var_40], 0
00413D15  mov     [esp+48h+var_2C], edx
00413D19  mov     edx, [ebx+2BCh]
00413D1F  mov     [esp+48h+var_34], eax
00413D23  mov     [esp+48h+var_30], edx
00413D27  mov     edx, [ebx]
00413D29  mov     [esp+48h+var_38], edx
00413D2D  cdq
00413D2E  idiv    edi
00413D30  sub     ecx, eax
00413D32  mov     eax, [ebx+440h]
00413D38  mov     [esp+48h+var_3C], ecx
00413D3C  mov     ecx, ebx
00413D3E  mov     eax, [eax+esi*4]
00413D41  mov     [esp+48h+var_44], eax
00413D45  mov     eax, [ebx+0D3Ch]
00413D4B  mov     [esp+48h+lpCriticalSection], eax
00413D4E  call    sub_41344A
00413D53  mov     eax, [ebx+70h]
00413D56  sub     esp, 20h
00413D59  mov     ecx, ebx
00413D5B  mov     [esp+48h+lpCriticalSection], eax
00413D5E  call    sub_413658
00413D63  mov     esi, ds:dword_41E160
00413D69  push    ecx
00413D6A  test    esi, esi
00413D6C  jz      short loc_413DBD
00413D6E  mov     edx, [ebx+2B8h]
00413D74  mov     eax, [ebx+6Ch]
00413D77  mov     ecx, [ebx+0Ch]
00413D7A  add     ecx, [ebx+68h]
00413D7D  mov     [esp+48h+var_40], 0
00413D85  mov     [esp+48h+var_44], esi
00413D89  mov     [esp+48h+var_2C], edx
00413D8D  mov     edx, [ebx+2BCh]
00413D93  mov     [esp+48h+var_34], eax
00413D97  mov     [esp+48h+var_30], edx
00413D9B  mov     edx, [ebx]
00413D9D  mov     [esp+48h+var_38], edx
00413DA1  cdq
00413DA2  idiv    edi
00413DA4  add     eax, ecx
00413DA6  mov     ecx, ebx
00413DA8  mov     [esp+48h+var_3C], eax
00413DAC  mov     eax, [ebx+0D3Ch]
00413DB2  mov     [esp+48h+lpCriticalSection], eax
00413DB5  call    sub_41333E
00413DBA  sub     esp, 20h
00413DBD  mov     eax, [ebx+70h]
00413DC0  mov     ecx, ebx
00413DC2  mov     [esp+48h+lpCriticalSection], eax
00413DC5  call    sub_413658
00413DCA  fld1
00413DCC  push    eax
00413DCD  fld     qword ptr [ebx+0D50h]
00413DD3  fucompp
00413DD5  fnstsw  ax
00413DD7  sahf
00413DD8  jbe     loc_413E6F
00413DDE  mov     eax, [ebx+0D88h]
00413DE4  mov     ecx, [ebx+0D8Ch]
00413DEA  mov     edx, [ebx+0D38h]
00413DF0  mov     [esp+48h+lpCriticalSection], 0
00413DF7  mov     [esp+48h+var_3C], eax
00413DFB  mov     [esp+48h+var_44], eax
00413DFF  mov     eax, ds:dword_4561C0
00413E04  mov     [esp+48h+var_38], ecx
00413E08  mov     [esp+48h+var_40], ecx
00413E0C  xor     ecx, ecx
00413E0E  call    sub_413F44
00413E13  fnstcw  [ebp+var_1A]
00413E16  fld     qword ptr [ebx+0D50h]
00413E1C  mov     dx, [ebp+var_1A]
00413E20  xor     ecx, ecx
00413E22  mov     eax, [ebx+0D38h]
00413E28  mov     [esp+48h+lpCriticalSection], 0
00413E2F  fld     st
00413E31  or      dh, 0Ch
00413E34  fimul   dword ptr [ebx+0D8Ch]
00413E3A  mov     [ebp+var_1C], dx
00413E3E  mov     edx, ds:dword_4561C0
00413E44  fldcw   [ebp+var_1C]
00413E47  fistp   [ebp+var_28]
00413E4A  fldcw   [ebp+var_1A]
00413E4D  mov     esi, dword ptr [ebp+var_28]
00413E50  fimul   dword ptr [ebx+0D88h]
00413E56  mov     [esp+48h+var_40], esi
00413E5A  fldcw   [ebp+var_1C]
00413E5D  fistp   [ebp+var_28]
00413E60  fldcw   [ebp+var_1A]
00413E63  mov     esi, dword ptr [ebp+var_28]
00413E66  mov     [esp+48h+var_44], esi
00413E6A  call    sub_4128C0
00413E6F  fld     qword ptr [ebx+0D50h]
00413E75  mov     edx, [ebx+2D8h]
00413E7B  fnstcw  [ebp+var_1A]
00413E7E  mov     eax, [ebx+0D3Ch]
00413E84  mov     [esp+48h+lpCriticalSection], 0
00413E8B  fld     st
00413E8D  mov     [esp+48h+var_3C], edx
00413E91  mov     dx, [ebp+var_1A]
00413E95  fimul   dword ptr [ebx+0D8Ch]
00413E9B  or      dh, 0Ch
00413E9E  mov     [ebp+var_1C], dx
00413EA2  mov     edx, ds:dword_4561C0
00413EA8  fldcw   [ebp+var_1C]
00413EAB  fistp   [ebp+var_28]
00413EAE  fldcw   [ebp+var_1A]
00413EB1  mov     esi, dword ptr [ebp+var_28]
00413EB4  fimul   dword ptr [ebx+0D88h]
00413EBA  mov     [esp+48h+var_40], esi
00413EBE  fldcw   [ebp+var_1C]
00413EC1  fistp   [ebp+var_28]
00413EC4  fldcw   [ebp+var_1A]
00413EC7  mov     ecx, dword ptr [ebp+var_28]
00413ECA  mov     [esp+48h+var_44], ecx
00413ECE  xor     ecx, ecx
00413ED0  call    sub_412875
00413ED5  call    sub_4117A3
00413EDA  mov     eax, [ebp+var_20]
00413EDD  mov     [ebp+arg_0], eax
00413EE0  lea     esp, [ebp-0Ch]
00413EE3  pop     ebx
00413EE4  pop     esi
00413EE5  pop     edi
00413EE6  pop     ebp
00413EE7  jmp     LeaveCriticalSection

; Failed pseudocode: 0x00416918 wsprintfA
00416918  jmp     ds:__imp_wsprintfA

; Failed pseudocode: 0x00416BD8 sprintf
00416BD8  jmp     ds:__imp_sprintf
