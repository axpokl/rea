// Decompiled pseudocode; not original source. Addresses refer to this EXE.

// Address: 0x00401000; symbol: TopLevelExceptionFilter
LONG __stdcall TopLevelExceptionFilter(struct _EXCEPTION_POINTERS *ExceptionInfo)
{
  DWORD v1; // eax
  void (__cdecl *v2)(signed int); // eax
  LONG result; // eax
  void (__cdecl *v4)(signed int); // eax
  void (__cdecl *v5)(signed int); // eax

  v1 = ExceptionInfo->ExceptionRecord->ExceptionCode;
  if ( v1 > 0xC0000091 )
  {
    if ( v1 == -1073741676 )
    {
      v4 = (void (__cdecl *)(signed int))signal(8, 0);
      if ( v4 == (void (__cdecl *)(signed int))1 )
      {
        signal(8, 1);
        return -1;
      }
LABEL_12:
      if ( !v4 )
        return 0;
      v4(8);
      return -1;
    }
    if ( v1 == -1073741674 )
    {
LABEL_17:
      v5 = (void (__cdecl *)(signed int))signal(4, 0);
      if ( v5 == (void (__cdecl *)(signed int))1 )
      {
        signal(4, 1);
        result = -1;
      }
      else
      {
        if ( !v5 )
          return 0;
        v5(4);
        result = -1;
      }
      return result;
    }
    if ( v1 != -1073741677 )
      return 0;
LABEL_11:
    v4 = (void (__cdecl *)(signed int))signal(8, 0);
    if ( v4 == (void (__cdecl *)(signed int))1 )
    {
      signal(8, 1);
      sub_414E20(0);
      return -1;
    }
    goto LABEL_12;
  }
  if ( v1 >= 0xC000008D )
    goto LABEL_11;
  if ( v1 != -1073741819 )
  {
    if ( v1 != -1073741795 )
      return 0;
    goto LABEL_17;
  }
  v2 = (void (__cdecl *)(signed int))signal(11, 0);
  if ( v2 == (void (__cdecl *)(signed int))1 )
  {
    signal(11, 1);
    result = -1;
  }
  else
  {
    if ( !v2 )
      return 0;
    v2(11);
    result = -1;
  }
  return result;
}


// Address: 0x004011B0; symbol: sub_4011B0
void __noreturn sub_4011B0()
{
  int v0; // ST08_4
  UINT v1; // ebx

  if ( TlsCallback_0 )
    TlsCallback_0(0, 2, 0);
  SetUnhandledExceptionFilter(TopLevelExceptionFilter);
  sub_414640();
  sub_414E20(dword_4186CC);
  sub_4142A0();
  if ( dword_45E5A0 )
  {
    dword_4186D0 = dword_45E5A0;
    setmode(iob[4], dword_45E5A0);
    setmode(iob[12], dword_45E5A0);
    setmode(iob[20], dword_45E5A0);
  }
  *(_DWORD *)_p__fmode() = dword_4186D0;
  sub_414C20();
  sub_4147A0();
  v0 = *(_DWORD *)_p__environ();
  v1 = sub_4170E0(dword_41E004);
  cexit();
  ExitProcess(v1);
}


// Address: 0x004012A0; symbol: sub_4012A0
int sub_4012A0()
{
  char v1; // [esp+28h] [ebp-14h]
  int v2; // [esp+2Ch] [ebp-10h]

  v2 = 0;
  return _getmainargs(&dword_41E004, &dword_41E000, &v1, dword_4186C8 & 1, &v2);
}


// Address: 0x00401300; symbol: start
void __noreturn start()
{
  _set_app_type(2);
  sub_4011B0();
}


// Address: 0x00401320; symbol: atexit
int __cdecl atexit(void (__cdecl *a1)())
{
  return atexit(a1);
}


// Address: 0x00401340; symbol: sub_401340
int sub_401340()
{
  HMODULE v0; // eax
  HMODULE v1; // ebx
  FARPROC v2; // esi
  HMODULE v3; // eax
  FARPROC v4; // edx

  v0 = GetModuleHandleA("libgcc_s_dw2-1.dll");
  if ( v0 )
  {
    v1 = v0;
    hLibModule = LoadLibraryA("libgcc_s_dw2-1.dll");
    v2 = GetProcAddress(v1, "__register_frame_info");
    dword_418000 = (int)GetProcAddress(v1, "__deregister_frame_info");
  }
  else
  {
    dword_418000 = 0;
    v2 = 0;
  }
  if ( v2 )
    ((void (__cdecl *)(void *, void *))v2)(&unk_41B0B8, &unk_41E008);
  if ( dword_4186DC )
  {
    v3 = GetModuleHandleA("libgcj-16.dll");
    v4 = 0;
    if ( v3 )
      v4 = GetProcAddress(v3, "_Jv_RegisterClasses");
    if ( v4 )
      ((void (__cdecl *)(int *))v4)(&dword_4186DC);
  }
  return atexit(sub_401430);
}


// Address: 0x00401430; symbol: sub_401430
void __cdecl sub_401430()
{
  if ( dword_418000 )
    dword_418000(&unk_41B0B8);
  if ( hLibModule )
    FreeLibrary(hLibModule);
}


// Address: 0x00401460; symbol: sub_401460
int __thiscall sub_401460(_DWORD *this)
{
  int v1; // esi
  int v2; // ecx
  int v3; // ST78_4
  int v4; // eax
  int v5; // esi
  int v6; // ecx
  int v7; // ST78_4
  int v8; // eax
  int v9; // ecx
  int v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // edx
  int v14; // eax
  char v15; // bl
  int (__cdecl *v16)(int, int); // edx
  int v17; // edi
  unsigned __int8 *v18; // esi
  signed int v19; // ebx
  unsigned int v20; // eax
  signed int v21; // edx
  signed int v22; // edx
  unsigned __int8 v23; // cl
  unsigned int v24; // ecx
  __int16 v25; // dx
  char v26; // al
  int v27; // ST60_4
  int v28; // ST58_4
  int v29; // ST80_4
  int v30; // esi
  int v31; // esi
  int v32; // ebx
  int v33; // eax
  int v34; // ebx
  int v35; // esi
  int v36; // ST50_4
  int v37; // eax
  int v38; // ecx
  int v39; // eax
  int v40; // eax
  signed int v41; // ebx
  int v42; // eax
  int v43; // ST68_4
  int v44; // ST58_4
  wchar_t *v45; // ST70_4
  int v46; // ecx
  int v47; // edx
  int v48; // eax
  BOOL v49; // esi
  int v50; // eax
  int v51; // eax
  int v52; // ebx
  int v53; // ecx
  BOOL v54; // edx
  int v55; // eax
  int v56; // esi
  int v57; // esi
  int v58; // ebx
  int v59; // edi
  char v60; // ST70_1
  int v61; // ST78_4
  int v62; // edx
  char v63; // ST58_1
  signed int v64; // eax
  int v65; // eax
  int v66; // eax
  int v67; // edx
  signed int v68; // edi
  signed __int64 v69; // ST88_8
  int v70; // esi
  signed __int64 v71; // ST58_8
  int v72; // eax
  int v73; // eax
  double v74; // st7
  double v75; // st6
  __int64 v76; // rax
  signed __int64 v77; // ST60_8
  int v78; // eax
  int v79; // eax
  signed int v80; // edx
  double v81; // rt1
  double v82; // st6
  double v83; // st7
  double v84; // rt2
  int v85; // ST70_4
  signed int v86; // ST90_4
  int v87; // eax
  int v88; // eax
  int v89; // edi
  double v90; // ST60_8
  signed __int64 v91; // ST88_8
  int v92; // eax
  signed int v93; // ebx
  double v94; // st7
  int v95; // edx
  signed int v96; // esi
  int v97; // eax
  int v98; // edi
  double v99; // ST68_8
  int v100; // eax
  int v101; // ebx
  int v102; // edx
  int v103; // ebx
  int v104; // ebx
  int v105; // ST78_4
  int v106; // ST70_4
  int v107; // esi
  int v108; // ST78_4
  int v109; // ebx
  int v110; // ST70_4
  int v111; // eax
  int v112; // esi
  int v113; // ST78_4
  int v114; // ebx
  int v115; // ST70_4
  int v116; // eax
  int v117; // ST78_4
  int v118; // ecx
  int v119; // ebx
  int v120; // eax
  int v121; // ST78_4
  int v122; // ecx
  int v123; // ebx
  int v124; // eax
  int v125; // ebx
  int v126; // eax
  int v127; // esi
  int v128; // eax
  int v129; // esi
  int v130; // ecx
  int v131; // ebx
  int v132; // eax
  int v133; // ST78_4
  int v134; // ecx
  int v135; // ebx
  int v136; // eax
  int v137; // ST78_4
  int v138; // ecx
  int v139; // edx
  int v140; // eax
  int v141; // ecx
  int v142; // edx
  int v143; // eax
  int v144; // ebx
  int v145; // esi
  int v146; // ecx
  int v147; // eax
  int v148; // ST78_4
  int v149; // ecx
  int v150; // eax
  int v151; // ST78_4
  int v152; // ebx
  int v153; // ecx
  int v154; // edx
  int v155; // ST78_4
  int v156; // ecx
  int v157; // eax
  int v158; // eax
  int v159; // esi
  int v160; // eax
  int v161; // esi
  int v162; // eax
  int v163; // esi
  int v164; // eax
  int v165; // eax
  int v166; // eax
  int v167; // eax
  signed int v168; // ebx
  char *v169; // edx
  int v170; // esi
  signed int v171; // eax
  int v172; // edx
  int v173; // edx
  int v174; // edi
  int v175; // ecx
  int v176; // eax
  int v177; // ebx
  int v178; // esi
  _DWORD *v179; // edi
  int v180; // eax
  int v181; // ebx
  int v182; // ecx
  int v183; // ebx
  int v184; // eax
  int v185; // eax
  int v186; // ebx
  int v187; // ecx
  int v188; // ebx
  int v189; // eax
  int v190; // eax
  int v191; // ecx
  int v192; // eax
  int v193; // ecx
  int v194; // edx
  int v195; // eax
  int v196; // ecx
  int v197; // edx
  int v198; // ebx
  int v199; // ecx
  signed int v200; // ebx
  int v201; // eax
  int v202; // eax
  int v203; // esi
  signed int v204; // ebx
  signed int v205; // eax
  int v206; // eax
  int v207; // eax
  int v208; // ecx
  int v209; // edx
  int v210; // esi
  int v211; // edi
  int v212; // eax
  int v213; // eax
  _DWORD *v214; // edi
  int v215; // ecx
  int v216; // ebx
  int v217; // eax
  int v218; // eax
  int v219; // ebx
  int v220; // ecx
  int v221; // ebx
  int v222; // eax
  int v223; // eax
  int v224; // ecx
  int v225; // eax
  int v226; // ecx
  int v227; // edx
  int v228; // eax
  int v229; // ecx
  int v230; // edx
  int v231; // esi
  int v232; // ecx
  int v233; // ecx
  int v234; // eax
  signed int v235; // ebx
  int v236; // eax
  int v237; // ecx
  int v238; // edx
  int v239; // eax
  int v240; // ebx
  int v241; // ecx
  int v242; // ST78_4
  signed int v243; // esi
  int v244; // eax
  int v245; // edi
  int v246; // edx
  bool v247; // cf
  int v248; // eax
  int v249; // edx
  int v250; // eax
  int v251; // ecx
  int v252; // edx
  _DWORD *v253; // eax
  int v254; // ecx
  int v255; // ST78_4
  int v256; // eax
  int v257; // edx
  int v258; // eax
  int v259; // ecx
  int v260; // edx
  int v261; // eax
  int v262; // esi
  int v263; // ecx
  int v264; // ST78_4
  int v265; // eax
  int v266; // ecx
  int v267; // ST78_4
  int v268; // eax
  int v269; // ecx
  int v270; // edx
  int v271; // eax
  int v272; // ecx
  int v273; // edx
  int v274; // eax
  int v275; // esi
  int v276; // ecx
  int v277; // ST78_4
  int v278; // eax
  signed int v279; // ebx
  int v280; // edx
  int v281; // eax
  int v282; // edi
  int v283; // ecx
  int v284; // ST78_4
  int v285; // eax
  signed int v286; // ebx
  int v287; // ST78_4
  int v288; // ecx
  int v289; // esi
  int v290; // eax
  int v291; // eax
  int v292; // eax
  signed int v293; // ebx
  int v294; // esi
  int v295; // eax
  int v296; // edx
  int v297; // eax
  unsigned int v298; // ecx
  int v299; // ebx
  int v300; // eax
  bool v301; // zf
  bool v302; // sf
  unsigned __int8 v303; // of
  signed int v304; // ecx
  int v305; // edx
  int v306; // ebx
  int v307; // ecx
  int v308; // ST78_4
  __int64 v309; // rax
  int v310; // esi
  int v311; // edi
  int v312; // ST78_4
  int v313; // eax
  int v314; // eax
  int v315; // ST78_4
  int v316; // eax
  int v317; // ST78_4
  int v318; // eax
  int v319; // ST78_4
  int v320; // eax
  int v321; // ST70_4
  int v322; // eax
  int v323; // eax
  int v324; // eax
  int result; // eax
  int v326; // ecx
  int v327; // ST78_4
  int v328; // ecx
  int v329; // ST78_4
  signed int v330; // eax
  int v331; // esi
  int v332; // ecx
  int v333; // ST78_4
  int v334; // eax
  int v335; // eax
  int v336; // ST78_4
  int v337; // ecx
  int v338; // ST78_4
  int v339; // eax
  char *Dest; // [esp+8h] [ebp-458h]
  char *Desta; // [esp+8h] [ebp-458h]
  char *Format; // [esp+Ch] [ebp-454h]
  int v343; // [esp+44h] [ebp-41Ch]
  int v344; // [esp+44h] [ebp-41Ch]
  int v345; // [esp+4Ch] [ebp-414h]
  char *v346; // [esp+4Ch] [ebp-414h]
  unsigned __int8 v347; // [esp+50h] [ebp-410h]
  unsigned int v348; // [esp+50h] [ebp-410h]
  char *v349; // [esp+50h] [ebp-410h]
  int v350; // [esp+54h] [ebp-40Ch]
  int v351; // [esp+58h] [ebp-408h]
  int v352; // [esp+58h] [ebp-408h]
  int v353; // [esp+58h] [ebp-408h]
  signed int v354; // [esp+58h] [ebp-408h]
  int v355; // [esp+60h] [ebp-400h]
  int v356; // [esp+60h] [ebp-400h]
  int v357; // [esp+60h] [ebp-400h]
  signed int v358; // [esp+60h] [ebp-400h]
  int v359; // [esp+60h] [ebp-400h]
  int i; // [esp+68h] [ebp-3F8h]
  int v361; // [esp+68h] [ebp-3F8h]
  signed int v362; // [esp+68h] [ebp-3F8h]
  signed int v363; // [esp+68h] [ebp-3F8h]
  signed int v364; // [esp+70h] [ebp-3F0h]
  double v365; // [esp+70h] [ebp-3F0h]
  double v366; // [esp+70h] [ebp-3F0h]
  int v367; // [esp+70h] [ebp-3F0h]
  int v368; // [esp+70h] [ebp-3F0h]
  int v369; // [esp+78h] [ebp-3E8h]
  int v370; // [esp+78h] [ebp-3E8h]
  double v371; // [esp+78h] [ebp-3E8h]
  signed int v372; // [esp+78h] [ebp-3E8h]
  int v373; // [esp+78h] [ebp-3E8h]
  int v374; // [esp+78h] [ebp-3E8h]
  int v375; // [esp+78h] [ebp-3E8h]
  int v376; // [esp+78h] [ebp-3E8h]
  __int16 v377; // [esp+80h] [ebp-3E0h]
  int v378; // [esp+80h] [ebp-3E0h]
  int v379; // [esp+80h] [ebp-3E0h]
  _DWORD *v380; // [esp+84h] [ebp-3DCh]
  int v381; // [esp+9Ch] [ebp-3C4h]
  int v382; // [esp+A0h] [ebp-3C0h]
  int v383; // [esp+A4h] [ebp-3BCh]
  int v384; // [esp+A8h] [ebp-3B8h]
  int v385; // [esp+ACh] [ebp-3B4h]
  int v386; // [esp+B0h] [ebp-3B0h]
  int v387; // [esp+B4h] [ebp-3ACh]
  int v388; // [esp+B8h] [ebp-3A8h]
  int v389; // [esp+BCh] [ebp-3A4h]
  wchar_t *v390; // [esp+C0h] [ebp-3A0h]
  int v391; // [esp+C4h] [ebp-39Ch]
  int v392; // [esp+C8h] [ebp-398h]
  int v393; // [esp+D0h] [ebp-390h]
  int v394; // [esp+D4h] [ebp-38Ch]
  int v395; // [esp+DCh] [ebp-384h]
  int v396; // [esp+E0h] [ebp-380h]
  int v397; // [esp+E4h] [ebp-37Ch]
  int v398[10]; // [esp+E8h] [ebp-378h]
  int v399; // [esp+110h] [ebp-350h]
  int v400; // [esp+114h] [ebp-34Ch]
  int v401; // [esp+118h] [ebp-348h]
  int v402; // [esp+11Ch] [ebp-344h]
  int v403; // [esp+120h] [ebp-340h]
  int v404; // [esp+124h] [ebp-33Ch]
  int v405; // [esp+128h] [ebp-338h]
  int v406; // [esp+12Ch] [ebp-334h]
  int v407; // [esp+130h] [ebp-330h]
  char v408[4]; // [esp+13Ch] [ebp-324h]
  int v409; // [esp+140h] [ebp-320h]
  int v410; // [esp+144h] [ebp-31Ch]
  int v411; // [esp+148h] [ebp-318h]
  int v412; // [esp+14Ch] [ebp-314h]
  int v413; // [esp+150h] [ebp-310h]
  int v414; // [esp+154h] [ebp-30Ch]
  int v415; // [esp+158h] [ebp-308h]
  int v416; // [esp+15Ch] [ebp-304h]
  int v417; // [esp+160h] [ebp-300h]
  int v418; // [esp+164h] [ebp-2FCh]
  int v419; // [esp+168h] [ebp-2F8h]
  int v420; // [esp+16Ch] [ebp-2F4h]
  int v421; // [esp+170h] [ebp-2F0h]
  int v422; // [esp+174h] [ebp-2ECh]
  int v423; // [esp+178h] [ebp-2E8h]
  BOOL v424; // [esp+17Ch] [ebp-2E4h]
  BOOL v425; // [esp+180h] [ebp-2E0h]
  BOOL v426; // [esp+184h] [ebp-2DCh]
  BOOL v427; // [esp+188h] [ebp-2D8h]
  BOOL v428; // [esp+18Ch] [ebp-2D4h]
  BOOL v429; // [esp+190h] [ebp-2D0h]
  BOOL v430; // [esp+194h] [ebp-2CCh]
  int v431; // [esp+19Ch] [ebp-2C4h]
  int v432; // [esp+1A0h] [ebp-2C0h]
  int v433; // [esp+1A8h] [ebp-2B8h]
  int v434; // [esp+1ACh] [ebp-2B4h]
  int v435; // [esp+240h] [ebp-220h]
  int v436; // [esp+244h] [ebp-21Ch]
  int v437; // [esp+248h] [ebp-218h]
  int v438; // [esp+24Ch] [ebp-214h]
  int v439; // [esp+250h] [ebp-210h]
  int v440; // [esp+254h] [ebp-20Ch]
  int v441; // [esp+258h] [ebp-208h]
  int v442; // [esp+25Ch] [ebp-204h]
  int v443; // [esp+260h] [ebp-200h]
  int v444; // [esp+264h] [ebp-1FCh]
  int v445; // [esp+268h] [ebp-1F8h]
  int v446; // [esp+26Ch] [ebp-1F4h]
  int v447; // [esp+270h] [ebp-1F0h]
  int v448; // [esp+274h] [ebp-1ECh]
  int v449; // [esp+278h] [ebp-1E8h]
  int v450; // [esp+27Ch] [ebp-1E4h]
  int v451; // [esp+280h] [ebp-1E0h]
  int v452; // [esp+284h] [ebp-1DCh]
  int v453; // [esp+288h] [ebp-1D8h]
  int v454; // [esp+28Ch] [ebp-1D4h]
  int v455; // [esp+290h] [ebp-1D0h]
  int v456; // [esp+294h] [ebp-1CCh]
  int v457; // [esp+298h] [ebp-1C8h]
  int v458; // [esp+29Ch] [ebp-1C4h]
  int v459; // [esp+2A0h] [ebp-1C0h]
  int v460; // [esp+2A4h] [ebp-1BCh]
  int v461; // [esp+2A8h] [ebp-1B8h]
  int v462; // [esp+2ACh] [ebp-1B4h]
  int v463; // [esp+2B0h] [ebp-1B0h]
  int v464; // [esp+2B4h] [ebp-1ACh]
  int v465; // [esp+2B8h] [ebp-1A8h]
  int v466; // [esp+2BCh] [ebp-1A4h]
  int v467; // [esp+2C0h] [ebp-1A0h]
  int v468; // [esp+2C4h] [ebp-19Ch]
  int v469; // [esp+2C8h] [ebp-198h]
  int v470; // [esp+2CCh] [ebp-194h]
  int v471; // [esp+2D0h] [ebp-190h]
  int v472; // [esp+2D4h] [ebp-18Ch]
  int v473; // [esp+2D8h] [ebp-188h]
  int v474; // [esp+2DCh] [ebp-184h]
  int v475; // [esp+2E0h] [ebp-180h]
  int v476; // [esp+2E4h] [ebp-17Ch]
  int v477; // [esp+2E8h] [ebp-178h]
  int v478; // [esp+2ECh] [ebp-174h]
  int v479; // [esp+2F0h] [ebp-170h]
  int v480; // [esp+2F4h] [ebp-16Ch]
  int v481; // [esp+2F8h] [ebp-168h]
  int v482; // [esp+2FCh] [ebp-164h]
  int v483; // [esp+300h] [ebp-160h]
  int v484; // [esp+304h] [ebp-15Ch]
  int v485; // [esp+308h] [ebp-158h]
  int v486; // [esp+30Ch] [ebp-154h]
  int v487; // [esp+310h] [ebp-150h]
  int v488; // [esp+314h] [ebp-14Ch]
  int v489; // [esp+318h] [ebp-148h]

  v380 = this;
  switch ( this[844] )
  {
    case 0xFFFFFFFD:
      goto LABEL_54;
    case 0xFFFFFFFE:
      sub_413658(this[7]);
      sub_41344A(v380[847], *(_DWORD *)(v380[272] + 4 * v380[288] + 36), 0, 0, v380[24], v380[7], v380[175], v380[174]);
      sub_413658(v380[27]);
      if ( *((_BYTE *)v380 + 1188) )
      {
        sub_413658(v380[29] - 1);
        v369 = 0;
        v381 = v380[41];
        v382 = v380[43];
        v383 = v380[45];
        while ( 1 )
        {
          v9 = v380[5];
          v10 = v380[24] * (2 * v369 + 1) / 6;
          v11 = *(&v381 + v369);
          sub_4127DC(v380[6], v380[7], v380[173]);
          for ( i = 0; *(_DWORD *)(v380[685] + 640 * (v369 + 3 * v380[884]) + 32 * i + 12) > 9997; ++i )
            ;
          v364 = 0;
          do
          {
            v12 = v380[884];
            v13 = v380[685];
            if ( v364 > 9 )
              v14 = v13 + 32 * (v364 + 20 * (v369 + 3 * v12) - 10) + 9600;
            else
              v14 = v13 + 32 * (i + v364 + 20 * (v369 + 3 * v12));
            qmemcpy(&v399, (const void *)v14, 0x20u);
            v355 = *(_DWORD *)(v14 + 8);
            v15 = *(_BYTE *)(v14 + 6) >> 4;
            v350 = *(_DWORD *)(v14 + 12);
            if ( *(_DWORD *)(v380[685] + 640 * (v369 + 3 * v380[884]) + 19208) != v355 )
            {
              if ( !v15 )
                goto LABEL_41;
LABEL_16:
              v16 = *(int (__cdecl **)(int, int))(**(_DWORD **)SteamInternal_ContextInit(&off_418284, Format) + 28);
              BYTE2(v400) = BYTE2(v400) & 0xF | 16 * v15;
              v17 = 0;
              v345 = v16(v399, v400);
              v377 = 0;
              v351 = 0;
              while ( 1 )
              {
                v18 = (unsigned __int8 *)(v351 + v345);
                if ( !*(_BYTE *)(v351 + v345) )
                {
                  v436 = (unsigned __int16)v17;
                  v435 = -1;
                  *((_WORD *)&v437 + v17) = 0;
                  sprintf(v408, "%ld", v355 - i);
                  sub_41329C(
                    v380[847],
                    v408,
                    v380[24] * v369 / 3,
                    v380[5] + v380[7] + v380[29] * v364 + 1,
                    v380[175],
                    v380[174]);
                  v27 = v380[174];
                  v28 = v380[175];
                  v29 = v380[29];
                  v30 = v380[24] / 3;
                  v31 = v30 - sub_413256("00000");
                  v32 = v380[29];
                  v33 = v32 * v380[11];
                  v34 = v380[5] + v380[7] + v364 * v32 + 1;
                  v35 = v31 - 4 * (v33 / v380[14]);
                  v36 = v380[24] * v369 / 3;
                  v37 = sub_413256("00000");
                  sub_413552(v380[847], (int)&v437, v36 + v37, v34, v35, v29, v28, v27, 0);
                  v38 = v380[29];
                  v39 = v38 * v380[11] / v380[14];
                  sub_40F924(
                    v350,
                    4,
                    v380[24] * (v369 + 1) / 3 - 4 * v39,
                    v380[5] + v380[7] + v364 * v38,
                    v39,
                    v380[29],
                    1);
                  goto LABEL_41;
                }
                v19 = *v18;
                LOWORD(v390) = 770;
                BYTE2(v390) = 4;
                LOWORD(v398[0]) = 3871;
                BYTE2(v398[0]) = 7;
                v20 = v19;
                if ( v19 <= 127 )
                  goto LABEL_32;
                if ( (unsigned __int8)(v19 + 64) > 0x3Du )
                  break;
                if ( v19 <= 223 )
                {
                  v22 = 0;
                }
                else if ( v19 <= 239 )
                {
                  v22 = 1;
                }
                else
                {
                  v20 = 0;
                  v21 = 1;
                  if ( v19 > 247 )
                    goto LABEL_33;
                  v22 = 2;
                }
                v23 = *((_BYTE *)v398 + v22) & v19;
                v21 = *((unsigned __int8 *)&v390 + v22);
                v20 = v23;
                if ( !(_BYTE)v21 )
                  break;
                v24 = 1;
                while ( (unsigned __int8)v21 > v24 )
                {
                  v347 = v18[v24];
                  if ( (unsigned __int8)(v18[v24] + -128) > 0x3Fu )
                    goto LABEL_32;
                  ++v24;
                  v20 = v347 & 0x3F | (v20 << 6);
                }
LABEL_33:
                v351 += v21;
                if ( v20 > 0xFFFF )
                {
                  if ( v20 > 0xEFFFF )
                    continue;
                  v377 = (v20 & 0x3FF) - 9216;
                  v25 = (v20 >> 10) - 10304;
                  v26 = 2;
                }
                else
                {
                  v25 = v20;
                  v26 = 1;
                }
                *((_WORD *)&v437 + v17) = v25;
                if ( v26 == 2 )
                {
                  *((_WORD *)&v437 + v17 + 1) = v377;
                  v17 += 2;
                }
                else
                {
                  ++v17;
                }
              }
              v20 = 0;
LABEL_32:
              v21 = 1;
              goto LABEL_33;
            }
            if ( v15 )
            {
              cWeight = 700;
              sub_412D22();
              v339 = v380[847];
              sub_412C4D();
              goto LABEL_16;
            }
LABEL_41:
            cWeight = 0;
            sub_412D22();
            v40 = v380[847];
            sub_412C4D();
            ++v364;
          }
          while ( v364 != 20 );
          if ( ++v369 == 3 )
          {
            v41 = 0;
            sub_413658(v380[28]);
            v390 = 0;
            v391 = 0;
            v392 = 1;
            v384 = v380[77];
            v385 = v380[79];
            v386 = v380[99];
            v387 = v380[358];
            v388 = v380[357];
            v389 = v380[359];
            while ( 1 )
            {
              v356 = (int)&v380[*(&v387 + v41)];
              v370 = *(_DWORD *)(v356 + 1552);
              if ( *((_BYTE *)v380 + 3540) )
              {
                if ( !v41 )
                {
                  v42 = v380[739];
LABEL_49:
                  v370 = v42;
                  goto LABEL_50;
                }
                if ( v41 == 1 )
                {
                  v42 = v380[740];
                  goto LABEL_49;
                }
              }
LABEL_50:
              v43 = v380[6];
              v44 = 2 * v41 + 1;
              v45 = (&v390)[v41];
              v46 = v380[5] + (v380[25] + 20 * v380[29] - v380[31]) / 2 + 1;
              v47 = v380[24] * v44 / 6 - 2 * v380[10] - v43;
              v48 = *(&v384 + v41);
              sub_4127DC(v43, v380[7], v380[173]);
              v49 = v41++ <= 1;
              sub_40FA06(
                v370,
                (char *)v45 + (*(_DWORD *)(v356 + 1552) > 9999) * v49 + 4,
                v380[6] + v380[24] * v44 / 6 - 2 * v380[10] - (_DWORD)v45 * v380[10],
                v380[5] + (v380[25] + 20 * v380[29] - v380[31]) / 2 + 1,
                2 * v49 * *((unsigned __int8 *)v380 + 3540));
              if ( v41 == 3 )
              {
                v50 = v380[24] / 3;
                sub_412A78(0, v380[5], v380[25] - v380[31], v380[180]);
                v51 = v380[24] / 3;
                v52 = 0;
                sub_412A78(0, v380[5], v380[25] - v380[31], v380[180]);
                sub_412A78(v380[24], v380[5], 0, v380[180]);
                sub_412A78(v380[24], v380[5] + v380[7], 0, v380[180]);
                sub_412A78(v380[24], 10 * v380[29] + v380[5] + v380[7], 0, v380[180]);
                sub_412A78(v380[24], 20 * v380[29] + v380[5] + v380[7], 0, v380[180]);
                qmemcpy(v398, &unk_418020, 0x14u);
                do
                {
                  v53 = (v380[24] + (v380[16] + v380[24]) / 2) / 2 + v52 * v380[6] + -5 * v380[6] / 2;
                  v54 = v380[884] == v52;
                  v55 = 2 * v398[v52++];
                  v56 = v380[v54 + 61 + v55];
                  sub_4128C0(v380[5] + v380[25] - (v380[31] + v380[17]) / 2, v380[6], v380[7]);
                }
                while ( v52 != 5 );
                sub_413658(v380[7]);
                v57 = v380[24];
                sub_41344A(
                  v380[847],
                  *(_DWORD *)(v380[272] + 4 * (v380[292] + v380[884])),
                  (v57 + v380[16]) / 2,
                  v380[5] + v380[25] - (v380[31] + v380[17]) / 2 + v380[7],
                  v57 - (v57 + v380[16]) / 2,
                  v380[7],
                  v380[175],
                  v380[174]);
                goto LABEL_200;
              }
            }
          }
        }
      }
LABEL_54:
      sub_413658(v380[7]);
      sub_41344A(v380[847], *(_DWORD *)(v380[272] + 4 * v380[288] + 32), 0, 0, v380[24], v380[7], v380[175], v380[174]);
      sub_413658(v380[28]);
      memset(&v390, 0, 0x28u);
      v58 = *((unsigned __int8 *)v380 + 2856);
      v59 = *((unsigned __int8 *)v380 + 2857);
      v60 = *((_BYTE *)v380 + 2856);
      v390 = (wchar_t *)v380[v58 + 51];
      v61 = v380[879];
      v391 = v380[v59 + 53];
      v392 = v380[2 * v61 + 61];
      v393 = v380[84];
      v394 = v380[83];
      v395 = v380[86];
      v396 = v395;
      v62 = *((unsigned __int8 *)v380 + 3540);
      v63 = *((_BYTE *)v380 + 3540);
      v397 = v380[v62 + 59];
      qmemcpy(v398, &unk_418040, sizeof(v398));
      qmemcpy(&v399, &unk_418080, 0x28u);
      memset(v408, 0, 0x78u);
      *(_DWORD *)v408 = v58;
      v409 = (unsigned __int8)(v60 ^ 1);
      v411 = v59;
      v412 = (unsigned __int8)(v59 ^ 1);
      v414 = v61 == 0;
      v415 = v61 == 1;
      v417 = v61 == 2;
      v418 = v61 == 3;
      v64 = v380[850];
      v420 = v64 == 0;
      v421 = v64 == 1;
      v422 = v64 > 1;
      v65 = v380[172];
      v423 = v65 == 0;
      v424 = v65 == 1;
      v425 = v65 == 2;
      v426 = v65 == 3;
      v427 = v65 == 4;
      v428 = v65 == 5;
      v434 = v62;
      v66 = v380[754];
      v429 = v66 == 1;
      v430 = v66 == 0;
      LOBYTE(v66) = *((_BYTE *)v380 + 3512);
      v431 = *((unsigned __int8 *)v380 + 3512);
      v432 = (unsigned __int8)(v66 ^ 1);
      qmemcpy(&v435, &unk_4180C0, 0x78u);
      v433 = (unsigned __int8)(v63 ^ 1);
      v67 = 2 * v380[9];
      v387 = v380[97];
      v388 = v380[99];
      v361 = v380[8];
      v68 = 0;
      v371 = (double)(v380[25] - v380[31] - v67 - v380[7]) / 9.0;
      do
      {
        if ( (&v390)[v68] )
        {
          v69 = (signed __int64)(v371 * (double)v68 + (double)(signed int)v380[5] + (double)(signed int)v380[9]);
          sub_4127DC(v380[6], v380[7], v380[173]);
        }
        if ( v68 != 3 && v68 != 6 )
          sub_413552(
            v380[847],
            *(_DWORD *)(v380[272] + 4 * (v380[288] + v398[v68])),
            v361 + v380[6] + v380[8],
            (signed int)(v371 * (double)v68 + (double)(signed int)v380[5] + (double)(signed int)v380[9]),
            v380[24] / 4 - v380[6] - 2 * v380[8],
            v380[7],
            v380[175],
            v380[174],
            0);
        v70 = 0;
        v378 = 3 * v68;
        while ( v70 < *(&v399 + v68) )
        {
          v357 = v70 + 1;
          v365 = v371 * (double)v68;
          v71 = (signed __int64)(v365 + (double)(signed int)v380[5] + (double)(signed int)v380[9]);
          v72 = (v70 + 1) * (v380[24] / 4);
          v73 = *(&v387 + *(_DWORD *)&v408[4 * (v70 + v378)]);
          sub_4127DC(v380[6], v380[7], v380[173]);
          v352 = v380[6];
          v74 = (double)(signed int)v380[5];
          v75 = (double)(signed int)v380[9];
          if ( v68 != 4 )
          {
            v81 = v75;
            v82 = v74;
            v83 = v81;
LABEL_70:
            sub_413552(
              v380[847],
              *(_DWORD *)(v380[272] + 4 * (v380[289] + *(&v435 + v378 + v70))),
              v352 + v357 * (v380[24] / 4) + v380[8],
              (signed int)(v83 + v82 + v365),
              v380[24] / 4 - v352 - 2 * v380[8],
              v380[7],
              v380[175],
              v380[174],
              0);
            goto LABEL_67;
          }
          if ( v70 != 2 )
          {
            v84 = v75;
            v82 = v74;
            v83 = v84;
            goto LABEL_70;
          }
          v76 = (signed int)v380[24];
          LODWORD(v76) = v380[160];
          sub_4127DC(v352, v380[7], v380[173]);
          v77 = (signed __int64)(v365 + (double)(signed int)v380[5] + (double)(signed int)v380[9]);
          v78 = 3 * (v380[24] / 4);
          v79 = v380[161];
          sub_4127DC(v380[6], v380[7], v380[173]);
          v80 = v380[850];
          if ( v80 < 2 )
            v80 = 2;
          sub_413552(
            v380[847],
            *(_DWORD *)(v380[272] + 4 * (v80 + v380[289] + v449 - 2)),
            3 * (v380[6] + v380[24] / 4) + v380[8],
            (signed int)(v365 + (double)(signed int)v380[5] + (double)(signed int)v380[9]),
            v380[24] / 4 - v380[6] - 2 * v380[8],
            v380[7],
            v380[175],
            v380[174],
            0);
          v357 = 3;
LABEL_67:
          v70 = v357;
        }
        ++v68;
      }
      while ( v68 != 10 );
      if ( v380[754] == 1 )
        sub_412A78(
          v380[6],
          (signed int)(v371 * 7.0 + (double)(signed int)v380[5] + (double)(signed int)v380[9] + (double)(v380[7] / 2)),
          0,
          v380[177]);
      if ( *((_BYTE *)v380 + 3512) )
      {
        v85 = v380[6];
        v86 = (signed int)(v371 * 8.0 + (double)(signed int)v380[5] + (double)(signed int)v380[9]);
        sub_412A48(v380[7] - 1, v380[175], v380[162]);
      }
LABEL_201:
      result = v380[844];
      if ( result == -1 )
      {
        sub_413658(v380[28]);
        v326 = (v380[22] - v380[16]) / 2;
        v327 = v380[146];
        sub_4128C0(v380[5] + v380[23] - (v380[17] + v380[31]) / 2, v380[16], v380[17]);
        result = sub_41344A(
                   v380[847],
                   *(_DWORD *)(v380[272] + 4 * v380[282]),
                   (v380[22] - v380[16]) / 2,
                   v380[5] + v380[23] - (v380[31] + v380[17]) / 2,
                   v380[16],
                   v380[17],
                   v380[175],
                   v380[176]);
      }
      else if ( result )
      {
        sub_413658(v380[28]);
        v328 = (v380[24] - v380[16]) / 2;
        v329 = v380[146];
        sub_4128C0(v380[5] + v380[25] - (v380[17] + v380[31]) / 2, v380[16], v380[17]);
        sub_41344A(
          v380[847],
          *(_DWORD *)(v380[272] + 4 * v380[282]),
          (v380[24] - v380[16]) / 2,
          v380[25] - (v380[31] + v380[17]) / 2 + v380[5],
          v380[16],
          v380[17],
          v380[175],
          v380[176]);
        v330 = v380[844];
        if ( v330 > 1 && v330 <= v380[843] )
        {
          v331 = v380[18];
          v332 = (v380[24] - v380[16]) / 2 - 2 * v331;
          v333 = v380[147];
          sub_4128C0(v380[25] - (v380[31] + v380[17]) / 2 + v380[5], v331, v380[19]);
          sub_41333E(
            v380[847],
            a123n,
            (v380[24] - v380[16]) / 2 - 2 * v380[18],
            v380[25] - (v380[31] + v380[17]) / 2 + v380[5],
            v380[18],
            v380[19],
            v380[175],
            v380[176]);
        }
        v334 = v380[844];
        if ( v334 > 0 && v334 < v380[843] )
        {
          v335 = v380[24] + v380[16];
          v336 = v380[147];
          sub_4128C0(v380[5] + v380[25] - (v380[31] + v380[17]) / 2, v380[18], v380[19]);
          sub_41333E(
            v380[847],
            4296826,
            v380[18] + (v380[24] + v380[16]) / 2,
            v380[5] + v380[25] - (v380[31] + v380[17]) / 2,
            v380[18],
            v380[19],
            v380[175],
            v380[176]);
        }
        v337 = (v380[24] - v380[16]) / 2 - 3 * v380[18] - v380[20];
        v338 = v380[146];
        sub_4128C0(v380[5] + v380[25] - (v380[31] + v380[17]) / 2, v380[20], v380[21]);
        sub_41344A(
          v380[847],
          *(_DWORD *)(v380[272] + 4 * v380[290]),
          -3 * v380[18] + (v380[24] - v380[16]) / 2 - v380[20],
          v380[5] + v380[25] - (v380[31] + v380[17]) / 2,
          v380[20],
          v380[21],
          v380[175],
          v380[176]);
        sub_412A78(v380[24], v380[5], 0, v380[180]);
        result = sub_412A78(v380[24], v380[5] + v380[25] - v380[31], 0, v380[180]);
      }
      return result;
    case 0xFFFFFFFF:
      sub_413658(this[7]);
      sub_41344A(v380[847], *(_DWORD *)(v380[272] + 4 * v380[288] + 28), 0, 0, v380[22], v380[7], v380[175], v380[174]);
      sub_413658(v380[27]);
      *(_DWORD *)v408 = v380[102];
      v409 = v380[100];
      v435 = v380[81];
      v436 = v380[101];
      v1 = v380[27];
      v2 = v380[5] + (v380[26] - v1) / 2;
      v3 = v380[22];
      v4 = *(_DWORD *)&v408[4 * *((unsigned __int8 *)v380 + 3381)];
      sub_4127DC(v1, v1, v380[174]);
      v5 = v380[27];
      v6 = v380[5] + (v380[26] - v5) / 2;
      v7 = v380[22];
      v8 = *(&v435 + *((unsigned __int8 *)v380 + 3204));
      sub_4127DC(v5, v5, v380[174]);
      sub_413658(v380[28]);
      sub_41344A(
        v380[847],
        *(_DWORD *)(v380[272] + 4 * v380[278]),
        0,
        v380[5] + v380[26],
        v380[22],
        v380[28],
        v380[175],
        v380[174]);
      sub_41344A(
        v380[847],
        *(_DWORD *)(v380[272] + 4 * v380[279]),
        0,
        v380[28] + v380[5] + v380[26],
        v380[22],
        v380[28],
        v380[175],
        v380[174]);
      sub_41344A(
        v380[847],
        *(_DWORD *)(v380[272] + 4 * v380[280]),
        0,
        2 * v380[28] + v380[5] + v380[26],
        v380[22],
        v380[28],
        v380[175],
        v380[174]);
      sub_41344A(
        v380[847],
        *(_DWORD *)(v380[272] + 4 * v380[281]),
        0,
        3 * v380[28] + v380[5] + v380[26],
        v380[22],
        v380[28],
        v380[175],
        v380[174]);
      goto LABEL_201;
    case 1:
      sub_413658(this[7]);
      sub_41344A(v380[847], *(_DWORD *)(v380[272] + 4 * v380[288] + 24), 0, 0, v380[24], v380[7], v380[175], v380[174]);
      sub_41344A(
        v380[847],
        *(_DWORD *)(v380[272] + 4 * v380[295]),
        v380[24] / 2,
        v380[5],
        v380[24] / 2,
        (-20 * v380[9] + v380[25] - v380[31]) / 2,
        v380[175],
        v380[174]);
      sub_413658(v380[28]);
      *(_DWORD *)v408 = v380[41];
      v409 = v380[43];
      v410 = v380[45];
      v411 = v380[80];
      v412 = v380[76];
      v413 = v380[101];
      v414 = v380[47];
      v415 = v380[49];
      v416 = v380[57];
      v417 = v380[55];
      v418 = v380[51];
      v419 = v380[53];
      v420 = v380[2 * v380[879] + 61];
      v421 = v380[*((unsigned __int8 *)v380 + 3540) + 59];
      v422 = v380[83];
      v423 = v380[82];
      v87 = v380[81];
      qmemcpy(&v435, &off_418140, 0x44u);
      v424 = v87;
      v88 = v380[178];
      qmemcpy(&v390, &off_4181A0, 0x24u);
      v399 = v88;
      v400 = v88;
      v401 = v88;
      v402 = v88;
      v403 = v88;
      qmemcpy(v398, off_4181E0, 0x24u);
      v404 = v88;
      v405 = v88;
      v406 = v380[177];
      v407 = v406;
      v89 = v380[8];
      v372 = 0;
      v366 = 0.0625 * (double)(v380[25] - v380[31] - v380[9] - v380[7]);
      do
      {
        v90 = v366 * (double)v372;
        v91 = (signed __int64)(v90 + (double)(signed int)v380[5] + (double)(v380[9] / 2));
        v92 = *(_DWORD *)&v408[4 * v372];
        sub_4127DC(v380[6], v380[7], v380[173]);
        sub_41329C(
          v380[847],
          *(&v435 + v372++),
          v380[8] + v89 + v380[6],
          (signed int)(v90 + (double)(signed int)v380[5] + (double)(v380[9] / 2)),
          v380[175],
          v380[174]);
      }
      while ( v372 != 17 );
      v93 = 0;
      if ( *((_BYTE *)v380 + 3381) )
      {
        do
        {
          v98 = *(&v399 + v93);
          v99 = v366 * (double)v93;
          sub_41329C(
            v380[847],
            (&v390)[v93],
            v380[24] / 4,
            (signed int)(v99 + (double)(signed int)v380[5] + (double)(v380[9] / 2)),
            *(&v399 + v93),
            v380[174]);
          v100 = v398[v93++];
          sub_41329C(
            v380[847],
            v100,
            v380[6] + v380[24] / 4,
            (signed int)(v99 + (double)(signed int)v380[5] + (double)(v380[9] / 2)),
            v98,
            v380[174]);
        }
        while ( v93 != 9 );
      }
      else
      {
        do
        {
          v94 = v366 * (double)v93 + (double)(signed int)v380[5] + (double)(v380[9] / 2);
          v95 = v93++ + v380[288];
          sub_413552(
            v380[847],
            *(_DWORD *)(v380[272] + 4 * v95),
            v380[24] / 4,
            (signed int)v94,
            v380[24] / 4,
            v380[7],
            v380[175],
            v380[174],
            0);
        }
        while ( v93 != 17 );
      }
      v96 = 8;
      v97 = v380[24] / 2;
      sub_412A78(0, v380[5], v380[25] - v380[31], v380[180]);
      do
      {
        v101 = v380[9];
        v102 = -20 * v101;
        v103 = v96++ * v101;
        v104 = v380[5] + (v102 + v380[25] - v380[31]) / 2 + v103;
        v105 = (-12 * v380[8] + 3 * v380[24] / 2) / 2;
        v106 = v380[97];
        sub_40F528(v380[102], 2, v105, v104);
        sub_40F528(v106, 10, v105 + 2 * v380[8], v104);
      }
      while ( v96 != 20 );
      v107 = v380[174];
      v108 = v380[177];
      v109 = v380[5] + (-20 * v380[9] + v380[25] - v380[31]) / 2 + 8 * v380[9] - v380[7];
      v110 = 3 * v380[24] / 2;
      v111 = sub_413256("PgUp");
      sub_41329C(v380[847], "PgUp", (unsigned int)(v110 - v111) >> 1, v109, v108, v107);
      v112 = v380[173];
      v113 = v380[178];
      v114 = v380[5] + (-20 * v380[9] + v380[25] - v380[31]) / 2 + 8 * v380[9];
      v115 = 3 * v380[24] / 2;
      v116 = sub_413256("PgDn");
      sub_41329C(v380[847], "PgDn", (unsigned int)(v115 - v116) >> 1, v114, v113, v112);
      v117 = v380[37];
      v118 = v380[36];
      v119 = v380[5] + (-20 * v380[9] + v380[25] - v380[31]) / 2 + 15 * v380[9] - v117 / 2;
      v120 = 2 * v380[8] + (-12 * v380[8] + 3 * v380[24] / 2) / 2;
      sub_412A48(v117, 0, v380[181]);
      v121 = v380[37];
      v122 = v380[36];
      v123 = v380[5] + (-20 * v380[9] + v380[25] - v380[31]) / 2 + 15 * v380[9] - v121 / 2;
      v124 = -12 * v380[8] + 3 * v380[24] / 2;
      sub_412A48(v121, 0, v380[173]);
      v125 = v380[5] + (-20 * v380[9] + v380[25] - v380[31]) / 2 + 20 * v380[9] - v380[37];
      v126 = (3 * v380[24] / 2 - v380[36]) / 2;
      sub_412A48(v380[37], 0, v380[173]);
      v127 = v380[5] + (-20 * v380[9] + v380[25] - v380[31]) / 2 + 20 * v380[9];
      v128 = (3 * v380[24] / 2 - v380[36]) / 2;
      sub_412A48(v380[37], 0, v380[174]);
      v129 = v380[37];
      v130 = v380[36];
      v131 = v380[5] + (-20 * v380[9] + v380[25] - v380[31]) / 2 + 15 * v380[9] - v129 / 2;
      v132 = 12 * v380[8] + (-12 * v380[8] + 3 * v380[24] / 2) / 2;
      sub_412A48(v129, 0, v380[173]);
      v133 = v380[37];
      v134 = v380[36];
      v135 = v380[5] + (-20 * v380[9] + v380[25] - v380[31]) / 2 + 15 * v380[9] - v133 / 2;
      v136 = (-12 * v380[8] + 3 * v380[24] / 2) / 2;
      sub_412A48(v133, 0, v380[174]);
      v137 = v380[37];
      v138 = v380[5] + (-20 * v380[9] + v380[25] - v380[31]) / 2 + 15 * v380[9] - v137 / 2;
      v139 = (-12 * v380[8] + 3 * v380[24] / 2) / 2 + 2 * v380[8];
      v140 = v380[160];
      sub_4127DC(v380[36], v137, v380[173]);
      v141 = 15 * v380[9] + v380[5] + (-20 * v380[9] + v380[25] - v380[31]) / 2 - v380[37] / 2;
      v142 = (-12 * v380[8] + 3 * v380[24] / 2) / 2 + 2 * v380[8];
      v143 = v380[161];
      sub_4127DC(v380[36], v380[37], v380[173]);
      v144 = v380[37];
      v145 = v380[36];
      v146 = v380[5] + (-20 * v380[9] + v380[25] - v380[31]) / 2 + 20 * v380[9] - v144;
      v147 = (3 * v380[24] / 2 - v145) / 2;
      v148 = v380[158];
      sub_4127DC(v145, v144, v380[173]);
      v149 = v380[5] + (-20 * v380[9] + v380[25] - v380[31]) / 2 + 20 * v380[9];
      v150 = 3 * v380[24];
      v151 = v380[159];
      sub_4127DC(v380[36], v380[37], v380[173]);
      v152 = v380[37];
      v153 = 15 * v380[9] + v380[5] + (-20 * v380[9] + v380[25] - v380[31]) / 2 - v152 / 2;
      v154 = (-12 * v380[8] + 3 * v380[24] / 2) / 2 + 12 * v380[8];
      v155 = v380[156];
      sub_4127DC(v380[36], v152, v380[173]);
      v156 = 15 * v380[9] + v380[5] + (-20 * v380[9] + v380[25] - v380[31]) / 2;
      v157 = (-12 * v380[8] + 3 * v380[24] / 2) / 2;
      v158 = v380[157];
      sub_4127DC(v380[36], v380[37], v380[173]);
      v159 = v380[8];
      v160 = -12 * v159 + 3 * v380[24] / 2;
      sub_412A78(12 * v159, v380[5] + (-20 * v380[9] + v380[25] - v380[31]) / 2 - 1, 0, v380[175]);
      v161 = v380[8];
      v162 = -12 * v161 + 3 * v380[24] / 2;
      sub_412A78(12 * v161, v380[5] + (-20 * v380[9] + v380[25] - v380[31]) / 2 + 8 * v380[9] - 1, 0, v380[175]);
      v163 = v380[8];
      v164 = -12 * v163 + 3 * v380[24] / 2;
      sub_412A78(12 * v163, v380[5] + (-20 * v380[9] + v380[25] - v380[31]) / 2 + 20 * v380[9] - 1, 0, v380[175]);
      v165 = (-12 * v380[8] + 3 * v380[24] / 2) / 2;
      sub_412A78(0, v380[5] + (-20 * v380[9] + v380[25] - v380[31]) / 2, 20 * v380[9], v380[175]);
      v166 = (-12 * v380[8] + 3 * v380[24] / 2) / 2 + 2 * v380[8] - 1;
      sub_412A78(0, v380[5] + (v380[25] - v380[31] - 4 * v380[9]) / 2, 12 * v380[9], v380[175]);
      v167 = (-12 * v380[8] + 3 * v380[24] / 2) / 2 + 12 * v380[8] - 1;
      sub_412A78(0, v380[5] + (-20 * v380[9] + v380[25] - v380[31]) / 2, 20 * v380[9], v380[175]);
      goto LABEL_201;
    case 2:
      v168 = 0;
      sub_413658(this[7]);
      sub_41344A(v380[847], *(_DWORD *)(v380[272] + 4 * v380[295] + 4), 0, 0, v380[24], v380[7], v380[175], v380[174]);
      sub_413658(v380[30]);
      Dest = v169;
      v373 = (int)(v380 + 826);
      while ( 1 )
      {
        v170 = 0;
        do
        {
          sub_40CF70(v373, Dest);
          v171 = v168;
          if ( v168 > 0 )
            v171 = 1;
          if ( v168 == 1 )
          {
            if ( (v170 & 0xFFFFFFFD) == 1 )
              *(_BYTE *)(v380[835] + 129) = 1;
          }
          else if ( v168 == 2 )
          {
            if ( v170 == 1 )
            {
              *(_BYTE *)(v380[836] + 129) = 1;
              goto LABEL_99;
            }
          }
          else if ( (v170 & 0xFFFFFFFD) == 1 )
          {
            *(_BYTE *)(v380[838] + v171 + 128) = 1;
          }
          if ( v170 == 2 )
            *(_BYTE *)(v380[836] + v171 + 128) = 1;
LABEL_99:
          v172 = 2 * v170++;
          sub_413FCA(
            v373,
            v380[24] * (v172 + 1) / 8 - v380[8] * v380[826] / 2,
            (2 * v168 + 1) * (v380[25] - v380[31]) / 6 - v380[9] * v380[827] / 2,
            v171);
        }
        while ( v170 != 4 );
        if ( ++v168 == 3 )
        {
          v362 = 2;
          v367 = 0;
          v346 = v408;
          do
          {
            v358 = 1;
            v374 = 0;
            v348 = v367 & 0xFFFFFFFD;
            do
            {
              v173 = v380[104];
              v174 = v380[97];
              v175 = v380[98];
              v176 = v380[103];
              v437 = v380[89];
              v447 = v437;
              v177 = v380[99];
              v178 = v380[100];
              v435 = v174;
              v445 = v175;
              v450 = v174;
              v436 = v173;
              v452 = v178;
              v438 = v176;
              v439 = v176;
              v440 = v176;
              v441 = v176;
              v442 = v176;
              v443 = v176;
              v444 = v176;
              v446 = v173;
              v448 = v176;
              v449 = v176;
              v451 = v173;
              v453 = v173;
              v454 = v177;
              v455 = v176;
              v456 = v176;
              v457 = v176;
              v458 = v176;
              v460 = v175;
              v462 = v178;
              v465 = v174;
              v467 = v175;
              v475 = v175;
              v477 = v174;
              v459 = v176;
              v461 = v173;
              v463 = v173;
              v464 = v177;
              v466 = v173;
              v468 = v176;
              v469 = v176;
              v470 = v176;
              v471 = v176;
              v472 = v176;
              v473 = v176;
              v474 = v176;
              v476 = v173;
              v478 = v176;
              v479 = v176;
              qmemcpy(v408, &unk_418220, 0x24u);
              if ( !v348 )
              {
                v179 = v380;
                v180 = v380[25];
                v181 = v380[9];
                if ( v374 == 2 )
                {
                  v179 = v380;
                  v187 = v380[5] + -3 * v181 + 5 * (v180 - v380[31]) / 6;
                  v188 = v380[24] * v362 / 8;
                  v189 = v380[34] / 2;
                  v190 = v380[152];
                }
                else
                {
                  v182 = v380[5] + -3 * v181 + v358 * (v180 - v380[31]) / 6;
                  v183 = v380[24] * v362 / 8;
                  v184 = v380[34] / 2;
                  v185 = v380[151];
                }
                sub_412826(v179[173]);
              }
              v186 = 0;
              v343 = 12 * v374;
              while ( 1 )
              {
                v353 = *(_DWORD *)&v346[v343];
                if ( v186 >= *(_DWORD *)&v346[v343] )
                  break;
                v191 = v380[9];
                v192 = v380[25];
                if ( *(&v435 + 15 * v374 + 5 * v367 + v186) == v380[104] )
                {
                  v193 = v380[5] + v380[35] + v358 * (v192 - v380[31]) / 6 - 3 * v191;
                  v194 = v380[8] * (2 * v186 - v353) / 2 + v380[24] * v362 / 8;
                  v195 = v380[173];
                }
                else
                {
                  v196 = v380[5] + v380[35] + v358 * (v192 - v380[31]) / 6 - 3 * v191;
                  v197 = v380[8] * (2 * v186 - v353) / 2 + v380[24] * v362 / 8;
                  v195 = v380[174];
                }
                ++v186;
                sub_412826(v195);
              }
              if ( !v348 )
              {
                v198 = v380[9];
                v199 = v380[25] - v380[31];
                sub_41344A(
                  v380[847],
                  *(_DWORD *)(v380[272] + 4 * ((v367 >> 1) + v380[294] + 2 * v374)),
                  (v367 >> 1) * v380[24] / 2,
                  v380[5] + v380[35] + -3 * v198 + v199 * v358 / 6 + v198,
                  v380[24] / 2,
                  2 * v198 + v199 / 6 - v380[35],
                  v380[175],
                  v380[174]);
              }
              ++v374;
              v358 += 2;
            }
            while ( v374 != 3 );
            ++v367;
            v346 += 4;
            v362 += 2;
          }
          while ( v367 != 3 );
          v200 = 1;
          v201 = v380[24] / 2;
          sub_412A78(0, v380[5], v380[25] - v380[31], v380[180]);
          do
          {
            v202 = v200++ * (v380[25] - v380[31]);
            sub_412A78(v380[24], v380[5] + v202 / 3, 0, v380[180]);
          }
          while ( v200 != 3 );
LABEL_200:
          sub_413658(v380[28]);
          goto LABEL_201;
        }
      }
    case 3:
      v203 = 0;
      sub_413658(this[7]);
      sub_41344A(v380[847], *(_DWORD *)(v380[272] + 4 * v380[295] + 8), 0, 0, v380[24], v380[7], v380[175], v380[174]);
      Desta = (char *)sub_413658(v380[30]);
      v375 = (int)(v380 + 826);
      while ( 1 )
      {
        v204 = 0;
        do
        {
          sub_40CF70(v375, Desta);
          *(_BYTE *)(v380[838] + 128) = 1;
          *(_BYTE *)(v380[835] + 129) = 1;
          if ( v203 == 1 )
          {
            *(_BYTE *)(v380[835] + 129) = 1;
            if ( v204 )
            {
              *(_BYTE *)(v380[838] + 2) = 1;
              *(_BYTE *)(v380[838] + 3) = 1;
              if ( v204 != 2 )
                goto LABEL_139;
              v206 = v380[835];
            }
            else
            {
              v206 = v380[836];
            }
            *(_BYTE *)(v206 + 1) = 1;
            goto LABEL_139;
          }
          if ( v203 == 2 )
          {
            *(_BYTE *)(v380[835] + 129) = 1;
            if ( !v204 )
            {
              v207 = v380[836];
              goto LABEL_138;
            }
            *(_BYTE *)(v380[838] + 2) = 1;
            *(_BYTE *)(v380[835] + 1) = 1;
            if ( v204 == 2 )
            {
              v207 = v380[838];
LABEL_138:
              *(_BYTE *)(v207 + 3) = 1;
            }
LABEL_139:
            v205 = 2;
            goto LABEL_140;
          }
          v205 = 2;
          if ( v204 > 1 || (v205 = 0, v204) )
          {
            *(_BYTE *)v380[835] = 1;
            *(_BYTE *)(v380[835] + 1) = 1;
            if ( v204 == 3 )
            {
              *(_BYTE *)(v380[838] + 2) = 1;
              *(_BYTE *)(v380[838] + 3) = 1;
            }
          }
          else
          {
            *(_BYTE *)(v380[836] + 1) = 1;
            v205 = 0;
          }
LABEL_140:
          if ( !v203 || v204 <= 2 )
            sub_413FCA(
              v375,
              v380[24] * (2 * v204 + (v203 != 0) + 1) / 8 - v380[8] * v380[826] / 2,
              (2 * v203 + 1) * (v380[25] - v380[31]) / 6 - v380[9] * v380[827] / 2,
              v205);
          ++v204;
        }
        while ( v204 != 4 );
        if ( ++v203 == 3 )
        {
          v354 = 2;
          v368 = 0;
          v349 = v408;
          while ( 1 )
          {
            v363 = 1;
            v376 = 0;
            do
            {
              memset(&v435, 0, 0xF0u);
              v208 = v380[99];
              v209 = v380[105];
              v210 = v380[98];
              v211 = v380[97];
              v212 = v380[89];
              v447 = v380[88];
              v437 = v208;
              v445 = v208;
              v435 = v211;
              v436 = v210;
              v439 = v212;
              v455 = v210;
              v456 = v208;
              v460 = v211;
              v438 = v209;
              v213 = v380[103];
              v446 = v209;
              v457 = v209;
              v458 = v447;
              v440 = v213;
              v441 = v213;
              v442 = v213;
              v443 = v213;
              v444 = v213;
              v448 = v213;
              v449 = v213;
              v459 = v213;
              v461 = v210;
              v462 = v208;
              v475 = v210;
              v476 = v208;
              v480 = v208;
              v463 = v209;
              v464 = v447;
              v465 = v213;
              v466 = v213;
              v467 = v213;
              v468 = v213;
              v469 = v213;
              v477 = v209;
              v478 = v447;
              v479 = v213;
              v481 = v209;
              v482 = v447;
              v483 = v213;
              v484 = v213;
              v485 = v213;
              v486 = v213;
              v487 = v213;
              v488 = v213;
              v489 = v213;
              qmemcpy(v408, &unk_418260, 0x24u);
              if ( v368 && (v368 != 2 || v376) )
              {
                if ( v368 != 1 || !v376 )
                  goto LABEL_152;
                v214 = v380;
                v220 = v380[5] + -3 * v380[9] + v363 * (v380[25] - v380[31]) / 6;
                v221 = 5 * v380[24] / 8;
                v222 = v380[34] / 2;
                v223 = v380[153];
              }
              else
              {
                v214 = v380;
                v215 = v380[5] + -3 * v380[9] + v363 * (v380[25] - v380[31]) / 6;
                v216 = v380[24] * (v354 + (v376 != 0)) / 8;
                v217 = v380[34] / 2;
                v218 = v380[154];
              }
              sub_412826(v214[173]);
LABEL_152:
              v219 = 0;
              v379 = v354 + (v376 != 0);
              v344 = 12 * v376;
              while ( 1 )
              {
                v359 = *(_DWORD *)&v349[v344];
                if ( v219 >= *(_DWORD *)&v349[v344] )
                  break;
                v224 = v380[9];
                v225 = v380[25];
                if ( *(&v435 + 20 * v376 + 5 * v368 + v219) == v380[105] )
                {
                  v226 = v380[5] + v380[35] + v363 * (v225 - v380[31]) / 6 - 3 * v224;
                  v227 = v380[8] * (2 * v219 - v359) / 2 + v380[24] * v379 / 8;
                  v228 = v380[173];
                }
                else
                {
                  v229 = v380[5] + v380[35] + v363 * (v225 - v380[31]) / 6 - 3 * v224;
                  v230 = v380[8] * (2 * v219 - v359) / 2 + v380[24] * v379 / 8;
                  v228 = v380[174];
                }
                ++v219;
                sub_412826(v228);
              }
              if ( ~(_BYTE)v368 & 1 && !v376 )
              {
                v231 = v380[9];
                v232 = (v380[25] - v380[31]) / 6 + 2 * v231;
                sub_41344A(
                  v380[847],
                  *(_DWORD *)(v380[272] + 4 * (v380[294] + (v368 >> 1)) + 24),
                  v380[24] * (v368 >> 1) / 2,
                  v380[5] + v380[35] + v232 - 5 * v231 + v231,
                  v380[24] / 2,
                  v232 - v380[35],
                  v380[175],
                  v380[174]);
              }
              if ( v376 > 0 && v368 == 0 )
              {
                v233 = v380[25] - v380[31];
                sub_41344A(
                  v380[847],
                  *(_DWORD *)(v380[272] + 4 * (v380[294] + v376) + 28),
                  0,
                  v380[5] + -3 * v380[9] + v233 * v363 / 6 + v380[35] + v380[9],
                  v380[24],
                  2 * v380[9] + v233 / 6 - v380[35],
                  v380[175],
                  v380[174]);
              }
              ++v376;
              v363 += 2;
            }
            while ( v376 != 3 );
            ++v368;
            v349 += 4;
            v354 += 2;
            if ( v368 == 3 )
            {
              v234 = v380[24] / 2;
              v235 = 1;
              sub_412A78(0, v380[5], (v380[25] - v380[31]) / 3, v380[180]);
              do
              {
                v236 = v235++ * (v380[25] - v380[31]);
                sub_412A78(v380[24], v380[5] + v236 / 3, 0, v380[180]);
              }
              while ( v235 != 3 );
              goto LABEL_201;
            }
          }
        }
      }
    case 4:
      sub_413658(this[7]);
      sub_41344A(v380[847], *(_DWORD *)(v380[272] + 4 * v380[295] + 12), 0, 0, v380[24], v380[7], v380[175], v380[174]);
      sub_413658(v380[30]);
      sub_40F528(v380[101], 2, 20 * v380[8], v380[5] + 2 * v380[9]);
      sub_40F528(v380[97], 12, 20 * v380[8], v380[5] + 3 * v380[9]);
      sub_40F528(v380[97], 12, 20 * v380[8], v380[5] + 4 * v380[9]);
      sub_40F528(v380[101], 2, 5 * v380[8], v380[5] + 4 * v380[9]);
      sub_40F5F2(v380[97], v380[100], v380[87], v380[103], 5, 1, 1, 5, 5 * v380[8], v380[5] + 5 * v380[9]);
      sub_40F5F2(v380[97], v380[99], v380[87], v380[103], 5, 1, 1, 5, 20 * v380[8], v380[5] + 5 * v380[9]);
      v237 = v380[5] + 5 * v380[9];
      v238 = 18 * v380[8];
      v239 = v380[104];
      sub_412826(v380[173]);
      v240 = v380[8];
      v241 = v380[5] + 4 * v380[9] - v380[7] / 2;
      v242 = v380[6];
      v243 = 10;
      v244 = v380[79];
      sub_412826(v380[173]);
      v245 = 0;
      sub_41344A(
        v380[847],
        *(_DWORD *)(v380[272] + 4 * v380[294] + 40),
        0,
        v380[5] + 6 * v380[9],
        v380[24],
        2 * v380[9],
        v380[175],
        v380[174]);
      do
      {
        sub_40F528(v380[101], 2, 5 * v380[8], v380[5] + v243 * v380[9]);
        sub_40F528(v380[101], v245 + 3, 20 * v380[8], v380[5] + v243 * v380[9]);
        sub_40F528(v380[97], 12, 5 * v380[8], v380[5] + (v243 + 1) * v380[9]);
        sub_40F528(v380[97], 12, 20 * v380[8], v380[5] + (v243 + 1) * v380[9]);
        sub_40FA06(5 * v245, 2, 34 * v380[8], v380[5] + (v243 + 1) * v380[9] - v380[13] / 2, 0);
        v246 = 18 * v380[8];
        v247 = __CFADD__(v380[5], v380[9] * (v243 + 1));
        v248 = v380[104];
        sub_412826(v380[173]);
        ++v245;
        v243 += 3;
      }
      while ( v245 != 3 );
      sub_41344A(
        v380[847],
        *(_DWORD *)(v380[272] + 4 * v380[294] + 44),
        0,
        v380[5] + 18 * v380[9],
        v380[24],
        v380[9] + v380[9] / 2,
        v380[175],
        v380[174]);
      sub_40F528(v380[101], 12, 5 * v380[8], v380[5] + 21 * v380[9]);
      sub_40F528(v380[97], 12, 20 * v380[8], v380[5] + 21 * v380[9]);
      sub_40F528(v380[97], 12, 5 * v380[8], v380[5] + 22 * v380[9]);
      sub_40F528(v380[97], 12, 20 * v380[8], v380[5] + 22 * v380[9]);
      v249 = 18 * v380[8];
      v247 = __CFADD__(v380[5], 22 * v380[9]);
      v250 = v380[104];
      sub_412826(v380[173]);
      sub_41344A(
        v380[847],
        *(_DWORD *)(v380[272] + 4 * v380[294] + 48),
        0,
        23 * v380[9] + v380[5],
        v380[24],
        v380[25] - v380[31] - 23 * v380[9],
        v380[175],
        v380[174]);
      sub_412A78(v380[24], v380[5] + 8 * v380[9], 0, v380[180]);
      v251 = v380[24];
      v252 = v380[5] + 19 * v380[9] + v380[9] / 2;
      v253 = v380;
      goto LABEL_185;
    case 5:
      sub_413658(this[7]);
      sub_41344A(v380[847], *(_DWORD *)(v380[272] + 4 * v380[295] + 16), 0, 0, v380[24], v380[7], v380[175], v380[174]);
      sub_413658(v380[30]);
      sub_40F566(v380[97], v380[88], v380[103], 4, 1, 7, 3 * v380[8], v380[5] + 2 * v380[9] - v380[9] / 2);
      sub_40F5F2(v380[97], v380[99], v380[88], v380[103], 2, 2, 1, 7, 3 * v380[8], v380[5] + 3 * v380[9] - v380[9] / 2);
      sub_414046(
        v380[97],
        v380[99],
        v380[89],
        v380[87],
        v380[103],
        2,
        1,
        3 * v380[8],
        v380[5] + 4 * v380[9] - v380[9] / 2);
      sub_40F566(v380[97], v380[87], v380[103], 4, 1, 7, 20 * v380[8], v380[5] + 3 * v380[9] - v380[9] / 2);
      sub_414046(
        v380[97],
        v380[99],
        v380[89],
        v380[87],
        v380[103],
        2,
        1,
        20 * v380[8],
        v380[5] + 4 * v380[9] - v380[9] / 2);
      sub_412A78(12 * v380[8], v380[5] + 3 * v380[9], 0, v380[177]);
      v254 = v380[5] + 4 * v380[9] - v380[9] / 2;
      v255 = v380[8];
      v256 = v380[99];
      sub_412826(v380[174]);
      v257 = 17 * v380[8];
      v247 = __CFADD__(v380[5], 4 * v380[9] - v380[9] / 2);
      v258 = v380[105];
      sub_412826(v380[173]);
      v259 = v380[5] + 4 * v380[9] - v380[9] / 2;
      v260 = 18 * v380[8];
      v261 = v380[102];
      sub_412826(v380[174]);
      v262 = v380[8];
      v263 = v380[5] + 4 * v380[9] - v380[9] / 2 - v380[9] - v380[7] / 2;
      v264 = v380[6];
      v265 = v380[80];
      sub_412826(v380[174]);
      sub_40FA06(1, 4, 34 * v380[8], v380[5] + 4 * v380[9] - v380[9] / 2 - v380[13] / 2, 0);
      sub_41344A(
        v380[847],
        *(_DWORD *)(v380[272] + 4 * v380[294] + 52),
        0,
        v380[5] + 5 * v380[9] - v380[9] / 2,
        v380[24],
        3 * v380[9] / 2,
        v380[175],
        v380[174]);
      sub_40F566(v380[97], v380[88], v380[103], 4, 1, 7, 3 * v380[8], v380[5] + 6 * v380[9]);
      sub_414046(v380[87], v380[90], v380[97], v380[88], v380[103], 1, 2, 3 * v380[8], v380[5] + 7 * v380[9]);
      sub_414046(v380[97], v380[97], v380[89], v380[87], v380[103], 2, 1, 3 * v380[8], v380[5] + 8 * v380[9]);
      sub_40F566(v380[97], v380[87], v380[103], 4, 1, 7, 20 * v380[8], v380[5] + 7 * v380[9]);
      sub_40F5F2(v380[97], v380[89], v380[87], v380[103], 3, 1, 1, 7, 20 * v380[8], v380[5] + 8 * v380[9]);
      sub_412A78(12 * v380[8], v380[5] + 7 * v380[9] + v380[9] / 2, 0, v380[177]);
      v266 = v380[5] + 8 * v380[9];
      v267 = v380[8];
      v268 = v380[97];
      sub_412826(v380[174]);
      v269 = v380[5] + 8 * v380[9];
      v270 = 17 * v380[8];
      v271 = v380[105];
      sub_412826(v380[173]);
      v272 = v380[5] + 8 * v380[9];
      v273 = 18 * v380[8];
      v274 = v380[102];
      sub_412826(v380[174]);
      v275 = v380[8];
      v276 = v380[5] + 8 * v380[9] - v380[9] - v380[7] / 2;
      v277 = v380[6];
      v278 = v380[80];
      sub_412826(v380[174]);
      sub_40FA06(1, 4, 34 * v380[8], v380[5] + 8 * v380[9] - v380[13] / 2, 0);
      sub_41344A(
        v380[847],
        *(_DWORD *)(v380[272] + 4 * v380[294] + 56),
        0,
        v380[5] + 9 * v380[9],
        v380[24],
        3 * v380[9] / 2,
        v380[175],
        v380[174]);
      sub_40F528(v380[103], 12, 3 * v380[8], v380[5] + 15 * v380[9] - v380[9] / 2);
      v279 = 0;
      sub_412A78(12 * v380[8], v380[5] + 15 * v380[9], 0, v380[177]);
      break;
    case 6:
      sub_413658(this[7]);
      v293 = 4;
      sub_41344A(v380[847], *(_DWORD *)(v380[272] + 4 * v380[295] + 20), 0, 0, v380[24], v380[7], v380[175], v380[174]);
      sub_413658(v380[30]);
      do
      {
        v294 = 0;
        do
        {
          v295 = v380[5] + v380[9] / 2;
          ++v294;
          v296 = v293 * v380[8];
          v297 = v380[103];
          sub_412826(v380[173]);
        }
        while ( v294 != 24 );
        ++v293;
      }
      while ( v293 != 36 );
      v298 = 0;
      do
      {
        v299 = v298 + 1;
        v300 = v380[9] * (v298 + 1) + v380[5] + v380[9] / 2 - v380[9];
        if ( v298 <= 0xB )
        {
          v304 = 2;
          v305 = 0;
        }
        else
        {
          v303 = __OFSUB__(v298, 15);
          v301 = v298 == 15;
          v302 = (signed int)(v298 - 15) < 0;
          v304 = 3;
          v305 = 3 * !((unsigned __int8)(v302 ^ v303) | v301);
        }
        sub_40F528(v380[102], v304 + v305, 5 * v380[8], v300);
        v298 = v299;
      }
      while ( v299 != 24 );
      v306 = 0;
      do
      {
        v307 = v380[5] + v380[9] / 2 + v306 * v380[9];
        v308 = v380[8];
        v309 = v306++;
        LODWORD(v309) = v380[(unsigned int)(v309 % 10) + 87];
        sub_412826(v380[174]);
      }
      while ( v306 != 24 );
      v310 = 0;
      do
      {
        v311 = v380[5] + v380[9] / 2;
        v312 = v380[8] * (v310 + 4);
        v313 = v310++;
        v314 = v380[v313 % 10 + 87];
        sub_412826(v380[174]);
      }
      while ( v310 != 32 );
      v315 = v380[9];
      v247 = (unsigned int)(16 * v380[8]) < v380[4];
      v316 = v380[41];
      sub_412826(v380[174]);
      v317 = v380[9];
      v247 = (unsigned int)(20 * v380[8]) < v380[4];
      v318 = v380[43];
      sub_412826(v380[174]);
      v319 = v380[9];
      v247 = (unsigned int)(36 * v380[8]) < v380[4];
      v320 = v380[45];
      sub_412826(v380[174]);
      sub_412A78(12 * v380[8], v380[5] + v380[9] / 2 + 12 * v380[9] - 1, 0, v380[175]);
      sub_412A78(16 * v380[8], v380[5] + v380[9] / 2 + 16 * v380[9] - 1, 0, v380[175]);
      sub_412A78(32 * v380[8], v380[5] + v380[9] / 2 + 24 * v380[9] - 1, 0, v380[175]);
      sub_412A78(32 * v380[8], v380[5] + v380[9] / 2 - 1, 0, v380[175]);
      v321 = v380[8];
      sub_412A78(0, v380[5] + v380[9] / 2, 12 * v380[9], v380[175]);
      v322 = 20 * v380[8];
      sub_412A78(0, v380[5] + v380[9] / 2, 16 * v380[9], v380[175]);
      v323 = 36 * v380[8] - 1;
      sub_412A78(0, v380[5] + v380[9] / 2, 24 * v380[9], v380[175]);
      v324 = 4 * v380[8] - 1;
      sub_412A78(0, v380[5] + v380[9] / 2, 24 * v380[9], v380[175]);
      sub_413552(
        v380[847],
        *(_DWORD *)(v380[272] + 4 * v380[294] + 68),
        5 * v380[8],
        12 * v380[9] + v380[5] + v380[9] / 2 - v380[30] - 1,
        15 * v380[8] - v380[4],
        v380[30],
        v380[175],
        v380[173],
        0);
      sub_413552(
        v380[847],
        *(_DWORD *)(v380[272] + 4 * v380[294] + 72),
        5 * v380[8],
        16 * v380[9] + v380[5] + v380[9] / 2 - v380[30] - 1,
        15 * v380[8] - v380[4],
        v380[30],
        v380[175],
        v380[173],
        0);
      sub_413552(
        v380[847],
        *(_DWORD *)(v380[272] + 4 * v380[294] + 76),
        5 * v380[8],
        24 * v380[9] + v380[5] + v380[9] / 2 - v380[30] - 1,
        15 * v380[8] - v380[4],
        v380[30],
        v380[175],
        v380[173],
        0);
      goto LABEL_200;
    default:
      goto LABEL_201;
  }
  while ( v279 <= 4 )
  {
    if ( v279 )
      goto LABEL_180;
LABEL_181:
    if ( ++v279 == 8 )
    {
      v280 = 17 * v380[8];
      v247 = __CFADD__(v380[5], 18 * v380[9] - v380[9] / 2);
      v281 = v380[104];
      sub_412826(v380[173]);
      v282 = v380[8];
      v283 = v380[5] + 18 * v380[9] - v380[9] / 2 - v380[9] - v380[7] / 2;
      v284 = v380[6];
      v285 = v380[77];
      sub_412826(v380[173]);
      sub_40FA06(5, 4, 34 * v380[8], v380[5] + 18 * v380[9] - v380[9] / 2 - v380[13] / 2, 0);
      v286 = 2;
      sub_41344A(
        v380[847],
        *(_DWORD *)(v380[272] + 4 * v380[294] + 60),
        0,
        v380[5] + 19 * v380[9] - v380[9] / 2,
        v380[24],
        3 * v380[9] / 2,
        v380[175],
        v380[174]);
      do
      {
        v287 = 2 * v286 - 3;
        sub_40FA06(
          v286 * v286,
          4,
          v380[24] * v287 / 6 - 4 * v380[10] - v380[8] / 2,
          v380[5] + 22 * v380[9] - v380[13] / 2,
          0);
        sub_40FA06(
          v286++,
          2,
          v380[8] / 2 + v380[24] * v287 / 6 + 2 * v380[10],
          v380[5] + 22 * v380[9] - v380[13] / 2,
          0);
        v288 = v380[5] + 22 * v380[9] - v380[9] / 2;
        v289 = v380[10] + v380[24] * v287 / 6;
        v290 = v380[8] / 2;
        v291 = v380[104];
        sub_412826(v380[173]);
      }
      while ( v286 != 5 );
      v292 = 22 * v380[9] + v380[13] / 2;
      sub_41344A(
        v380[847],
        *(_DWORD *)(v380[272] + 4 * v380[294] + 64),
        0,
        v380[5] + v292,
        v380[24],
        v380[25] - v380[31] - v292,
        v380[175],
        v380[174]);
      sub_412A78(v380[24], v380[5] + 10 * v380[9] + v380[9] / 2, 0, v380[180]);
      v253 = v380;
      v251 = v380[24];
      v252 = v380[5] + 20 * v380[9];
LABEL_185:
      sub_412A78(v251, v252, 0, v253[180]);
      goto LABEL_200;
    }
  }
  sub_40F528(v380[97], 12, 3 * v380[8], v380[5] + v380[9] * (v279 + 11) - v380[9] / 2);
LABEL_180:
  sub_40F528(v380[97], 12, 20 * v380[8], v380[5] + v380[9] * (v279 + 11) - v380[9] / 2);
  goto LABEL_181;
}


// Address: 0x0040BAC0; symbol: sub_40BAC0
void __thiscall sub_40BAC0(int this)
{
  int v1; // ebx
  bool v2; // zf
  int v3; // eax

  v1 = this;
  if ( *(_DWORD *)(this + 20) )
  {
    if ( *(_DWORD *)(this + 20) >= 0 )
      goto LABEL_12;
  }
  else if ( *(_DWORD *)(this + 24) <= 0 )
  {
    goto LABEL_12;
  }
  if ( *(_DWORD *)(this + 12) <= 3 && !*(_BYTE *)(this + 2436) )
  {
    sub_40E540(*(_DWORD *)(this + 2156) - *(_DWORD *)(this + 2196), *(_DWORD *)(this + 2128), *(_DWORD *)(this + 696));
    v2 = *(_BYTE *)(v1 + 2176) == 0;
    v3 = *(_DWORD *)(v1 + 2156);
    *(_BYTE *)(v1 + 2144) = 0;
    *(_DWORD *)(v1 + 12) = 4;
    *(_DWORD *)(v1 + 2196) = v3;
    if ( !v2 )
      *(_BYTE *)(*(_DWORD *)(v1 + 48) + (*(_DWORD *)(v1 + 2180) << 7) + *(_DWORD *)(v1 + 2184)) = 1;
    sub_40EA0C(*(_DWORD *)(v1 + 2056));
    if ( !*(_DWORD *)(v1 + 2140) )
      sub_40E31E(*(_DWORD *)(v1 + 456));
    sub_40E822(*(_DWORD *)(v1 + 2128));
  }
LABEL_12:
  if ( *(_DWORD *)(v1 + 20) || *(_DWORD *)(v1 + 24) || *(_DWORD *)(v1 + 12) > 3 )
  {
    if ( *(_BYTE *)(v1 + 2144) )
      sub_40E31E(*(_DWORD *)(v1 + 460));
  }
  else
  {
    *(_BYTE *)(v1 + 2144) = 1;
  }
}


// Address: 0x0040BBDE; symbol: sub_40BBDE
int __thiscall sub_40BBDE(signed int *this)
{
  signed int *v1; // ebx
  signed int v2; // edx
  signed int v3; // eax
  signed int v4; // eax
  signed int v5; // ecx
  int v6; // ecx
  int v7; // edx
  int v8; // edx
  bool v9; // zf
  int i; // ecx
  int v11; // eax
  int v12; // edx
  int v13; // esi
  int result; // eax
  int v15[10]; // [esp+20h] [ebp-28h]

  v1 = this;
  sub_40E822(this[532]);
  v2 = v1[554];
  v1[3] = 0;
  v1[539] = 0;
  v1[540] = 0;
  v1[547] = 0;
  v1[548] = 0;
  v1[549] = 0;
  v1[551] = 0;
  if ( v2 > 128 )
    v2 = 128;
  v3 = *v1;
  if ( *v1 < 12 )
    v3 = 12;
  if ( v2 > v3 )
    v2 = v3;
  v4 = v1[1];
  *v1 = v2;
  if ( v4 < 8 )
    v4 = 8;
  v5 = v1[555];
  if ( v5 > 128 )
    v5 = 128;
  if ( v4 > v5 )
    v4 = v5;
  v6 = v1[2];
  v7 = v2 - 1;
  v1[1] = v4;
  if ( v7 > v6 )
    v7 = v6;
  if ( v7 <= 0 )
    v7 = 1;
  v1[2] = v7;
  v8 = v1[537];
  if ( v4 - 3 <= v8 )
    v8 = v4 - 4;
  v9 = *((_BYTE *)v1 + 2436) == 0;
  v1[5] = v8;
  if ( !v9 )
    v1[5] = 1;
  v1[6] = 0;
  *((_BYTE *)v1 + 2152) = 0;
  for ( i = 0; i < *v1; ++i )
  {
    v11 = 0;
    v12 = i << 7;
    while ( v11 < v1[1] )
    {
      *(_BYTE *)(v11 + v1[11] + v12) = i < v1[2];
      *(_BYTE *)(v11 + v1[9] + v12) = 0;
      *(_BYTE *)(v11 + v1[15] + v12) = 0;
      *(_BYTE *)(v11 + v1[16] + v12) = 0;
      *(_BYTE *)(v11 + v1[10] + v12) = 0;
      *(_BYTE *)(v11 + v1[12] + v12) = 0;
      *(_BYTE *)(v11 + v1[13] + v12) = v11 < v1[5];
      v13 = v1[14] + 4 * v11++;
      *(_DWORD *)(v13 + (i << 9)) = 0;
    }
  }
  sub_40EA0C(v1[519]);
  result = v1[532];
  qmemcpy(v15, &unk_418518, 0x10u);
  v1[533] |= v15[result];
  if ( !result )
    result = sub_40E31E(v1[107]);
  if ( v1[533] == 7 )
    result = sub_40E31E(v1[108]);
  v1[535] = 0;
  v1[569] = 0;
  v1[568] = 0;
  v1[543] = 0;
  v1[4] = 0;
  v1[566] = -1;
  v1[567] = -1;
  v1[550] = 0;
  v1[633] = 0;
  return result;
}


// Address: 0x0040BE12; symbol: sub_40BE12
BOOL __thiscall sub_40BE12(signed int *this, signed int a2, signed int a3)
{
  signed int *v3; // ebx
  BOOL result; // eax

  v3 = this;
  sub_40E822(this[532]);
  v3[532] = a2;
  switch ( a2 )
  {
    case 2:
      *v3 = 16;
      v3[1] = 24;
      v3[2] = 3;
      goto LABEL_7;
    case 3:
      *v3 = 32;
      v3[1] = 32;
      v3[2] = 6;
      goto LABEL_7;
    case 1:
      *v3 = 12;
      v3[1] = 20;
      v3[2] = 2;
LABEL_7:
      v3[537] = 8;
      sub_40BBDE(v3);
      break;
  }
  result = a3 <= 1;
  v3[564] = result;
  return result;
}


// Address: 0x0040BEAE; symbol: sub_40BEAE
char __thiscall sub_40BEAE(_DWORD *this, int a2, int a3, int a4, int *a5, int *a6)
{
  char result; // al
  bool v7; // zf
  bool v8; // sf
  int v9; // eax
  bool v10; // sf
  unsigned __int8 v11; // of
  int v12; // eax
  bool v13; // cl

  result = a2;
  switch ( a2 )
  {
    case 0:
      v7 = a3 == 0;
      v8 = a3 < 0;
      *a5 = a3 - 1;
      *a6 = a4;
      return !v8 && !v7;
    case 1:
      *a5 = a3 + 1;
      *a6 = a4;
      v9 = *this - 1;
      v11 = __OFSUB__(a3, v9);
      v10 = a3 - v9 < 0;
      return v10 ^ v11;
    case 2:
      *a5 = a3;
      v7 = a4 == 0;
      v8 = a4 < 0;
      *a6 = a4 - 1;
      return !v8 && !v7;
    case 3:
      *a5 = a3;
      *a6 = a4 + 1;
      v12 = this[1] - 1;
      v11 = __OFSUB__(a4, v12);
      v10 = a4 - v12 < 0;
      return v10 ^ v11;
    case 4:
      v13 = a3 > 0;
      *a5 = a3 - 1;
      *a6 = a4 - 1;
      return v13 && a4 > 0;
    case 5:
      *a5 = a3 - 1;
      *a6 = a4 + 1;
      if ( a3 <= 0 )
        goto LABEL_10;
      goto LABEL_12;
    case 6:
      *a5 = a3 + 1;
      *a6 = a4 - 1;
      v13 = a3 < *this - 1;
      return v13 && a4 > 0;
    case 7:
      *a5 = a3 + 1;
      *a6 = a4 + 1;
      if ( a3 >= *this - 1 )
        goto LABEL_10;
LABEL_12:
      if ( a4 >= this[1] - 1 )
LABEL_10:
        result = 0;
      else
        result = 1;
      break;
    default:
      return result;
  }
  return result;
}


// Address: 0x0040BF70; symbol: sub_40BF70
char __thiscall sub_40BF70(int this, int a2, int a3, char a4)
{
  int v4; // ebx
  unsigned int v5; // eax
  int *v6; // edx
  int v7; // edi
  int v8; // esi
  int *v9; // ST24_4
  char v10; // al
  char v11; // si
  int v12; // ecx
  int v13; // edx
  int v14; // edi
  int v16; // [esp+2Ch] [ebp-1Ch]

  v4 = this;
  *(_BYTE *)(this + 2136) = a4;
  if ( a4 )
    *(_DWORD *)(this + 2140) = 1;
  v5 = *(_DWORD *)(this + 12) - 1;
  if ( v5 <= 2 && !*(_DWORD *)(this + 16) )
    LOBYTE(v5) = sub_411FFA(a2, a3);
  if ( !*(_DWORD *)(v4 + 2260) || *(_DWORD *)(v4 + 2272) == 1 )
  {
    if ( (unsigned int)(*(_DWORD *)(v4 + 12) - 1) <= 2 && !*(_DWORD *)(v4 + 16) )
      sub_411FFA(a2, a3);
    v5 = *(_DWORD *)(v4 + 12) - 1;
    if ( v5 <= 2 )
    {
      v5 = *(_DWORD *)(v4 + 16);
      v16 = *(_DWORD *)(v4 + 16);
      if ( !v5 )
      {
        v6 = (int *)(v4 + 28);
        v7 = 0;
        v8 = 0;
        do
        {
          v9 = v6;
          v10 = sub_40BEAE((_DWORD *)v4, v8, a2, a3, v6, (int *)(v4 + 32));
          v6 = v9;
          if ( v10 )
            v7 += *(_BYTE *)(*(_DWORD *)(v4 + 48) + (*(_DWORD *)(v4 + 28) << 7) + *(_DWORD *)(v4 + 32)) < 1u;
          ++v8;
        }
        while ( v8 != 8 );
        v5 = *(_DWORD *)(v4 + 56) + (a2 << 9);
        if ( *(_DWORD *)(v5 + 4 * a3) == v7 )
        {
          v11 = 0;
          do
          {
            LOBYTE(v5) = sub_40BEAE((_DWORD *)v4, v16, a2, a3, (int *)(v4 + 28), (int *)(v4 + 32));
            if ( (_BYTE)v5 )
            {
              v12 = *(_DWORD *)(v4 + 32);
              v13 = *(_DWORD *)(v4 + 28) << 7;
              if ( !*(_BYTE *)(v13 + *(_DWORD *)(v4 + 48) + v12) )
              {
                v14 = v13 + *(_DWORD *)(v4 + 36);
                if ( !*(_BYTE *)(v14 + v12) && !*(_BYTE *)(*(_DWORD *)(v4 + 52) + v13 + v12) )
                {
                  *(_BYTE *)(v14 + v12) = 1;
                  v11 = v5;
                  *(_BYTE *)(*(_DWORD *)(v4 + 40) + (*(_DWORD *)(v4 + 28) << 7) + *(_DWORD *)(v4 + 32)) = 0;
                }
              }
            }
            ++v16;
          }
          while ( v16 != 8 );
          if ( *(_BYTE *)(v4 + 2136) )
          {
            LOBYTE(v5) = v11;
            if ( v11 )
            {
              LOBYTE(v5) = sub_40EA0C(*(_DWORD *)(v4 + 2072));
              *(_BYTE *)(v4 + 2136) = 0;
            }
          }
        }
      }
    }
  }
  return v5;
}


// Address: 0x0040C132; symbol: sub_40C132
void __thiscall sub_40C132(int this)
{
  bool v1; // zf
  bool v2; // sf
  unsigned __int8 v3; // of
  int *v4; // ebx
  int v5; // edi
  int i; // esi
  int v7; // esi
  int v8; // edx
  int v9; // eax
  int v10; // edi
  int v11; // ST18_4
  int v12; // ST1C_4

  v3 = __OFSUB__(*(_DWORD *)(this + 12), 3);
  v1 = *(_DWORD *)(this + 12) == 3;
  v2 = *(_DWORD *)(this + 12) - 3 < 0;
  *(_BYTE *)(this + 2166) = 0;
  if ( (unsigned __int8)(v2 ^ v3) | v1 )
  {
    v4 = (int *)this;
    v5 = *(_DWORD *)(this + 16);
    if ( !v5 )
    {
      while ( *v4 > v5 )
      {
        for ( i = 2; v4[1] > i; ++i )
        {
          if ( *(_BYTE *)(i + v4[12] + (v5 << 7)) )
          {
            if ( *(_DWORD *)(v4[14] + 4 * i + (v5 << 9)) >= 0 )
              sub_40BF70((int)v4, v5, i, 0);
          }
        }
        ++v5;
      }
      v7 = *v4 - 1;
      v8 = v7 << 9;
      v9 = v7 << 7;
      while ( v7 >= 0 )
      {
        v10 = v4[1];
        while ( --v10 > 1 )
        {
          if ( *(_BYTE *)(v10 + v4[12] + v9) && *(_DWORD *)(v4[14] + 4 * v10 + v8) >= 0 )
          {
            v11 = v9;
            v12 = v8;
            sub_40BF70((int)v4, v7, v10, 0);
            v9 = v11;
            v8 = v12;
          }
        }
        --v7;
        v8 -= 512;
        v9 -= 128;
      }
      sub_40EA0C(v4[520]);
    }
  }
}


// Address: 0x0040C23C; symbol: sub_40C23C
void __thiscall sub_40C23C(_BYTE *this)
{
  int v1; // ebx
  bool v2; // zf
  bool v3; // sf
  unsigned __int8 v4; // of
  int v5; // edi
  int i; // esi
  int v7; // esi
  int v8; // edx
  int v9; // eax
  int v10; // edi
  int v11; // ST18_4
  int v12; // ST1C_4

  v1 = (int)this;
  this[2165] = 1;
  while ( *(_BYTE *)(v1 + 2165) )
  {
    v4 = __OFSUB__(*(_DWORD *)(v1 + 12), 3);
    v2 = *(_DWORD *)(v1 + 12) == 3;
    v3 = *(_DWORD *)(v1 + 12) - 3 < 0;
    *(_BYTE *)(v1 + 2165) = 0;
    if ( (unsigned __int8)(v3 ^ v4) | v2 )
    {
      v5 = *(_DWORD *)(v1 + 16);
      if ( !v5 )
      {
        while ( *(_DWORD *)v1 > v5 )
        {
          for ( i = 2; *(_DWORD *)(v1 + 4) > i; ++i )
          {
            if ( *(_BYTE *)(i + *(_DWORD *)(v1 + 48) + (v5 << 7)) )
            {
              if ( !*(_DWORD *)(*(_DWORD *)(v1 + 56) + 4 * i + (v5 << 9)) )
                sub_40BF70(v1, v5, i, 0);
            }
          }
          ++v5;
        }
        v7 = *(_DWORD *)v1 - 1;
        v8 = v7 << 9;
        v9 = v7 << 7;
        while ( v7 >= 0 )
        {
          v10 = *(_DWORD *)(v1 + 4);
          while ( --v10 > 1 )
          {
            if ( *(_BYTE *)(v10 + *(_DWORD *)(v1 + 48) + v9) && !*(_DWORD *)(*(_DWORD *)(v1 + 56) + 4 * v10 + v8) )
            {
              v11 = v9;
              v12 = v8;
              sub_40BF70(v1, v7, v10, 0);
              v9 = v11;
              v8 = v12;
            }
          }
          --v7;
          v8 -= 512;
          v9 -= 128;
        }
      }
    }
  }
}


// Address: 0x0040C342; symbol: sub_40C342
char __fastcall sub_40C342(int a1, int a2, char a3)
{
  _DWORD *v3; // eax
  int v4; // ebx
  bool v5; // zf
  int v6; // eax
  int v7; // edx
  int v8; // edx
  int v9; // ebx
  _DWORD *v10; // edx
  int *v11; // ebx
  int v12; // edi
  int v13; // esi
  int v14; // edx
  int v16; // [esp+14h] [ebp-20h]
  int *v17; // [esp+18h] [ebp-1Ch]
  int *v18; // [esp+1Ch] [ebp-18h]
  int v19; // [esp+24h] [ebp-10h]

  v3 = (_DWORD *)(*(_DWORD *)(a1 + 12) - 1);
  if ( (unsigned int)v3 <= 2 && !*(_DWORD *)(a1 + 16) )
  {
    v4 = *(_DWORD *)(a1 + 20);
    --*(_DWORD *)(a1 + 2200);
    v5 = *(_BYTE *)(a1 + 2436) == 0;
    *(_DWORD *)(a1 + 20) = v4 - 1;
    if ( !v5 && v4 - 1 <= 0 )
    {
      v6 = *(_DWORD *)(a1 + 2204) - 1;
      v7 = *(_DWORD *)(a1 + 2156) - 1;
      *(_DWORD *)(a1 + 2204) = v6;
      if ( v7 < 0 )
        v7 = 0;
      *(_DWORD *)(a1 + 2156) = v7;
      if ( a3 )
      {
        v8 = --*(_DWORD *)(a1 + 2196);
        if ( v8 < 0 )
          v8 = 0;
        *(_DWORD *)(a1 + 2196) = v8;
      }
      if ( v6 < 0 )
        v6 = 0;
      *(_DWORD *)(a1 + 2204) = v6;
      *(_DWORD *)(a1 + 20) = v4;
    }
    v9 = *(_DWORD *)(a1 + 20);
    v3 = 0;
    if ( v9 >= 0 )
    {
      while ( *(_DWORD *)a1 > (signed int)v3 )
      {
        v10 = v3;
        v3 = (_DWORD *)((char *)v3 + 1);
        *(_BYTE *)(*(_DWORD *)(a1 + 52) + ((_DWORD)v10 << 7) + v9) = 0;
      }
      v11 = (int *)a1;
      v12 = 0;
      v18 = (int *)(a1 + 32);
      LOBYTE(v3) = a1 + 28;
      v17 = (int *)(a1 + 28);
      while ( *v11 > v12 )
      {
        v13 = v11[5] + 1;
        LOBYTE(v3) = 0;
        v19 = v12 << 9;
        while ( v11[5] <= v13 )
        {
          *(_DWORD *)(4 * v13 + v11[14] + v19) = 0;
          v14 = 0;
          do
          {
            v16 = v14;
            LOBYTE(v3) = sub_40BEAE(v11, v14, v12, v13, v17, v18);
            if ( (_BYTE)v3 )
            {
              v3 = (_DWORD *)(v11[11] + (v11[7] << 7));
              if ( *((_BYTE *)v3 + v11[8]) )
              {
                v3 = (_DWORD *)(v11[14] + v19 + 4 * v13);
                ++*v3;
              }
            }
            v14 = v16 + 1;
          }
          while ( v16 != 7 );
          --v13;
        }
        ++v12;
      }
    }
    else
    {
      *(_BYTE *)(a1 + 2152) = 1;
    }
  }
  return (char)v3;
}


// Address: 0x0040C498; symbol: sub_40C498
int __thiscall sub_40C498(int this, int a2)
{
  int result; // eax
  bool v3; // zf
  bool v4; // sf
  unsigned __int8 v5; // of
  int v6; // ebx
  int v7; // edx
  int v8; // eax
  int v9; // esi
  int v10; // eax
  int v11; // ST60_4
  char v12; // al
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // edi
  int v17; // ST5C_4
  char i; // al
  int *v19; // eax
  int v20; // edx
  _DWORD *v21; // eax
  _DWORD *v22; // esi
  int v23; // edx
  int v24; // eax
  int v25; // esi
  int j; // eax
  int v27; // ecx
  int v28; // edi
  int k; // eax
  int l; // eax
  int v31; // edx
  int v32; // ecx
  int v33; // edx
  int v34; // edx
  int v35; // ecx
  int v36; // edx
  signed int v37; // esi
  int v38; // edi
  int *v39; // [esp+28h] [ebp-100h]
  int *v40; // [esp+2Ch] [ebp-FCh]
  int v41; // [esp+30h] [ebp-F8h]
  int v42; // [esp+38h] [ebp-F0h]
  int v43; // [esp+3Ch] [ebp-ECh]
  int v44; // [esp+40h] [ebp-E8h]
  int v45; // [esp+4Ch] [ebp-DCh]
  int *v46; // [esp+50h] [ebp-D8h]
  int v47; // [esp+50h] [ebp-D8h]
  int *v48; // [esp+54h] [ebp-D4h]
  int v49; // [esp+54h] [ebp-D4h]
  int v50; // [esp+58h] [ebp-D0h]
  int v51; // [esp+5Ch] [ebp-CCh]
  int v52; // [esp+60h] [ebp-C8h]
  int v53; // [esp+60h] [ebp-C8h]
  int v54; // [esp+64h] [ebp-C4h]
  int v55; // [esp+64h] [ebp-C4h]
  int v56; // [esp+68h] [ebp-C0h]
  int v57; // [esp+68h] [ebp-C0h]
  int v58; // [esp+6Ch] [ebp-BCh]
  char v59; // [esp+70h] [ebp-B8h]
  int v60[8]; // [esp+80h] [ebp-A8h]
  int v61[8]; // [esp+A0h] [ebp-88h]
  char v62; // [esp+C0h] [ebp-68h]
  int v63[8]; // [esp+D0h] [ebp-58h]
  int v64[14]; // [esp+F0h] [ebp-38h]

  result = a2;
  v5 = __OFSUB__(*(_DWORD *)(this + 12), 3);
  v3 = *(_DWORD *)(this + 12) == 3;
  v4 = *(_DWORD *)(this + 12) - 3 < 0;
  *(_BYTE *)(this + 2167) = 0;
  *(_DWORD *)(this + 2524) = 0;
  *(_DWORD *)(this + 2532) = 0;
  if ( (unsigned __int8)(v4 ^ v5) | v3 )
  {
    result = *(_DWORD *)(this + 16);
    v58 = *(_DWORD *)(this + 16);
    if ( !result )
    {
      v6 = this;
      v56 = 0;
      v48 = (int *)(this + 32);
      v46 = (int *)(this + 28);
      while ( *(_DWORD *)v6 > v56 )
      {
        v7 = 0;
        v54 = v56 << 9;
        while ( *(_DWORD *)(v6 + 4) > v7 )
        {
          *(_DWORD *)(4 * v7 + *(_DWORD *)(v6 + 2528) + v54) = -1;
          if ( *(_BYTE *)(v7 + *(_DWORD *)(v6 + 48) + (v56 << 7)) )
          {
            v8 = *(_DWORD *)(v6 + 56) + 4 * v7;
            *(_DWORD *)(v6 + 2444) = v7;
            *(_DWORD *)(v6 + 2440) = v56;
            v9 = 0;
            v10 = *(_DWORD *)(v8 + v54);
            *(_DWORD *)(v6 + 2452) = 0;
            *(_DWORD *)(v6 + 2448) = v10;
            do
            {
              v11 = v7;
              v12 = sub_40BEAE((_DWORD *)v6, v9, v56, v7, v46, v48);
              v7 = v11;
              if ( v12 )
              {
                v13 = *(_DWORD *)(v6 + 28);
                v14 = *(_DWORD *)(v6 + 32);
                v52 = v13;
                v15 = v13 << 7;
                if ( *(_BYTE *)(v15 + *(_DWORD *)(v6 + 36) + v14) || *(_BYTE *)(v15 + *(_DWORD *)(v6 + 64) + v14) )
                {
                  --*(_DWORD *)(v6 + 2448);
                }
                else if ( !*(_BYTE *)(*(_DWORD *)(v6 + 48) + v15 + v14) )
                {
                  v16 = v6 + 4 * *(_DWORD *)(v6 + 2452);
                  v17 = *(_DWORD *)(v6 + 2452);
                  *(_DWORD *)(v16 + 2488) = v14;
                  *(_DWORD *)(v16 + 2456) = v52;
                  *(_DWORD *)(v6 + 2452) = v17 + 1;
                }
              }
              ++v9;
            }
            while ( v9 != 8 );
            *(_DWORD *)(*(_DWORD *)(v6 + 2528) + 4 * v7 + v54) = *(_DWORD *)(v6 + 2524);
            qmemcpy(
              (void *)(*(_DWORD *)(v6 + 2520) + 80 * (*(_DWORD *)(v6 + 2524))++),
              (const void *)(v6 + 2440),
              0x50u);
          }
          ++v7;
        }
        ++v56;
      }
      v57 = 0;
      v40 = (int *)(v6 + 32);
      v39 = (int *)(v6 + 28);
      while ( *(_DWORD *)(v6 + 2524) > v57 )
      {
        v55 = 0;
        v53 = 80 * v57;
        v19 = (int *)(*(_DWORD *)(v6 + 2520) + 80 * v57);
        v44 = *v19;
        v43 = v19[1];
        for ( i = sub_40BEAE((_DWORD *)v6, 0, *v19, v43, v39, v40); ; i = sub_40BEAE(
                                                                            (_DWORD *)v6,
                                                                            v55,
                                                                            v44,
                                                                            v43,
                                                                            v39,
                                                                            v40) )
        {
          if ( i )
          {
            v20 = *(_DWORD *)(*(_DWORD *)(v6 + 2528) + (*(_DWORD *)(v6 + 28) << 9) + 4 * *(_DWORD *)(v6 + 32));
            if ( v20 >= 0 )
            {
              v21 = (_DWORD *)(*(_DWORD *)(v6 + 2520) + v53);
              qmemcpy(&v59, v21, 0x50u);
              v51 = v21[3];
              v42 = v21[2];
              v50 = 80 * v20;
              v22 = (_DWORD *)(*(_DWORD *)(v6 + 2520) + 80 * v20);
              v23 = v22[2];
              v24 = v22[3];
              qmemcpy(&v62, v22, 0x50u);
              v25 = 0;
              v41 = v24;
              v45 = v51;
              while ( v51 > v25 )
              {
                for ( j = 0; v41 > j; ++j )
                {
                  v27 = v60[v25];
                  if ( v27 >= 0 )
                  {
                    v28 = v61[v25];
                    if ( v28 >= 0 )
                    {
                      v49 = v63[j];
                      if ( v49 >= 0 )
                      {
                        v47 = v64[j];
                        if ( v47 >= 0 && v27 == v49 )
                        {
                          if ( v28 == v47 )
                          {
                            --v45;
                            v60[v25] = -1;
                            v61[v25] = -1;
                            v63[j] = -1;
                            v64[j] = -1;
                          }
                        }
                      }
                    }
                  }
                }
                ++v25;
              }
              if ( v42 - v23 == v45 )
              {
                for ( k = 0; *(_DWORD *)(*(_DWORD *)(v6 + 2520) + v53 + 12) > k; ++k )
                {
                  v31 = v60[k];
                  if ( v31 >= 0 )
                  {
                    v32 = v61[k];
                    if ( v32 >= 0 )
                    {
                      v33 = v31 << 7;
                      if ( !*(_BYTE *)(v32 + *(_DWORD *)(v6 + 52) + v33) )
                        *(_BYTE *)(*(_DWORD *)(v6 + 64) + v32 + v33) = 1;
                    }
                  }
                }
                for ( l = 0; *(_DWORD *)(*(_DWORD *)(v6 + 2520) + v50 + 12) > l; ++l )
                {
                  v34 = v63[l];
                  if ( v34 >= 0 )
                  {
                    v35 = v64[l];
                    if ( v35 >= 0 )
                    {
                      v36 = v34 << 7;
                      if ( !*(_BYTE *)(v35 + *(_DWORD *)(v6 + 52) + v36) )
                        *(_BYTE *)(*(_DWORD *)(v6 + 60) + v35 + v36) = 1;
                    }
                  }
                }
              }
            }
          }
          if ( ++v55 == 8 )
            break;
        }
        ++v57;
      }
      while ( 1 )
      {
        result = v58;
        if ( *(_DWORD *)v6 <= v58 )
          break;
        v37 = 2;
        v38 = v58 << 7;
        while ( *(_DWORD *)(v6 + 4) > v37 )
        {
          if ( *(_BYTE *)(v37 + *(_DWORD *)(v6 + 60) + v38) )
          {
            if ( !*(_BYTE *)(v37 + *(_DWORD *)(v6 + 48) + v38) && !*(_BYTE *)(v37 + *(_DWORD *)(v6 + 52) + v38) )
            {
              ++*(_DWORD *)(v6 + 2532);
              *(_BYTE *)(v6 + 2164) = 1;
              *(_BYTE *)(v6 + 2165) = 1;
              *(_BYTE *)(v6 + 2166) = 1;
              *(_BYTE *)(v6 + 2167) = 1;
              *(_BYTE *)(v6 + 2168) = 1;
              if ( (_BYTE)a2 )
                sub_4122D0(v58, v37, 0, 3);
            }
          }
          if ( *(_BYTE *)(v37 + *(_DWORD *)(v6 + 64) + v38) )
          {
            if ( !*(_BYTE *)(v37 + *(_DWORD *)(v6 + 48) + v38)
              && !*(_BYTE *)(v37 + *(_DWORD *)(v6 + 40) + v38)
              && !*(_BYTE *)(v37 + *(_DWORD *)(v6 + 36) + v38)
              && !*(_BYTE *)(v37 + *(_DWORD *)(v6 + 52) + v38) )
            {
              ++*(_DWORD *)(v6 + 2532);
              *(_BYTE *)(v6 + 2164) = 1;
              *(_BYTE *)(v6 + 2165) = 1;
              *(_BYTE *)(v6 + 2166) = 1;
              *(_BYTE *)(v6 + 2167) = 1;
              *(_BYTE *)(v6 + 2168) = 1;
              if ( (_BYTE)a2 )
                sub_4121F2(v58, v37, 0, 3);
            }
          }
          ++v37;
        }
        ++v58;
      }
      if ( (_BYTE)a2 )
        result = sub_40EA0C(*(_DWORD *)(v6 + 2080));
    }
  }
  return result;
}


// Address: 0x0040CA82; symbol: sub_40CA82
int __thiscall sub_40CA82(int this, char a2)
{
  int result; // eax
  int v3; // ebx
  char v4; // dl
  int v5; // ecx
  int v6; // edi
  int i; // eax
  int v8; // eax
  signed int v9; // esi
  double v10; // st7
  double v11; // st6
  int v12; // ecx
  double v13; // st6
  int v14; // esi
  int v15; // [esp+2Ch] [ebp-2Ch]
  int v16; // [esp+30h] [ebp-28h]
  int v17; // [esp+34h] [ebp-24h]

  result = *(_DWORD *)(this + 12) - 1;
  if ( (unsigned int)result <= 2 && !*(_DWORD *)(this + 16) )
  {
    v3 = this;
    sub_40C23C((_BYTE *)this);
    v17 = *(_DWORD *)(v3 + 4) - 1;
    v16 = *(_DWORD *)(v3 + 20);
    if ( v16 < 0 )
      v16 = 0;
    v15 = 0;
    v4 = 0;
    while ( v16 <= v17 )
    {
      v5 = 0;
      v6 = 0;
      for ( i = 0; *(_DWORD *)v3 > i; ++i )
      {
        v6 += *(_BYTE *)((i << 7) + *(_DWORD *)(v3 + 48) + v17) < 1u;
        v5 -= (*(_BYTE *)((i << 7) + *(_DWORD *)(v3 + 36) + v17) < 1u) - 1;
      }
      v8 = *(_DWORD *)(v3 + 8);
      if ( v5 != v8 && v6 != v8 )
      {
        --v17;
      }
      else
      {
        if ( (unsigned int)(*(_DWORD *)(v3 + 12) - 1) <= 2 && !*(_DWORD *)(v3 + 16) )
          sub_411B10(v17);
        if ( *(_DWORD *)(v3 + 2248) && a2 || *(_DWORD *)(v3 + 2272) == 1 )
        {
          v9 = 0;
          while ( 1 )
          {
            v10 = (double)v9;
            v11 = *(double *)(v3 + 2240);
            if ( v11 <= v10 )
              break;
            ++v9;
            sub_412A78(
              (signed int)(v11 * (double)*(signed int *)(v3 + 2224)),
              (signed int)(v10 + v11 * (double)(16 * (v17 + 3 - v15) + 8) - (v11 - 1.0) * 0.5),
              0,
              *(_DWORD *)(v3 + 2232));
          }
        }
        ++v15;
        v4 = 1;
      }
    }
    if ( v4 )
    {
      if ( (sub_40EA0C(*(_DWORD *)(v3 + 2080)), *(_DWORD *)(v3 + 2248)) && a2 || *(_DWORD *)(v3 + 2272) == 1 )
      {
        sub_4117A3(v12);
        v13 = 1000.0 / ((double)*(signed int *)(v3 + 2160) / 5.0 + 1.0);
        *(double *)(v3 + 2104) = (double)(signed int)v13 / 1000.0 + *(double *)(v3 + 2104);
        Sleep((signed int)v13);
        *(_DWORD *)(v3 + 2252) = 1;
      }
    }
    sub_40C23C((_BYTE *)v3);
    *(_BYTE *)(v3 + 2167) = 1;
    for ( result = -1; *(_BYTE *)(v3 + 2167); result = v14 )
    {
      v14 = *(_DWORD *)(v3 + 2532);
      if ( v14 <= result )
        break;
      sub_40C498(v3, 0);
    }
  }
  return result;
}


// Address: 0x0040CCD0; symbol: sub_40CCD0
char __thiscall sub_40CCD0(int this, int a2, int a3)
{
  int v3; // esi
  int v4; // edi
  char result; // al
  signed int v6; // ebx
  int v7; // ebx
  bool v8; // zf
  bool v9; // sf
  char v10; // ST1F_1
  int v11; // edx
  int v12; // eax
  int v13; // ecx
  char v14; // ST1F_1

  v3 = a2 << 7;
  v4 = (a2 << 7) + *(_DWORD *)(this + 48);
  result = *(_BYTE *)(v4 + a3);
  if ( result )
  {
    result = *(_BYTE *)(v3 + *(_DWORD *)(this + 44) + a3);
    if ( result )
    {
      v6 = *(_DWORD *)(this + 12);
      if ( v6 > 3 || v6 == 2 )
      {
        result = 0;
      }
      else
      {
        *(_BYTE *)(this + 2176) = 1;
        v7 = this;
        *(_DWORD *)(this + 2184) = a3;
        *(_DWORD *)(this + 2180) = a2;
        *(_BYTE *)(v4 + a3) = 0;
        *(_BYTE *)(v3 + *(_DWORD *)(this + 36) + a3) = 1;
        *(_BYTE *)(*(_DWORD *)(this + 40) + v3 + a3) = 0;
        v8 = *(_DWORD *)(this + 2532) == 0;
        v9 = *(_DWORD *)(this + 2532) < 0;
        *(_DWORD *)(this + 12) = 2;
        if ( !v9 && !v8 || *(_DWORD *)(this + 2272) > 0 )
        {
          v10 = result;
          sub_40C342(this, a3, 1);
          sub_40C342(v7, v11, 1);
          sub_40E540(*(_DWORD *)(v7 + 2156) - *(_DWORD *)(v7 + 2196), *(_DWORD *)(v7 + 2128), *(_DWORD *)(v7 + 696));
          v12 = *(_DWORD *)(v7 + 2192);
          v13 = *(_DWORD *)(v7 + 704);
          *(_DWORD *)(v7 + 2196) = *(_DWORD *)(v7 + 2156);
          *(_DWORD *)(v7 + 2192) = v12 + 1;
          sub_40E540(v12 + 1, *(_DWORD *)(v7 + 2128), v13);
          sub_40CA82(v7, 1);
          sub_40BAC0(v7);
          result = v10;
        }
        if ( *(_DWORD *)(v7 + 12) == 2 )
          *(_DWORD *)(v7 + 12) = 1;
        v14 = result;
        sub_40E604(*(_DWORD *)(v7 + 660), 1, *(_DWORD *)(v7 + 2128));
        sub_40EA0C(*(_DWORD *)(v7 + 2060));
        *(_BYTE *)(v7 + 2136) = 0;
        *(_DWORD *)(v7 + 2172) = 1;
        result = v14;
      }
    }
  }
  return result;
}


// Address: 0x0040CE72; symbol: sub_40CE72
char __thiscall sub_40CE72(int this)
{
  char result; // al
  int v2; // esi
  int *v3; // ebx
  int i; // edi

  result = *(_DWORD *)(this + 12) <= 3 && *(_DWORD *)(this + 12) != 2;
  if ( result )
  {
    result = 0;
    v2 = 0;
    v3 = (int *)this;
    *(_BYTE *)(this + 2176) = 0;
    while ( *v3 > v2 )
    {
      for ( i = 0; v3[1] > i; ++i )
        result = sub_40CCD0((int)v3, v2, i);
      ++v2;
    }
  }
  return result;
}


// Address: 0x0040CEC4; symbol: sub_40CEC4
char __thiscall sub_40CEC4(int *this)
{
  int v1; // esi
  int *v2; // ebx
  _DWORD *v3; // eax
  int v4; // edi
  int v5; // edx
  int v7; // [esp+14h] [ebp-20h]
  int *v8; // [esp+18h] [ebp-1Ch]
  int *v9; // [esp+1Ch] [ebp-18h]
  int v10; // [esp+24h] [ebp-10h]

  v1 = 0;
  v2 = this;
  v9 = this + 8;
  LOBYTE(v3) = (_BYTE)this + 28;
  v8 = this + 7;
  while ( v1 < *v2 )
  {
    v4 = 0;
    LOBYTE(v3) = 0;
    v10 = v1 << 9;
    while ( v4 < v2[1] )
    {
      *(_DWORD *)(4 * v4 + v2[14] + v10) = 0;
      v5 = 0;
      do
      {
        v7 = v5;
        LOBYTE(v3) = sub_40BEAE(v2, v5, v1, v4, v8, v9);
        if ( (_BYTE)v3 )
        {
          v3 = (_DWORD *)(v2[11] + (v2[7] << 7));
          if ( *((_BYTE *)v3 + v2[8]) )
          {
            v3 = (_DWORD *)(v2[14] + v10 + 4 * v4);
            ++*v3;
          }
        }
        v5 = v7 + 1;
      }
      while ( v7 != 7 );
      ++v4;
    }
    ++v1;
  }
  return (char)v3;
}


// Address: 0x0040CF70; symbol: sub_40CF70
char __thiscall sub_40CF70(int *this)
{
  int v1; // edx
  int v2; // eax
  int v3; // ebx
  int v4; // esi

  *this = 3;
  v1 = 0;
  this[1] = 5;
  while ( v1 < *this )
  {
    v2 = 0;
    v3 = v1 << 7;
    while ( v2 < this[1] )
    {
      *(_BYTE *)(v2 + this[11] + v3) = 0;
      *(_BYTE *)(v2 + this[9] + v3) = 0;
      *(_BYTE *)(v2 + this[10] + v3) = 0;
      *(_BYTE *)(v2 + this[12] + v3) = 0;
      *(_BYTE *)(v2 + this[13] + v3) = 0;
      v4 = this[14] + 4 * v2++;
      *(_DWORD *)(v4 + (v1 << 9)) = 0;
    }
    ++v1;
  }
  *(_BYTE *)this[11] = 1;
  *(_BYTE *)(this[11] + 1) = 1;
  *(_BYTE *)(this[11] + 129) = 1;
  *(_BYTE *)(this[11] + 4) = 1;
  *(_BYTE *)(this[11] + 132) = 1;
  *(_BYTE *)(this[12] + 256) = 1;
  *(_BYTE *)(this[12] + 257) = 1;
  *(_BYTE *)(this[12] + 130) = 1;
  *(_BYTE *)(this[12] + 258) = 1;
  *(_BYTE *)(this[12] + 131) = 1;
  *(_BYTE *)(this[12] + 259) = 1;
  return sub_40CEC4(this);
}


// Address: 0x0040D04C; symbol: sub_40D04C
char __thiscall sub_40D04C(int *this)
{
  int *v1; // ebx

  v1 = this;
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
  this[9] = (int)calloc(0x80u, 0x80u);
  v1[10] = (int)calloc(0x80u, 0x80u);
  v1[11] = (int)calloc(0x80u, 0x80u);
  v1[12] = (int)calloc(0x80u, 0x80u);
  v1[13] = (int)calloc(0x80u, 0x80u);
  v1[15] = (int)calloc(0x80u, 0x80u);
  v1[16] = (int)calloc(0x80u, 0x80u);
  v1[14] = (int)calloc(0x80u, 0x200u);
  return sub_40CF70(v1);
}


// Address: 0x0040D14C; symbol: sub_40D14C
int __thiscall sub_40D14C(int this)
{
  int v1; // ebx
  _DWORD *v2; // esi
  int v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  int v24; // ecx
  int v25; // eax
  int v26; // ecx
  int v27; // eax
  int v28; // ecx
  int v29; // eax
  int v30; // ecx
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // ecx
  int v35; // eax
  int v36; // ecx
  int v37; // esi
  int v38; // eax
  int v39; // eax
  int v40; // esi
  int v41; // eax
  int v42; // edx
  int v43; // eax
  int v44; // ecx
  int v45; // eax
  int v46; // edx
  int v47; // eax
  int v48; // ecx
  int v49; // eax
  int v50; // edx
  int v51; // eax
  int v52; // ecx
  int v53; // eax
  int v54; // edx
  int v55; // eax
  int v56; // ecx
  int v57; // eax
  int v58; // edx
  int v59; // eax
  int v60; // ecx
  int v61; // ecx
  int v62; // eax
  int v63; // eax
  _DWORD *v64; // esi
  int v65; // eax
  int v66; // edx
  int v67; // eax
  int v68; // ecx
  int v69; // eax
  int v70; // edx
  int v71; // eax
  int v72; // ecx
  int v73; // ecx
  int v74; // edi
  int v75; // eax
  int v76; // eax
  int v77; // edx
  int v78; // edx
  int v79; // eax
  int v80; // eax
  int v81; // edx
  int v82; // eax
  int v83; // ecx
  int v84; // eax
  int v85; // eax
  int v86; // edx
  int v87; // eax
  int v88; // ecx
  int v89; // eax
  int v90; // edx
  int v91; // eax
  int v92; // ecx
  int v93; // eax
  int v94; // edx
  int v95; // eax
  int v96; // ecx
  int v97; // eax
  int v98; // edx
  int v99; // eax
  int v100; // ecx
  int v101; // eax
  int v102; // edx
  int v103; // eax
  int v104; // ecx
  int v105; // eax
  int v106; // edx
  int v107; // eax
  int v108; // ecx
  int v109; // eax
  int v110; // edx
  int v111; // eax
  int v112; // ecx
  int v113; // eax
  int v114; // edx
  int v115; // eax
  int v116; // ecx
  int v117; // eax
  int v118; // edx
  int v119; // eax
  int v120; // ecx
  int v121; // eax
  int v122; // edx
  int v123; // eax
  int v124; // ecx
  int v125; // eax
  int v126; // edx
  int v127; // eax
  int v128; // ecx
  int v129; // eax
  int v130; // edx
  int v131; // eax
  int v132; // ecx
  int v133; // eax
  int v134; // eax
  int v135; // eax
  int v136; // eax
  int v137; // eax
  int v138; // eax
  int v139; // eax
  int v140; // eax
  int v141; // eax
  int v142; // eax
  int v143; // eax
  int v144; // eax
  int v145; // esi
  int v146; // eax
  int v147; // edx
  int *v148; // edi
  int v149; // eax
  int v150; // ecx
  int v151; // edx
  int v152; // eax
  int v153; // ecx
  int v154; // edx
  int v155; // ecx
  int v156; // eax
  int v157; // edx
  int v158; // edx
  int v159; // eax
  int v160; // edx
  int v161; // eax
  int v162; // edx
  int v163; // eax
  int v164; // edx
  int v165; // eax
  int v166; // edx
  int v167; // eax
  int v168; // edx
  int v169; // eax
  int v170; // edx
  int v171; // eax
  int v172; // edx
  int v173; // eax
  int v174; // edx
  int v175; // eax
  int v176; // edx
  int v177; // eax
  int v178; // edx
  int v179; // eax
  int v180; // edx
  int v181; // eax
  int v182; // edx
  int v183; // eax
  int v184; // edx
  int v185; // eax
  int v186; // edx
  int v187; // eax
  int v188; // edx
  int v189; // eax
  int v190; // esi
  int v191; // edx
  int v192; // eax
  int y; // ST08_4
  int v194; // ecx
  int v195; // edx
  int v196; // eax
  int v197; // edx
  int v198; // eax
  int v199; // edx
  int v200; // eax
  int v201; // edx
  int v202; // eax
  int v203; // edx
  int v204; // eax
  int v205; // edx
  int v206; // eax
  int v207; // esi
  int v208; // edi
  int v209; // edx
  int v210; // eax
  int v211; // ecx
  int v212; // edx
  int v213; // eax
  int v214; // edx
  int v215; // eax
  int v216; // eax
  int v217; // edx
  _DWORD *v218; // esi
  signed int v219; // edi
  int v220; // edx
  int v221; // ST08_4
  int v222; // ecx
  int v223; // ST24_4
  int v224; // edi
  int v225; // ecx
  int v226; // edx
  int v227; // eax
  int v228; // edx
  int v229; // eax
  int v230; // edx
  int v231; // eax
  int v232; // ecx
  int v233; // edx
  int v234; // eax
  int v235; // edx
  int v236; // eax
  int v237; // edx
  int v238; // eax
  int v239; // edx
  int v240; // eax
  int v241; // edx
  int v242; // eax
  int v243; // edx
  int v244; // eax
  int v245; // edx
  int v246; // eax
  int v247; // edx
  int v248; // eax
  int v249; // edx
  int v250; // eax
  int v251; // edx
  int v252; // eax
  int v253; // edx
  int v254; // eax
  int v255; // edx
  int v256; // eax
  int v258; // [esp+2Ch] [ebp-12Ch]
  char Dest; // [esp+3Ch] [ebp-11Ch]

  v1 = this;
  if ( *(_BYTE *)(this + 732) )
  {
    v134 = *(_DWORD *)(this + 156);
    sub_412478();
    v135 = *(_DWORD *)(v1 + 160);
    sub_412478();
    v136 = *(_DWORD *)(v1 + 300);
    sub_412478();
    v137 = *(_DWORD *)(v1 + 340);
    sub_412478();
    v138 = *(_DWORD *)(v1 + 424);
    sub_412478();
    v139 = *(_DWORD *)(v1 + 428);
    sub_412478();
    v140 = *(_DWORD *)(v1 + 432);
    sub_412478();
    v141 = *(_DWORD *)(v1 + 580);
    sub_412478();
    v142 = *(_DWORD *)(v1 + 592);
    sub_412478();
    v143 = *(_DWORD *)(v1 + 600);
    sub_412478();
    v144 = *(_DWORD *)(v1 + 620);
    sub_412478();
  }
  else
  {
    v2 = (_DWORD *)(this + 164);
    v3 = this + 172;
    do
    {
      v4 = *(_DWORD *)(v1 + 16);
      ++v2;
      *(v2 - 1) = sub_412A2E(this, *(_DWORD *)(v1 + 20));
      v5 = *(_DWORD *)(v1 + 16);
      v2[1] = sub_412A2E(v6, *(_DWORD *)(v1 + 20));
      v7 = *(_DWORD *)(v1 + 16);
      v2[3] = sub_412A2E(v8, *(_DWORD *)(v1 + 20));
      v9 = *(_DWORD *)(v1 + 16);
      v2[5] = sub_412A2E(v10, *(_DWORD *)(v1 + 20));
      v11 = *(_DWORD *)(v1 + 16);
      v2[7] = sub_412A2E(v12, *(_DWORD *)(v1 + 20));
      v13 = *(_DWORD *)(v1 + 16);
      v2[9] = sub_412A2E(v14, *(_DWORD *)(v1 + 20));
      v15 = *(_DWORD *)(v1 + 16);
      v2[11] = sub_412A2E(v16, *(_DWORD *)(v1 + 20));
      v17 = *(_DWORD *)(v1 + 16);
      v2[13] = sub_412A2E(v18, *(_DWORD *)(v1 + 20));
      v19 = *(_DWORD *)(v1 + 16);
      v2[15] = sub_412A2E(v20, *(_DWORD *)(v1 + 20));
      v21 = *(_DWORD *)(v1 + 16);
      v2[17] = sub_412A2E(v22, *(_DWORD *)(v1 + 20));
      v23 = *(_DWORD *)(v1 + 16);
      v2[19] = sub_412A2E(v24, *(_DWORD *)(v1 + 20));
      v25 = *(_DWORD *)(v1 + 16);
      v2[21] = sub_412A2E(v26, *(_DWORD *)(v1 + 20));
      v27 = *(_DWORD *)(v1 + 16);
      v2[23] = sub_412A2E(v28, *(_DWORD *)(v1 + 20));
      v29 = *(_DWORD *)(v1 + 16);
      v2[25] = sub_412A2E(v30, *(_DWORD *)(v1 + 20));
      v31 = *(_DWORD *)(v1 + 16);
      v2[27] = sub_412A2E(v32, *(_DWORD *)(v1 + 20));
      v33 = *(_DWORD *)(v1 + 16);
      v2[29] = sub_412A2E(v34, *(_DWORD *)(v1 + 20));
      v35 = *(_DWORD *)(v1 + 16);
      v2[31] = sub_412A2E(v36, *(_DWORD *)(v1 + 20));
    }
    while ( v2 != (_DWORD *)v3 );
    v37 = 0;
    do
    {
      v38 = *(_DWORD *)(v1 + 24);
      *(_DWORD *)(v1 + 4 * v37++ + 304) = sub_412A2E(this, *(_DWORD *)(v1 + 28));
    }
    while ( v37 != 9 );
    v39 = *(_DWORD *)(v1 + 32);
    v40 = 0;
    v41 = sub_412A2E(this, *(_DWORD *)(v1 + 36));
    v42 = *(_DWORD *)(v1 + 36);
    *(_DWORD *)(v1 + 388) = v41;
    v43 = *(_DWORD *)(v1 + 32);
    v45 = sub_412A2E(v44, v42);
    v46 = *(_DWORD *)(v1 + 36);
    *(_DWORD *)(v1 + 396) = v45;
    v47 = *(_DWORD *)(v1 + 32);
    v49 = sub_412A2E(v48, v46);
    v50 = *(_DWORD *)(v1 + 36);
    *(_DWORD *)(v1 + 392) = v49;
    v51 = *(_DWORD *)(v1 + 32);
    v53 = sub_412A2E(v52, v50);
    v54 = *(_DWORD *)(v1 + 36);
    *(_DWORD *)(v1 + 400) = v53;
    v55 = *(_DWORD *)(v1 + 32);
    v57 = sub_412A2E(v56, v54);
    v58 = *(_DWORD *)(v1 + 36);
    *(_DWORD *)(v1 + 404) = v57;
    v59 = *(_DWORD *)(v1 + 32);
    *(_DWORD *)(v1 + 408) = sub_412A2E(v60, v58);
    do
    {
      v62 = *(_DWORD *)(v1 + 32);
      *(_DWORD *)(v1 + 4 * v40++ + 344) = sub_412A2E(v61, *(_DWORD *)(v1 + 36));
    }
    while ( v40 != 11 );
    v63 = *(_DWORD *)(v1 + 32);
    v64 = (_DWORD *)v1;
    v65 = sub_412A2E(v61, *(_DWORD *)(v1 + 36));
    v66 = *(_DWORD *)(v1 + 36);
    *(_DWORD *)(v1 + 412) = v65;
    v67 = *(_DWORD *)(v1 + 32);
    v69 = sub_412A2E(v68, v66);
    v70 = *(_DWORD *)(v1 + 36);
    *(_DWORD *)(v1 + 416) = v69;
    v71 = *(_DWORD *)(v1 + 32);
    *(_DWORD *)(v1 + 420) = sub_412A2E(v72, v70);
    do
    {
      v74 = 0;
      do
      {
        v75 = v64[10];
        v76 = sub_412A2E(v73, v64[13]);
        v77 = 3 * v74++;
        v64[v77 + 109] = v76;
      }
      while ( v74 != 10 );
      v78 = v64[13];
      v79 = v64[10];
      ++v64;
      v80 = sub_412A2E(v73, v78);
      v81 = v64[12];
      v64[138] = v80;
      v82 = v64[9];
      v64[141] = sub_412A2E(v83, v81);
    }
    while ( v64 != (_DWORD *)(v1 + 12) );
    v84 = *(_DWORD *)(v1 + 64);
    v85 = sub_412A2E(v73, *(_DWORD *)(v1 + 68));
    v86 = *(_DWORD *)(v1 + 76);
    *(_DWORD *)(v1 + 584) = v85;
    v87 = *(_DWORD *)(v1 + 72);
    v89 = sub_412A2E(v88, v86);
    v90 = *(_DWORD *)(v1 + 132);
    *(_DWORD *)(v1 + 588) = v89;
    v91 = *(_DWORD *)(v1 + 128);
    v93 = sub_412A2E(v92, v90);
    v94 = *(_DWORD *)(v1 + 140);
    *(_DWORD *)(v1 + 596) = v93;
    v95 = *(_DWORD *)(v1 + 136);
    v97 = sub_412A2E(v96, v94);
    v98 = *(_DWORD *)(v1 + 140);
    *(_DWORD *)(v1 + 604) = v97;
    v99 = *(_DWORD *)(v1 + 136);
    v101 = sub_412A2E(v100, v98);
    v102 = *(_DWORD *)(v1 + 140);
    *(_DWORD *)(v1 + 608) = v101;
    v103 = *(_DWORD *)(v1 + 136);
    v105 = sub_412A2E(v104, v102);
    v106 = *(_DWORD *)(v1 + 140);
    *(_DWORD *)(v1 + 612) = v105;
    v107 = *(_DWORD *)(v1 + 136);
    v109 = sub_412A2E(v108, v106);
    v110 = *(_DWORD *)(v1 + 148);
    *(_DWORD *)(v1 + 616) = v109;
    v111 = *(_DWORD *)(v1 + 144);
    v113 = sub_412A2E(v112, v110);
    v114 = *(_DWORD *)(v1 + 148);
    *(_DWORD *)(v1 + 624) = v113;
    v115 = *(_DWORD *)(v1 + 144);
    v117 = sub_412A2E(v116, v114);
    v118 = *(_DWORD *)(v1 + 148);
    *(_DWORD *)(v1 + 628) = v117;
    v119 = *(_DWORD *)(v1 + 144);
    v121 = sub_412A2E(v120, v118);
    v122 = *(_DWORD *)(v1 + 148);
    *(_DWORD *)(v1 + 632) = v121;
    v123 = *(_DWORD *)(v1 + 144);
    v125 = sub_412A2E(v124, v122);
    v126 = *(_DWORD *)(v1 + 148);
    *(_DWORD *)(v1 + 636) = v125;
    v127 = *(_DWORD *)(v1 + 144);
    v129 = sub_412A2E(v128, v126);
    v130 = *(_DWORD *)(v1 + 148);
    *(_DWORD *)(v1 + 640) = v129;
    v131 = *(_DWORD *)(v1 + 144);
    v133 = sub_412A2E(v132, v130);
    *(_BYTE *)(v1 + 732) = 1;
    *(_DWORD *)(v1 + 644) = v133;
  }
  sprintf(&Dest, "./data/png/%ld/bg.png", *(_DWORD *)(v1 + 688));
  dword_41E160 = (int)&Dest;
  *(_DWORD *)(v1 + 156) = sub_4128EE();
  sprintf(&Dest, "./data/png/%ld/menu.png", *(_DWORD *)(v1 + 688));
  dword_41E160 = (int)&Dest;
  dword_41E164 = 2;
  *(_DWORD *)(v1 + 160) = sub_4128EE();
  sprintf(&Dest, "./data/png/%ld/face.png", *(_DWORD *)(v1 + 688));
  dword_41E160 = (int)&Dest;
  dword_41E164 = 2;
  *(_DWORD *)(v1 + 300) = sub_4128EE();
  sprintf(&Dest, "./data/png/%ld/icon.png", *(_DWORD *)(v1 + 688));
  dword_41E160 = (int)&Dest;
  dword_41E164 = 2;
  *(_DWORD *)(v1 + 340) = sub_4128EE();
  sprintf(&Dest, "./data/png/%ld/digt.png", *(_DWORD *)(v1 + 688));
  dword_41E160 = (int)&Dest;
  dword_41E164 = 2;
  *(_DWORD *)(v1 + 424) = sub_4128EE();
  sprintf(&Dest, "./data/png/%ld/digt2.png", *(_DWORD *)(v1 + 688));
  dword_41E160 = (int)&Dest;
  dword_41E164 = 2;
  *(_DWORD *)(v1 + 428) = sub_4128EE();
  sprintf(&Dest, "./data/png/%ld/digt_.png", *(_DWORD *)(v1 + 688));
  dword_41E160 = (int)&Dest;
  dword_41E164 = 2;
  *(_DWORD *)(v1 + 432) = sub_4128EE();
  sprintf(&Dest, "./data/png/%ld/ok.png", *(_DWORD *)(v1 + 688));
  dword_41E160 = (int)&Dest;
  dword_41E164 = 2;
  *(_DWORD *)(v1 + 580) = sub_4128EE();
  sprintf(&Dest, "./data/png/%ld/cursor.png", *(_DWORD *)(v1 + 688));
  dword_41E160 = (int)&Dest;
  dword_41E164 = 2;
  *(_DWORD *)(v1 + 592) = sub_4128EE();
  sprintf(&Dest, "./data/png/%ld/click.png", *(_DWORD *)(v1 + 688));
  dword_41E160 = (int)&Dest;
  dword_41E164 = 2;
  *(_DWORD *)(v1 + 600) = sub_4128EE();
  sprintf(&Dest, "./data/png/%ld/arrow.png", *(_DWORD *)(v1 + 688));
  dword_41E160 = (int)&Dest;
  dword_41E164 = 2;
  v145 = 0;
  *(_DWORD *)(v1 + 620) = sub_4128EE();
  do
  {
    v146 = *(_DWORD *)(v1 + 156);
    if ( !v146 )
      v146 = dword_4561C0;
    *(_DWORD *)(v1 + 4 * v145 + 652) = GetPixel(*(HDC *)(v146 + 4), 0, v145);
    ++v145;
  }
  while ( v145 != 9 );
  v147 = *(_DWORD *)(v1 + 660);
  v148 = (int *)(v1 + 164);
  v149 = *(_DWORD *)(v1 + 652);
  v258 = 0;
  *(_DWORD *)(v1 + 712) = *(_DWORD *)(v1 + 672);
  v150 = *(_DWORD *)(v1 + 676);
  *(_DWORD *)(v1 + 700) = v147;
  v151 = *(_DWORD *)(v1 + 664);
  *(_DWORD *)(v1 + 692) = v149;
  v152 = *(_DWORD *)(v1 + 656);
  *(_DWORD *)(v1 + 716) = v150;
  v153 = *(_DWORD *)(v1 + 680);
  *(_DWORD *)(v1 + 704) = v151;
  v154 = *(_DWORD *)(v1 + 668);
  *(_DWORD *)(v1 + 696) = v152;
  *(_DWORD *)(v1 + 728) = v152;
  *(_DWORD *)(v1 + 720) = v153;
  v155 = *(_DWORD *)(v1 + 684);
  *(_DWORD *)(v1 + 708) = v154;
  *(_DWORD *)(v1 + 3000) = v154;
  *(_DWORD *)(v1 + 724) = v155;
  do
  {
    v156 = *(_DWORD *)(v1 + 160);
    v157 = *v148;
    sub_413F44(0, *(_DWORD *)(v1 + 16), *(_DWORD *)(v1 + 20), *(_DWORD *)(v1 + 16), *(_DWORD *)(v1 + 20));
    v158 = v148[2];
    v159 = *(_DWORD *)(v1 + 160);
    sub_413F44(
      *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20));
    v160 = v148[4];
    v161 = *(_DWORD *)(v1 + 160);
    sub_413F44(
      2 * *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20));
    v162 = v148[6];
    v163 = *(_DWORD *)(v1 + 160);
    sub_413F44(
      3 * *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20));
    v164 = v148[8];
    v165 = *(_DWORD *)(v1 + 160);
    sub_413F44(
      4 * *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20));
    v166 = v148[10];
    v167 = *(_DWORD *)(v1 + 160);
    sub_413F44(
      5 * *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20));
    v168 = v148[12];
    v169 = *(_DWORD *)(v1 + 160);
    sub_413F44(
      6 * *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20));
    v170 = v148[14];
    v171 = *(_DWORD *)(v1 + 160);
    sub_413F44(
      7 * *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20));
    v172 = v148[16];
    v173 = *(_DWORD *)(v1 + 160);
    sub_413F44(
      8 * *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20));
    v174 = v148[18];
    v175 = *(_DWORD *)(v1 + 160);
    sub_413F44(
      9 * *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20));
    v176 = v148[20];
    v177 = *(_DWORD *)(v1 + 160);
    sub_413F44(
      10 * *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20));
    v178 = v148[22];
    v179 = *(_DWORD *)(v1 + 160);
    sub_413F44(
      11 * *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20));
    v180 = v148[24];
    ++v148;
    v181 = *(_DWORD *)(v1 + 160);
    sub_413F44(
      12 * *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20));
    v182 = v148[25];
    v183 = *(_DWORD *)(v1 + 160);
    sub_413F44(
      13 * *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20));
    v184 = v148[27];
    v185 = *(_DWORD *)(v1 + 160);
    sub_413F44(
      14 * *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20));
    v186 = v148[29];
    v187 = *(_DWORD *)(v1 + 160);
    sub_413F44(
      15 * *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20));
    v188 = v148[31];
    v189 = *(_DWORD *)(v1 + 160);
    sub_413F44(
      16 * *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20),
      *(_DWORD *)(v1 + 16),
      *(_DWORD *)(v1 + 20));
    ++v258;
  }
  while ( v258 != 2 );
  v190 = 0;
  do
  {
    v191 = *(_DWORD *)(v1 + 4 * v190 + 304);
    v192 = *(_DWORD *)(v1 + 300);
    y = *(_DWORD *)(v1 + 28);
    v194 = v190++ * y;
    sub_413F44(v194, *(_DWORD *)(v1 + 24), y, *(_DWORD *)(v1 + 24), y);
  }
  while ( v190 != 9 );
  v195 = *(_DWORD *)(v1 + 388);
  v196 = *(_DWORD *)(v1 + 340);
  sub_413F44(0, *(_DWORD *)(v1 + 32), *(_DWORD *)(v1 + 36), *(_DWORD *)(v1 + 32), *(_DWORD *)(v1 + 36));
  v197 = *(_DWORD *)(v1 + 396);
  v198 = *(_DWORD *)(v1 + 340);
  sub_413F44(
    *(_DWORD *)(v1 + 36),
    *(_DWORD *)(v1 + 32),
    *(_DWORD *)(v1 + 36),
    *(_DWORD *)(v1 + 32),
    *(_DWORD *)(v1 + 36));
  v199 = *(_DWORD *)(v1 + 392);
  v200 = *(_DWORD *)(v1 + 340);
  sub_413F44(
    2 * *(_DWORD *)(v1 + 36),
    *(_DWORD *)(v1 + 32),
    *(_DWORD *)(v1 + 36),
    *(_DWORD *)(v1 + 32),
    *(_DWORD *)(v1 + 36));
  v201 = *(_DWORD *)(v1 + 400);
  v202 = *(_DWORD *)(v1 + 340);
  sub_413F44(
    3 * *(_DWORD *)(v1 + 36),
    *(_DWORD *)(v1 + 32),
    *(_DWORD *)(v1 + 36),
    *(_DWORD *)(v1 + 32),
    *(_DWORD *)(v1 + 36));
  v203 = *(_DWORD *)(v1 + 404);
  v204 = *(_DWORD *)(v1 + 340);
  sub_413F44(
    4 * *(_DWORD *)(v1 + 36),
    *(_DWORD *)(v1 + 32),
    *(_DWORD *)(v1 + 36),
    *(_DWORD *)(v1 + 32),
    *(_DWORD *)(v1 + 36));
  v205 = *(_DWORD *)(v1 + 408);
  v206 = *(_DWORD *)(v1 + 340);
  v207 = 0;
  sub_413F44(
    5 * *(_DWORD *)(v1 + 36),
    *(_DWORD *)(v1 + 32),
    *(_DWORD *)(v1 + 36),
    *(_DWORD *)(v1 + 32),
    *(_DWORD *)(v1 + 36));
  do
  {
    v208 = *(_DWORD *)(v1 + 36);
    v209 = *(_DWORD *)(v1 + 4 * v207 + 344);
    v210 = *(_DWORD *)(v1 + 340);
    v211 = v208 * (16 - v207++);
    sub_413F44(v211, *(_DWORD *)(v1 + 32), *(_DWORD *)(v1 + 36), *(_DWORD *)(v1 + 32), v208);
  }
  while ( v207 != 11 );
  v212 = *(_DWORD *)(v1 + 412);
  v213 = *(_DWORD *)(v1 + 340);
  sub_413F44(
    16 * *(_DWORD *)(v1 + 36),
    *(_DWORD *)(v1 + 32),
    *(_DWORD *)(v1 + 36),
    *(_DWORD *)(v1 + 32),
    *(_DWORD *)(v1 + 36));
  v214 = *(_DWORD *)(v1 + 416);
  v215 = *(_DWORD *)(v1 + 340);
  sub_413F44(
    17 * *(_DWORD *)(v1 + 36),
    *(_DWORD *)(v1 + 32),
    *(_DWORD *)(v1 + 36),
    *(_DWORD *)(v1 + 32),
    *(_DWORD *)(v1 + 36));
  v216 = *(_DWORD *)(v1 + 340);
  v217 = *(_DWORD *)(v1 + 420);
  v218 = (_DWORD *)v1;
  sub_413F44(
    18 * *(_DWORD *)(v1 + 36),
    *(_DWORD *)(v1 + 32),
    *(_DWORD *)(v1 + 36),
    *(_DWORD *)(v1 + 32),
    *(_DWORD *)(v1 + 36));
  do
  {
    v219 = 11;
    do
    {
      v220 = v218[-3 * v219 + 142];
      v221 = v218[13];
      v222 = v219-- * v221;
      v223 = v218[106];
      sub_413F44(v222, v218[10], v221, v218[10], v221);
    }
    while ( v219 != 1 );
    v224 = v218[13];
    v225 = v218[10];
    ++v218;
    v226 = v218[138];
    v227 = v218[105];
    sub_413F44(0, v225, v224, v225, v224);
    v228 = v218[141];
    v229 = v218[105];
    sub_413F44(v218[12], v218[9], v218[12], v218[9], v218[12]);
  }
  while ( (_DWORD *)(v1 + 12) != v218 );
  v230 = *(_DWORD *)(v1 + 584);
  v231 = *(_DWORD *)(v1 + 580);
  sub_413F44(0, *(_DWORD *)(v1 + 64), *(_DWORD *)(v1 + 68), *(_DWORD *)(v1 + 64), *(_DWORD *)(v1 + 68));
  v232 = *(_DWORD *)(v1 + 64);
  v233 = *(_DWORD *)(v1 + 588);
  v234 = *(_DWORD *)(v1 + 580);
  sub_413F44(0, *(_DWORD *)(v1 + 72), *(_DWORD *)(v1 + 76), *(_DWORD *)(v1 + 72), *(_DWORD *)(v1 + 76));
  v235 = *(_DWORD *)(v1 + 596);
  v236 = *(_DWORD *)(v1 + 592);
  sub_413F44(0, *(_DWORD *)(v1 + 128), *(_DWORD *)(v1 + 132), *(_DWORD *)(v1 + 128), *(_DWORD *)(v1 + 132));
  v237 = *(_DWORD *)(v1 + 604);
  v238 = *(_DWORD *)(v1 + 600);
  sub_413F44(0, *(_DWORD *)(v1 + 136), *(_DWORD *)(v1 + 140), *(_DWORD *)(v1 + 136), *(_DWORD *)(v1 + 140));
  v239 = *(_DWORD *)(v1 + 608);
  v240 = *(_DWORD *)(v1 + 600);
  sub_413F44(
    *(_DWORD *)(v1 + 140),
    *(_DWORD *)(v1 + 136),
    *(_DWORD *)(v1 + 140),
    *(_DWORD *)(v1 + 136),
    *(_DWORD *)(v1 + 140));
  v241 = *(_DWORD *)(v1 + 612);
  v242 = *(_DWORD *)(v1 + 600);
  sub_413F44(
    2 * *(_DWORD *)(v1 + 140),
    *(_DWORD *)(v1 + 136),
    *(_DWORD *)(v1 + 140),
    *(_DWORD *)(v1 + 136),
    *(_DWORD *)(v1 + 140));
  v243 = *(_DWORD *)(v1 + 616);
  v244 = *(_DWORD *)(v1 + 600);
  sub_413F44(
    3 * *(_DWORD *)(v1 + 140),
    *(_DWORD *)(v1 + 136),
    *(_DWORD *)(v1 + 140),
    *(_DWORD *)(v1 + 136),
    *(_DWORD *)(v1 + 140));
  v245 = *(_DWORD *)(v1 + 624);
  v246 = *(_DWORD *)(v1 + 620);
  sub_413F44(0, *(_DWORD *)(v1 + 144), *(_DWORD *)(v1 + 148), *(_DWORD *)(v1 + 144), *(_DWORD *)(v1 + 148));
  v247 = *(_DWORD *)(v1 + 628);
  v248 = *(_DWORD *)(v1 + 620);
  sub_413F44(
    *(_DWORD *)(v1 + 148),
    *(_DWORD *)(v1 + 144),
    *(_DWORD *)(v1 + 148),
    *(_DWORD *)(v1 + 144),
    *(_DWORD *)(v1 + 148));
  v249 = *(_DWORD *)(v1 + 632);
  v250 = *(_DWORD *)(v1 + 620);
  sub_413F44(
    2 * *(_DWORD *)(v1 + 148),
    *(_DWORD *)(v1 + 144),
    *(_DWORD *)(v1 + 148),
    *(_DWORD *)(v1 + 144),
    *(_DWORD *)(v1 + 148));
  v251 = *(_DWORD *)(v1 + 636);
  v252 = *(_DWORD *)(v1 + 620);
  sub_413F44(
    3 * *(_DWORD *)(v1 + 148),
    *(_DWORD *)(v1 + 144),
    *(_DWORD *)(v1 + 148),
    *(_DWORD *)(v1 + 144),
    *(_DWORD *)(v1 + 148));
  v253 = *(_DWORD *)(v1 + 640);
  v254 = *(_DWORD *)(v1 + 620);
  sub_413F44(
    4 * *(_DWORD *)(v1 + 148),
    *(_DWORD *)(v1 + 144),
    *(_DWORD *)(v1 + 148),
    *(_DWORD *)(v1 + 144),
    *(_DWORD *)(v1 + 148));
  v255 = *(_DWORD *)(v1 + 644);
  v256 = *(_DWORD *)(v1 + 620);
  return sub_413F44(
           5 * *(_DWORD *)(v1 + 148),
           *(_DWORD *)(v1 + 144),
           *(_DWORD *)(v1 + 148),
           *(_DWORD *)(v1 + 144),
           *(_DWORD *)(v1 + 148));
}


// Address: 0x0040E150; symbol: sub_40E150
DWORD __stdcall sub_40E150(LPVOID lpThreadParameter)
{
  int v1; // eax
  DWORD result; // eax

  v1 = dword_41E164;
  if ( dword_41E164 > 0 )
  {
    do
    {
      if ( v1 == 2 )
      {
        dword_41E164 = 1;
        sub_413BEC(dword_45E500);
      }
      Sleep(1u);
      v1 = dword_41E164;
    }
    while ( dword_41E164 > 0 );
    dword_41E160 = 0;
    result = 0;
  }
  else
  {
    dword_41E160 = 0;
    result = 0;
  }
  return result;
}


// Address: 0x0040E1B4; symbol: sub_40E1B4
int __cdecl sub_40E1B4(int *a1)
{
  int result; // eax

  result = SteamInternal_FindOrCreateUserInterface(0, "SteamUtils010");
  *a1 = result;
  return result;
}


// Address: 0x0040E1D6; symbol: sub_40E1D6
int __cdecl sub_40E1D6(int *a1)
{
  int v1; // eax
  int result; // eax

  v1 = SteamAPI_GetHSteamUser();
  result = SteamInternal_FindOrCreateUserInterface(v1, "STEAMREMOTESTORAGE_INTERFACE_VERSION016");
  *a1 = result;
  return result;
}


// Address: 0x0040E1FA; symbol: sub_40E1FA
int __cdecl sub_40E1FA(int *a1)
{
  int v1; // eax
  int result; // eax

  v1 = SteamAPI_GetHSteamUser();
  result = SteamInternal_FindOrCreateUserInterface(v1, "SteamFriends017");
  *a1 = result;
  return result;
}


// Address: 0x0040E21E; symbol: sub_40E21E
int __cdecl sub_40E21E(int *a1)
{
  int v1; // eax
  int result; // eax

  v1 = SteamAPI_GetHSteamUser();
  result = SteamInternal_FindOrCreateUserInterface(v1, "STEAMSCREENSHOTS_INTERFACE_VERSION003");
  *a1 = result;
  return result;
}


// Address: 0x0040E242; symbol: sub_40E242
int __cdecl sub_40E242(int *a1)
{
  int v1; // eax
  int result; // eax

  v1 = SteamAPI_GetHSteamUser();
  result = SteamInternal_FindOrCreateUserInterface(v1, "STEAMAPPS_INTERFACE_VERSION008");
  *a1 = result;
  return result;
}


// Address: 0x0040E266; symbol: sub_40E266
int __cdecl sub_40E266(int *a1)
{
  int v1; // eax
  int result; // eax

  v1 = SteamAPI_GetHSteamUser();
  result = SteamInternal_FindOrCreateUserInterface(v1, "STEAMUSERSTATS_INTERFACE_VERSION012");
  *a1 = result;
  return result;
}


// Address: 0x0040E28A; symbol: sub_40E28A
int sub_40E28A()
{
  int v1; // [esp+4h] [ebp-14h]

  return *(_DWORD *)SteamInternal_ContextInit(&off_418658, v1);
}


// Address: 0x0040E2A1; symbol: sub_40E2A1
int sub_40E2A1()
{
  int v1; // [esp+4h] [ebp-14h]

  return *(_DWORD *)SteamInternal_ContextInit(&off_41864C, v1);
}


// Address: 0x0040E2B8; symbol: sub_40E2B8
int sub_40E2B8()
{
  int v0; // eax

  v0 = sub_40E2A1();
  return (*(int (__thiscall **)(int, signed int))(*(_DWORD *)v0 + 84))(v0, 1);
}


// Address: 0x0040E2D4; symbol: sub_40E2D4
unsigned int __thiscall sub_40E2D4(int this)
{
  signed int v1; // edx
  unsigned int result; // eax

  v1 = *(_DWORD *)(this + 728);
  result = *(_DWORD *)(this + 764);
  if ( v1 > 9998 || v1 > 3000 && (result -= 99, result > 0x383) )
  {
    result = 0;
    if ( *(_BYTE *)(this + 348) )
    {
      do
        *(_DWORD *)(this + 4 * result++ + 712) = 0;
      while ( result != 19 );
      result = sub_40E2B8();
    }
  }
  return result;
}


// Address: 0x0040E31E; symbol: sub_40E31E
void __thiscall sub_40E31E(int this, int a2)
{
  int v2; // ebx
  int v3; // eax
  int v4; // ST00_4
  int v5; // eax

  if ( *(_BYTE *)(this + 348)
    && !*(_BYTE *)(this + a2 + 560)
    && (!*(_BYTE *)(this + 349) || a2 == *(_DWORD *)(this + 372)) )
  {
    v2 = this;
    v3 = sub_40E2A1();
    v4 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 28))(v3, *(_DWORD *)(v2 + 4 * a2 + 456));
    v5 = sub_40E2A1();
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 40))(v5, v4);
    *(_BYTE *)(v2 + a2 + 560) = 1;
  }
}


// Address: 0x0040E384; symbol: sub_40E384
void __thiscall sub_40E384(_BYTE *this, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v10; // eax
  int v11; // eax

  if ( this[348] )
  {
    v10 = *(_DWORD *)&this[4 * a2 + 712];
    if ( a3 > v10 )
    {
      if ( a4 > v10 )
      {
        if ( a5 > v10 )
        {
          if ( a6 > v10 )
            return;
          v11 = a10;
        }
        else
        {
          v11 = a9;
        }
      }
      else
      {
        v11 = a8;
      }
    }
    else
    {
      v11 = a7;
    }
    sub_40E31E((int)this, v11);
  }
}


// Address: 0x0040E3D0; symbol: sub_40E3D0
void __thiscall sub_40E3D0(char *this, int a2)
{
  char *v2; // ebx
  int v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // [esp+10h] [ebp-40h]
  int v7; // [esp+14h] [ebp-3Ch]
  int v8; // [esp+18h] [ebp-38h]
  int v9; // [esp+1Ch] [ebp-34h]
  int v10; // [esp+20h] [ebp-30h]
  int v11; // [esp+24h] [ebp-2Ch]
  int v12; // [esp+28h] [ebp-28h]

  v2 = this;
  v3 = (int)&this[4 * a2];
  if ( *(_DWORD *)(v3 + 712) > 0 )
  {
    v4 = sub_40E2A1();
    (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)v4 + 16))(
      v4,
      *(_DWORD *)(v3 + 636),
      *(float *)&v2[4 * a2 + 712]);
  }
  if ( a2 == *((_DWORD *)v2 + 147) )
  {
    v12 = *((_DWORD *)v2 + 98);
    v11 = *((_DWORD *)v2 + 99);
    v10 = *((_DWORD *)v2 + 100);
    v5 = *((_DWORD *)v2 + 101);
LABEL_7:
    v9 = v5;
    v8 = 1;
    v7 = 10;
    v6 = 100;
LABEL_12:
    sub_40E384(v2, a2, 1000, v6, v7, v8, v9, v10, v11, v12);
    return;
  }
  if ( a2 == *((_DWORD *)v2 + 148) )
  {
    v12 = *((_DWORD *)v2 + 102);
    v11 = *((_DWORD *)v2 + 103);
    v10 = *((_DWORD *)v2 + 104);
    v5 = *((_DWORD *)v2 + 105);
    goto LABEL_7;
  }
  if ( a2 == *((_DWORD *)v2 + 149) )
  {
    sub_40E384(
      v2,
      a2,
      10000,
      1000,
      100,
      10,
      *((_DWORD *)v2 + 113),
      *((_DWORD *)v2 + 112),
      *((_DWORD *)v2 + 111),
      *((_DWORD *)v2 + 110));
    return;
  }
  if ( a2 == *((_DWORD *)v2 + 150) )
  {
    v8 = 100;
    v7 = 300;
    v6 = 600;
    v12 = *((_DWORD *)v2 + 106);
    v11 = *((_DWORD *)v2 + 107);
    v10 = *((_DWORD *)v2 + 108);
    v9 = *((_DWORD *)v2 + 109);
    goto LABEL_12;
  }
}


// Address: 0x0040E540; symbol: sub_40E540
void __thiscall sub_40E540(int this, int a2, int a3, int a4)
{
  int v4; // eax
  int v5; // eax
  int v6; // edi
  signed int v7; // ebx
  int v8; // esi
  int v9; // edx
  int v10; // ecx
  int v11; // eax

  if ( *(_BYTE *)(this + 348) && *(_BYTE *)(this + 349) != 1 && a3 > 0 )
  {
    switch ( a3 )
    {
      case 2:
        v4 = *(_DWORD *)(this + 608);
        break;
      case 3:
        v4 = *(_DWORD *)(this + 612);
        break;
      case 1:
        v4 = *(_DWORD *)(this + 604);
        break;
      default:
        return;
    }
    if ( v4 > 0 )
    {
      v5 = a4 + v4;
      v6 = this + 4 * v5;
      v7 = v5;
      if ( a2 > *(_DWORD *)(v6 + 712) )
      {
        *(_DWORD *)(v6 + 712) = a2;
        v8 = this;
        sub_40E3D0((char *)this, v5);
        if ( v7 <= 6 )
        {
          v9 = *(_DWORD *)(v8 + 600);
          v10 = v8 + 4 * v9;
          v11 = *(_DWORD *)(v10 + 712);
          if ( v11 < *(_DWORD *)(v6 + 712) )
            v11 = *(_DWORD *)(v6 + 712);
          *(_DWORD *)(v10 + 712) = v11;
          if ( *(_BYTE *)(v8 + 348) )
            sub_40E3D0((char *)v8, v9);
        }
        *(_BYTE *)(v8 + 788) = 1;
      }
    }
  }
}


// Address: 0x0040E604; symbol: sub_40E604
void __thiscall sub_40E604(char *this, int a2, int a3, int a4)
{
  if ( this[348] && this[349] != 1 && a4 > 0 )
  {
    *(_DWORD *)&this[4 * a2 + 712] += a3;
    sub_40E3D0(this, a2);
  }
}


// Address: 0x0040E63C; symbol: sub_40E63C
int sub_40E63C()
{
  int v1; // [esp+4h] [ebp-14h]

  return *(_DWORD *)SteamInternal_ContextInit(&off_418640, v1);
}


// Address: 0x0040E654; symbol: sub_40E654
char __thiscall sub_40E654(double *this)
{
  double *v1; // esi
  int v2; // ebx
  int v3; // edi
  int v4; // eax
  int v5; // eax
  signed int v7; // [esp+2Ch] [ebp-28h]
  char v8; // [esp+30h] [ebp-24h]

  v1 = this;
  v2 = 0;
  v3 = (int)(this + 237);
  v8 = 1;
  v7 = (signed int)sub_412E2B();
  do
  {
    while ( byte_41E168 )
    {
      v4 = sub_40E63C();
      if ( (*(unsigned __int8 (__thiscall **)(int, _DWORD, _DWORD, int))(*(_DWORD *)v4 + 44))(
             v4,
             LODWORD(v1[v2 + 108]),
             HIDWORD(v1[v2 + 108]),
             v3)
        || (double)v7 + v1[238] <= sub_412E2B() )
      {
        break;
      }
      Sleep(1u);
    }
    if ( v8 )
    {
      v5 = sub_40E63C();
      v8 = (*(int (__thiscall **)(int, _DWORD, _DWORD, int))(*(_DWORD *)v5 + 44))(
             v5,
             LODWORD(v1[v2 + 108]),
             HIDWORD(v1[v2 + 108]),
             v3);
    }
    ++v2;
  }
  while ( v2 != 15 );
  return v8;
}


// Address: 0x0040E732; symbol: sub_40E732
void __thiscall sub_40E732(_BYTE *this)
{
  int v1; // esi
  _BYTE *v2; // ebx
  int v3; // eax
  int v4; // edx
  int v5; // esi
  int v6; // eax
  int v7; // edx

  if ( this[348] )
  {
    v1 = 0;
    v2 = this;
    dword_41E160 = (int)"Load Leaderboard";
    dword_41E164 = 2;
    do
    {
      v3 = sub_40E2A1();
      *(_DWORD *)&v2[8 * v1 + 864] = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 92))(
                                       v3,
                                       *(_DWORD *)&v2[4 * v1 + 792]);
      *(_DWORD *)&v2[8 * v1++ + 868] = v4;
    }
    while ( v1 != 15 );
    if ( v2[348] && sub_40E654((double *)v2) )
    {
      v5 = 0;
      do
      {
        v6 = sub_40E63C();
        (*(void (__thiscall **)(int, _DWORD, _DWORD, _BYTE *, signed int, signed int, _BYTE *))(*(_DWORD *)v6 + 52))(
          v6,
          *(_DWORD *)&v2[8 * v5 + 864],
          *(_DWORD *)&v2[8 * v5 + 868],
          v2 + 1344,
          16,
          1104,
          v2 + 1896);
        v7 = *((_DWORD *)v2 + 337);
        *(_DWORD *)&v2[8 * v5 + 1416] = *((_DWORD *)v2 + 336);
        *(_DWORD *)&v2[8 * v5++ + 1420] = v7;
      }
      while ( v5 != 15 );
    }
  }
}


// Address: 0x0040E822; symbol: sub_40E822
void __thiscall sub_40E822(_BYTE *this, int a2)
{
  _BYTE *v2; // ebx
  int v3; // eax
  int v4; // edi
  int v5; // edi
  _DWORD *v6; // esi
  int v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // edx
  int v11; // [esp+44h] [ebp-1Ch]

  if ( this[348] )
  {
    v2 = this;
    sub_40E2D4((int)this);
    if ( a2 > 0 )
    {
      if ( v2[788] )
      {
        v3 = 8 * a2;
        v2[788] = 0;
        v4 = (int)&v2[8 * a2];
        if ( !*(_QWORD *)(v4 + 1408) )
        {
          sub_40E732(v2);
          v3 = 8 * a2;
        }
        if ( *(_QWORD *)(v4 + 1408) )
        {
          v5 = (int)&v2[4 * a2];
          v11 = (int)&v2[v3 + 120];
          v6 = &v2[4 * a2 + 4 * a2];
          do
          {
            v7 = sub_40E2A1();
            v6[214] = (*(int (__thiscall **)(int, _DWORD, _DWORD, signed int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v7 + 124))(
                        v7,
                        v6[352],
                        v6[353],
                        1,
                        *(_DWORD *)(v5 + 724),
                        0,
                        0);
            v6[215] = v8;
            if ( v2[348] )
            {
              if ( sub_40E654((double *)v2) )
              {
                v9 = sub_40E63C();
                (*(void (__thiscall **)(int, _DWORD, _DWORD, _BYTE *, signed int, signed int, _BYTE *))(*(_DWORD *)v9 + 52))(
                  v9,
                  v6[214],
                  v6[215],
                  v2 + 1360,
                  32,
                  1106,
                  v2 + 1896);
                v10 = *((_DWORD *)v2 + 343);
                v6[352] = *((_DWORD *)v2 + 342);
                v6[353] = v10;
              }
            }
            v5 += 12;
            v6 += 6;
          }
          while ( v6 != (_DWORD *)v11 );
        }
      }
    }
  }
}


// Address: 0x0040E998; symbol: sub_40E998
void __usercall sub_40E998(int a1@<edx>, int a2@<ecx>, int a3@<ebx>)
{
  int v3; // eax
  int v4; // ebx
  int v5; // eax
  double v6; // st7
  int v7; // edx
  int v8; // eax
  int v9; // eax
  int v10; // [esp-Ch] [ebp-Ch]
  int v11; // [esp-8h] [ebp-8h]
  int v12; // [esp-4h] [ebp-4h]

  if ( *(_BYTE *)(a2 + 105) )
  {
    if ( byte_41E168 && (v3 = *(_DWORD *)(a2 + 100), v3 > 0) )
    {
      v11 = a3;
      v10 = a1;
      v4 = a2;
      if ( *(_DWORD *)(a2 + 108) != -256 && v3 != 1 )
      {
        v5 = rand();
        *(_DWORD *)(v4 + 108) = (v5 % (*(_DWORD *)(v4 + 100) - 1) >= *(_DWORD *)(v4 + 108))
                              + v5 % (*(_DWORD *)(v4 + 100) - 1);
      }
      else
      {
        *(_DWORD *)(a2 + 108) = 0;
      }
      v6 = sub_412E2B(v10, v11, v12);
      v7 = *(_DWORD *)(v4 + 108);
      v8 = *(_DWORD *)(v4 + 32);
      *(double *)(v4 + 112) = v6;
      v9 = *(_DWORD *)(v8 + 4 * v7);
      sub_413EEC();
    }
    else
    {
      *(_DWORD *)(a2 + 108) = -256;
      *(double *)(a2 + 112) = 0.0;
    }
  }
}


// Address: 0x0040EA0C; symbol: sub_40EA0C
int __userpurge sub_40EA0C@<eax>(int a1@<ecx>, int a2@<ebp>, int a3)
{
  int v3; // eax
  int result; // eax
  int v5; // [esp-4h] [ebp-4h]

  if ( byte_41E168 )
  {
    if ( *(_BYTE *)(a1 + 104) )
    {
      v5 = a2;
      v3 = *(_DWORD *)(a1 + 4 * a3);
      result = sub_413EEC();
    }
  }
  return result;
}


// Address: 0x0040EA30; symbol: sub_40EA30
int __usercall sub_40EA30@<eax>(int a1@<eax>, int a2@<ecx>, int a3@<ebp>)
{
  int result; // eax
  bool v4; // zf
  int v5; // [esp+18h] [ebp-4h]

  LOBYTE(a1) = *(_BYTE *)(a2 + 104);
  result = a1 ^ 1;
  v4 = byte_41E168 == 0;
  *(_BYTE *)(a2 + 104) = result;
  if ( !v4 )
  {
    if ( (_BYTE)result )
    {
      v5 = a3;
      result = sub_40EA0C(a2, (int)&v5, *(_DWORD *)(a2 + 80));
    }
  }
  return result;
}


// Address: 0x0040EAC4; symbol: sub_40EAC4
LSTATUS __thiscall sub_40EAC4(DWORD *this, HKEY hKey, LPCSTR lpValueName, int a4)
{
  DWORD *lpcbData; // eax
  DWORD *lpType; // ecx
  LSTATUS result; // eax
  BYTE Data[4]; // [esp+2Ch] [ebp-Ch]

  lpcbData = this + 3;
  lpType = this + 2;
  lpType[1] = 4;
  result = RegQueryValueExA(hKey, lpValueName, 0, lpType, Data, lpcbData);
  if ( !result )
  {
    result = a4;
    *(_DWORD *)a4 = *(_DWORD *)Data;
  }
  return result;
}


// Address: 0x0040EB14; symbol: sub_40EB14
_WORD *__thiscall sub_40EB14(LPVOID *this, char *Source)
{
  LPVOID *v2; // ebx
  HANDLE v3; // eax
  void *v4; // edi
  unsigned int i; // eax
  _WORD *v6; // ecx
  int v7; // edx
  int v8; // edx
  __int16 v9; // di
  int v10; // esi
  signed __int16 v11; // di
  signed int v12; // eax
  int v13; // ecx
  __int16 v14; // si
  _WORD *v15; // edx
  int v16; // ecx
  int v17; // edx
  int v18; // esi
  int v19; // eax
  _WORD *result; // eax
  int v21; // [esp+24h] [ebp-94h]
  signed int v22; // [esp+28h] [ebp-90h]
  DWORD v23; // [esp+2Ch] [ebp-8Ch]
  int v24; // [esp+2Ch] [ebp-8Ch]
  DWORD NumberOfBytesRead; // [esp+38h] [ebp-80h]
  CHAR FileName; // [esp+3Ch] [ebp-7Ch]

  v2 = this;
  strcpy(&FileName, "./data/lan/");
  strcat(&FileName, Source);
  strcat(&FileName, ".txt");
  v23 = GetTickCount();
  while ( 1 )
  {
    v3 = CreateFileA(&FileName, 0x80000000, 1u, 0, 3u, 0x80u, 0);
    v4 = v3;
    if ( v3 != (HANDLE)-1 )
      break;
    Sleep(0x64u);
    if ( GetTickCount() - v23 > 0xBB7 )
    {
      MessageBoxA(0, "Failed to load language file", "Error", 0x10u);
      ExitProcess(1u);
    }
  }
  ReadFile(v3, v2[60], 0x4E20u, &NumberOfBytesRead, 0);
  CloseHandle(v4);
  for ( i = 0; ; ++i )
  {
    v6 = (char *)v2[60] + 2 * i;
    if ( !*v6 || i > 0x2707 )
      break;
    v7 = 0;
    while ( v6[v7] == 120 )
    {
      if ( ++v7 == 8 )
      {
        v8 = 0;
        do
        {
          v9 = byte_4199E1[v8];
          v10 = i + v8++;
          *((_WORD *)v2[60] + v10) = v9;
        }
        while ( v8 != 8 );
        i += 7;
        break;
      }
    }
  }
  v22 = 262145;
  v11 = 1;
  v24 = 0;
  *(_WORD *)v2[61] = -1;
  *((_WORD *)v2[61] + 1) = -1;
  *((_WORD *)v2[61] + 2) = 0;
  *((_WORD *)v2[61] + 3) = 0;
  v12 = 4;
  while ( 1 )
  {
    v13 = 2 * v11;
    v21 = v13;
    v14 = *(_WORD *)((char *)v2[60] + v13);
    v15 = v2[61];
    v16 = (signed __int16)v12;
    if ( !v14 )
      break;
    v15[(signed __int16)v12] = v14;
    if ( *(_WORD *)((char *)v2[60] + v21) == 13 )
    {
      v17 = 2 * (SHIWORD(v22) + 2147483646);
      *(_WORD *)((char *)v2[61] + v17) = v11 - v22;
      v18 = v24++;
      *((_DWORD *)v2[62] + v18) = (char *)v2[61] + v17 + 4;
      *((_WORD *)v2[61] + (signed __int16)v12) = 0;
      *((_WORD *)v2[61] + (signed __int16)(v12 + 1)) = -1;
      *((_WORD *)v2[61] + (signed __int16)(v12 + 2)) = -1;
      LOWORD(v17) = v12 + 3;
      v12 += 4;
      *((_WORD *)v2[61] + (signed __int16)v17) = 0;
    }
    if ( *(_WORD *)((char *)v2[60] + v21) == 10 )
    {
      *((_WORD *)v2[61] + (signed __int16)v12) = 0;
      HIWORD(v22) = v12 + 1;
      LOWORD(v22) = v11 + 1;
    }
    ++v12;
    ++v11;
  }
  v19 = SHIWORD(v22) + 2147483646;
  v15[v19] = v11 - v22;
  *((_DWORD *)v2[62] + v24) = (char *)v2[61] + v19 * 2 + 4;
  result = v2[61];
  result[v16] = 0;
  return result;
}


// Address: 0x0040EE22; symbol: sub_40EE22
_WORD *__thiscall sub_40EE22(LPVOID *this)
{
  LPVOID *v1; // ebx
  LANGID v2; // ax
  char *v3; // ecx
  int v4; // edx

  v1 = this;
  qmemcpy(this, off_418540, 0x78u);
  qmemcpy(this + 30, &unk_4185C0, 0x78u);
  this[63] = 0;
  this[64] = (LPVOID)1;
  this[65] = (LPVOID)2;
  this[66] = (LPVOID)3;
  this[67] = (LPVOID)4;
  this[68] = (LPVOID)5;
  this[69] = (LPVOID)6;
  this[70] = (LPVOID)7;
  this[71] = (LPVOID)8;
  this[72] = (LPVOID)9;
  this[73] = (LPVOID)10;
  this[74] = (LPVOID)11;
  this[75] = (LPVOID)12;
  this[76] = (LPVOID)13;
  this[77] = (LPVOID)14;
  this[78] = (LPVOID)15;
  this[79] = (LPVOID)35;
  this[80] = (LPVOID)58;
  this[81] = (LPVOID)59;
  this[82] = (LPVOID)74;
  this[83] = (LPVOID)79;
  this[84] = (LPVOID)82;
  this[85] = (LPVOID)102;
  this[60] = calloc(0x2710u, 2u);
  v1[61] = calloc(0x2710u, 2u);
  v1[62] = calloc(0x3E8u, 4u);
  v2 = GetUserDefaultUILanguage();
  v3 = "english";
  v4 = 0;
  do
  {
    if ( (LPVOID)v2 == v1[v4 + 30] )
      v3 = (char *)v1[v4];
    ++v4;
  }
  while ( v4 != 30 );
  return sub_40EB14(v1, v3);
}


// Address: 0x0040EFAF; symbol: sub_40EFAF
HGDIOBJ __usercall sub_40EFAF@<eax>(int a1@<eax>, int a2@<edx>)
{
  int v2; // esi
  COLORREF v3; // ebx
  void *h; // eax

  v2 = a1;
  v3 = a2;
  dword_41863C = a2;
  DeleteObject(hbr);
  if ( v3 == 1 )
    h = GetStockObject(5);
  else
    h = CreateSolidBrush(v3);
  hbr = h;
  return SelectObject(*(HDC *)(v2 + 4), h);
}


// Address: 0x0040F008; symbol: sub_40F008
HGDIOBJ __usercall sub_40F008@<eax>(int a1@<eax>, int a2@<edx>)
{
  int v2; // esi
  COLORREF color; // ebx
  void *v4; // eax

  v2 = a1;
  color = a2;
  dword_418638 = a2;
  DeleteObject(dword_4561E0);
  if ( color == 1 )
    v4 = GetStockObject(8);
  else
    v4 = CreatePen(0, 1, color);
  dword_4561E0 = v4;
  return SelectObject(*(HDC *)(v2 + 4), v4);
}


// Address: 0x0040F074; symbol: sub_40F074
unsigned int sub_40F074()
{
  mciSendStringA(Dest, Str, 0x7Fu, 0);
  return strtoul(Str, 0, 10);
}


// Address: 0x0040F0C0; symbol: sub_40F0C0
void __fastcall sub_40F0C0(int a1, int a2)
{
  int v2; // ebx
  bool v3; // zf
  int v4; // eax
  int v5; // esi
  int savedregs; // [esp+18h] [ebp+0h]

  v2 = a1;
  v3 = *(_BYTE *)(a1 + 105) == 1;
  *(_BYTE *)(a1 + 105) ^= 1u;
  if ( v3 )
  {
    v4 = *(_DWORD *)(a1 + 108);
    if ( v4 >= 0 && v4 < *(_DWORD *)(a1 + 100) )
    {
      v5 = *(_DWORD *)(*(_DWORD *)(a1 + 32) + 4 * v4);
      sub_413EEC();
      sprintf(Dest, "stop s%lu", v5);
      sub_40F074();
    }
  }
  else
  {
    sub_40E998(a2, a1, a1);
  }
  if ( *(_BYTE *)(v2 + 104) )
    sub_40EA0C(v2, (int)&savedregs, *(_DWORD *)(v2 + 80));
}


// Address: 0x0040F128; symbol: sub_40F128
int sub_40F128()
{
  BOOL v0; // eax
  LONG v1; // ebx
  int v2; // ebx
  int v3; // eax
  int v4; // esi
  struct tagPOINT Point; // [esp+18h] [ebp-10h]

  v0 = GetCursorPos(&Point);
  v1 = Point.y;
  v2 = v1 - sub_412D30(v0);
  v3 = 0;
  if ( (dwStyle & 0x80000000) == 0 )
  {
    v4 = sub_412D92();
    v3 = v4 + sub_412E16();
  }
  return v2 - v3;
}


// Address: 0x0040F16C; symbol: sub_40F16C
DWORD __stdcall sub_40F16C(LPVOID lpThreadParameter)
{
  int *v1; // esi
  int v2; // eax
  int v3; // eax
  int v4; // edx
  int v5; // eax
  int v6; // eax
  int v7; // edx
  int v8; // eax
  int v9; // edx
  char *v10; // edi
  int v11; // esi
  int v12; // eax
  int v13; // eax
  int v14; // esi
  int v15; // eax
  int v16; // edx
  int v17; // edx
  int v18; // edi
  int v19; // eax
  int v20; // edx
  int v21; // ST68_4
  DWORD dwMilliseconds; // [esp+60h] [ebp-68h]
  DWORD dwMillisecondsa; // [esp+60h] [ebp-68h]
  int v25; // [esp+64h] [ebp-64h]
  int v26; // [esp+64h] [ebp-64h]
  int v27; // [esp+68h] [ebp-60h]
  int v28; // [esp+68h] [ebp-60h]
  signed int v29; // [esp+98h] [ebp-30h]
  char *v30; // [esp+9Ch] [ebp-2Ch]
  _DWORD *v31; // [esp+A0h] [ebp-28h]
  char v32; // [esp+A4h] [ebp-24h]
  int v33; // [esp+A4h] [ebp-24h]

  if ( !*((_BYTE *)lpThreadParameter + 3382) )
  {
    *((_BYTE *)lpThreadParameter + 3382) = 1;
    sub_413B76(lpThreadParameter);
    if ( *((_BYTE *)lpThreadParameter + 1188) )
    {
      if ( !*((_QWORD *)lpThreadParameter + 282)
        || !*((_QWORD *)lpThreadParameter + 283)
        || !*((_QWORD *)lpThreadParameter + 284) )
      {
        sub_40E732((_BYTE *)lpThreadParameter + 840);
      }
      v1 = (int *)((char *)lpThreadParameter + 1824);
      do
      {
        if ( *((_QWORD *)v1 + 54) )
        {
          v2 = sub_40E2A1();
          v3 = (*(int (__thiscall **)(int, int, int, _DWORD, signed int, signed int))(*(_DWORD *)v2 + 112))(
                 v2,
                 v1[108],
                 v1[109],
                 0,
                 1,
                 20);
          v1[1] = v4;
          *v1 = v3;
          v5 = sub_40E2A1();
          v6 = (*(int (__thiscall **)(int, int, int, signed int, signed int, signed int))(*(_DWORD *)v5 + 112))(
                 v5,
                 v1[108],
                 v1[109],
                 1,
                 -5,
                 4);
          v1[31] = v7;
          v1[30] = v6;
          v8 = sub_40E2A1();
          v1[60] = (*(int (__thiscall **)(int, int, int, signed int, _DWORD, _DWORD))(*(_DWORD *)v8 + 112))(
                     v8,
                     v1[108],
                     v1[109],
                     1,
                     0,
                     0);
          v1[61] = v9;
        }
        v1 += 2;
      }
      while ( v1 != (int *)((char *)lpThreadParameter + 1944) );
      v32 = *((_BYTE *)lpThreadParameter + 1188);
      if ( *((_BYTE *)lpThreadParameter + 1188) )
      {
        v31 = lpThreadParameter;
        v10 = (char *)lpThreadParameter;
        v29 = (signed int)sub_412E2B(dwMilliseconds, v25, v27);
        v30 = (char *)lpThreadParameter + 2736;
        do
        {
          v11 = 0;
          do
          {
            while ( byte_41E168 )
            {
              v12 = sub_40E63C();
              if ( (*(unsigned __int8 (__thiscall **)(int, _DWORD, _DWORD, char *))(*(_DWORD *)v12 + 44))(
                     v12,
                     *(_DWORD *)&v10[8 * v11 + 1824],
                     *(_DWORD *)&v10[8 * v11 + 1828],
                     v30)
                || (double)v29 + *((double *)lpThreadParameter + 343) <= sub_412E2B(dwMillisecondsa, v26, v28) )
              {
                break;
              }
              Sleep(1u);
            }
            if ( v32 )
            {
              v13 = sub_40E63C();
              v32 = (*(int (__thiscall **)(int, _DWORD, _DWORD, char *))(*(_DWORD *)v13 + 44))(
                      v13,
                      *(_DWORD *)&v10[8 * v11 + 1824],
                      *(_DWORD *)&v10[8 * v11 + 1828],
                      v30);
            }
            ++v11;
          }
          while ( v11 != 15 );
          v10 += 120;
        }
        while ( (char *)lpThreadParameter + 360 != v10 );
        if ( v32 )
        {
          v33 = 0;
          do
          {
            v14 = 0;
            do
            {
              v15 = sub_40E63C();
              (*(void (__thiscall **)(int, _DWORD, _DWORD, char *, signed int, signed int, char *))(*(_DWORD *)v15 + 52))(
                v15,
                v31[2 * v14 + 456],
                v31[2 * v14 + 457],
                (char *)lpThreadParameter + 2232,
                24,
                1105,
                (char *)lpThreadParameter + 2736);
              v16 = *((_DWORD *)lpThreadParameter + 559);
              *((_DWORD *)lpThreadParameter + 2 * v14 + 564) = *((_DWORD *)lpThreadParameter + 558);
              *((_DWORD *)lpThreadParameter + 2 * v14 + 565) = v16;
              v17 = *((_DWORD *)lpThreadParameter + 561);
              v31[2 * v14 + 594] = *((_DWORD *)lpThreadParameter + 560);
              v31[2 * v14 + 595] = v17;
              v18 = 0;
              while ( *((_DWORD *)lpThreadParameter + v33 + 423) > v18 )
              {
                v19 = sub_40E2A1();
                v20 = 9600 * v33 + 32 * (v18 + 20 * v14);
                v21 = v18++;
                (*(void (__thiscall **)(int, _DWORD, _DWORD, int, int, _DWORD, _DWORD))(*(_DWORD *)v19 + 120))(
                  v19,
                  v31[2 * v14 + 594],
                  v31[2 * v14 + 595],
                  v21,
                  *((_DWORD *)lpThreadParameter + 685) + v20,
                  0,
                  0);
              }
              ++v14;
            }
            while ( v14 != 15 );
            ++v33;
            v31 += 30;
          }
          while ( v33 != 3 );
        }
      }
    }
    sub_413B76(lpThreadParameter);
    *((_BYTE *)lpThreadParameter + 3382) = 0;
  }
  return 0;
}


// Address: 0x0040F528; symbol: sub_40F528
int __thiscall sub_40F528(_DWORD *this, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // esi
  int v6; // ebx
  int result; // eax

  v5 = this;
  v6 = 0;
  while ( v6 < a3 )
  {
    ++v6;
    result = sub_41284E(v5[8], v5[9]);
  }
  return result;
}


// Address: 0x0040F566; symbol: sub_40F566
int __thiscall sub_40F566(_DWORD *this, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  _DWORD *v9; // edi

  v9 = this;
  sub_40F528(this, a2, a5, a8, a9);
  sub_40F528(v9, a3, a6, a8 + v9[8] * a5, a9);
  return sub_40F528(v9, a4, a7, v9[8] * (a6 + a5) + a8, a9);
}


// Address: 0x0040F5F2; symbol: sub_40F5F2
int __thiscall sub_40F5F2(_DWORD *this, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
  _DWORD *v11; // esi

  v11 = this;
  sub_40F566(this, a2, a3, a4, a6, a7, a8, a10, a11);
  return sub_40F528(v11, a5, a9, a10 + v11[8] * (a8 + a7 + a6), a11);
}


// Address: 0x0040F672; symbol: sub_40F672
int __thiscall sub_40F672(_DWORD *this, _DWORD *a2, int a3, int a4)
{
  _DWORD *v4; // ebx
  int result; // eax
  int v6; // edi
  int v7; // ST28_4
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // ecx
  int v20; // ecx
  int v21; // [esp+18h] [ebp-30h]
  int v22; // [esp+1Ch] [ebp-2Ch]
  int v23; // [esp+20h] [ebp-28h]
  int v24; // [esp+2Ch] [ebp-1Ch]

  v4 = this;
  v21 = 0;
LABEL_2:
  result = v21;
  if ( v21 < *a2 )
  {
    v24 = 0;
    v6 = v21 << 7;
    while ( 1 )
    {
      if ( v24 >= a2[1] )
      {
        ++v21;
        goto LABEL_2;
      }
      v23 = v4[9];
      v22 = v4[8];
      v7 = a4 + v4[5] + v23 * v24;
      if ( *(_BYTE *)(a2[13] + v24 + v6) )
      {
        if ( v21 < a2[6] && v24 >= a2[5] - 1 )
        {
          v8 = v4[101];
LABEL_16:
          sub_41284E(v22, v23);
          goto LABEL_30;
        }
      }
      else
      {
        v9 = a2[12];
        if ( a2[4] <= 0 )
        {
          if ( *(_BYTE *)(v24 + v9 + v6) )
          {
            if ( *(_BYTE *)(a2[11] + v24 + v6) )
            {
              v12 = v4[100];
              goto LABEL_16;
            }
            v13 = v4[*(_DWORD *)(a2[14] + 4 * v24 + (v21 << 9)) + 86];
          }
          else if ( *(_BYTE *)(a2[9] + v24 + v6) )
          {
            v14 = v4[99];
          }
          else if ( *(_BYTE *)(a2[10] + v24 + v6) )
          {
            v15 = v4[98];
          }
          else
          {
            v16 = a2[3];
            if ( v16 != 4 && (v16 || v4[724]) || !*(_BYTE *)(a2[11] + v24 + v6) || v4[844] )
              v18 = v4[97];
            else
              v17 = v4[102];
          }
        }
        else
        {
          if ( *(_BYTE *)(v24 + v9 + v6) )
          {
            v10 = v4[103];
            sub_41284E(v22, v23);
            sub_412A48(v23 - 1, 0, v4[174]);
            goto LABEL_30;
          }
          v11 = v4[101];
        }
        sub_41284E(v22, v23);
      }
LABEL_30:
      if ( *((_BYTE *)v4 + 3381) )
      {
        if ( *(_BYTE *)(v4[207] + v24 + v6) && !*(_BYTE *)(v4[204] + v24 + v6) && !*(_BYTE *)(v4[205] + v24 + v6) )
        {
          v19 = v4[8] - 1;
          sub_412A48(v4[9] - 1, v4[178], v4[162]);
        }
        if ( *(_BYTE *)(v4[208] + v24 + v6)
          && !*(_BYTE *)(v4[204] + v24 + v6)
          && !*(_BYTE *)(v4[202] + v24 + v6)
          && !*(_BYTE *)(v4[201] + v24 + v6)
          && !*(_BYTE *)(v4[205] + v24 + v6) )
        {
          v20 = v4[8] - 1;
          sub_412A48(v4[9] - 1, v4[177], v4[162]);
        }
      }
      ++v24;
    }
  }
  return result;
}


// Address: 0x0040F924; symbol: sub_40F924
int __thiscall sub_40F924(_DWORD *this, unsigned int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // ecx
  int v9; // ebx
  int v10; // edi
  int v11; // edx
  bool v12; // zf
  int v13; // esi
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int result; // eax
  int v18; // [esp+0h] [ebp-68h]
  int v19; // [esp+4h] [ebp-64h]
  unsigned int v20; // [esp+18h] [ebp-50h]
  _DWORD *v21; // [esp+1Ch] [ebp-4Ch]
  int v22[16]; // [esp+28h] [ebp-40h]

  v21 = this;
  v8 = 0;
  v9 = abs(a2);
  while ( 1 )
  {
    v10 = v8 + 1;
    v11 = v9 % 10;
    v12 = v9 / 10 == 0;
    v9 /= 10;
    v22[v8] = v11;
    if ( v12 )
      break;
    ++v8;
  }
  if ( (a2 & 0x80000000) == 0 )
  {
    if ( a3 < v10 )
      a3 = v8 + 1;
  }
  else if ( v10 >= a3 )
  {
    a3 = v8 + 2;
  }
  v20 = a2 >> 31;
  v13 = a4 + a6 * (a3 - 1);
  do
  {
    if ( v10 <= v9 )
    {
      if ( (_BYTE)v20 && v10 == v9 )
      {
        v15 = v21[a8 + 139];
        v19 = a7;
        v18 = a6;
        goto LABEL_17;
      }
      v16 = v21[a8 + 142];
    }
    else
    {
      v14 = v21[3 * v22[v9] + 109 + a8];
    }
    v19 = a7;
    v18 = a6;
LABEL_17:
    ++v9;
    result = sub_41284E(v18, v19);
    v13 -= a6;
  }
  while ( a3 != v9 );
  return result;
}


// Address: 0x0040FA06; symbol: sub_40FA06
int __thiscall sub_40FA06(_DWORD *this, unsigned int a2, int a3, int a4, int a5, int a6)
{
  return sub_40F924(this, a2, a3, a4, a5, this[a6 + 10], this[a6 + 13], a6);
}


// Address: 0x0040FA4C; symbol: sub_40FA4C
int __thiscall sub_40FA4C(double *this)
{
  double *v1; // ebx
  signed int v2; // eax
  int v3; // esi
  double v4; // st7
  double v5; // st5
  double v6; // st6
  int v7; // esi
  int v8; // esi
  double v9; // st7
  double v10; // st5
  double v11; // st6
  int v12; // esi
  double v13; // st7
  double v14; // st5
  double v15; // st6
  int v16; // esi
  int v17; // esi
  double v18; // st7
  bool v19; // c0
  bool v20; // c3
  double v21; // st7
  int v22; // esi
  double v23; // st7
  double v24; // st5
  double v25; // st6
  int v26; // esi
  int v27; // esi
  double v28; // st7
  double v29; // st5
  double v30; // st6
  int v31; // esi
  double v32; // st7
  double v33; // st5
  double v34; // st6
  int v35; // esi
  int v36; // esi
  double v37; // st7
  int v38; // ST14_4
  int v39; // esi
  double v40; // ST08_8
  int v41; // esi
  int v42; // esi
  int v43; // eax
  double v44; // st7
  int v45; // esi
  int v46; // esi
  int v47; // esi
  int v48; // eax
  double v49; // st7
  bool v50; // c0
  bool v51; // c3
  int v52; // esi
  int v53; // ST14_4
  int v54; // esi
  double v55; // ST08_8
  int v56; // esi
  int v57; // esi
  int v58; // eax
  double v59; // st7
  int v60; // esi
  int v61; // esi
  int v62; // esi
  int v63; // eax
  int v64; // ST14_4
  int v65; // esi
  double v66; // ST08_8
  int v67; // esi
  int v68; // esi
  int v69; // eax
  double v70; // st7
  int v71; // esi
  int v72; // esi
  int v73; // esi
  int v74; // eax
  double v75; // st7
  bool v76; // c0
  bool v77; // c3
  int v78; // esi
  int v79; // ST14_4
  int v80; // esi
  double v81; // ST08_8
  int v82; // esi
  int v83; // esi
  int v84; // eax
  double v85; // st7
  int v86; // esi
  int v87; // esi
  int v88; // esi
  int v89; // eax
  double v90; // st6
  int v91; // eax
  double v92; // st7
  int result; // eax
  double v94; // [esp+8h] [ebp-20h]
  double v95; // [esp+8h] [ebp-20h]

  v1 = this;
  v2 = *((_DWORD *)this + 850);
  v3 = *((_DWORD *)this + 876);
  if ( v2 )
  {
    if ( v2 == 1 )
    {
      v38 = v3 - 2 * sub_412DB9();
      v39 = *((_DWORD *)v1 + 877);
      v40 = (double)v38 / (double)*((signed int *)v1 + 866);
      v41 = v39 - 2 * sub_412D92();
      if ( (double)(v41 - sub_412E16()) / (double)*((signed int *)v1 + 867) <= v40 )
      {
        v46 = *((_DWORD *)v1 + 877);
        v47 = v46 - 2 * sub_412D92();
        v48 = sub_412E16();
        v44 = (double)*((signed int *)v1 + 867);
        v45 = v47 - v48;
      }
      else
      {
        v42 = *((_DWORD *)v1 + 876);
        v43 = sub_412DB9();
        v44 = (double)*((signed int *)v1 + 866);
        v45 = v42 - 2 * v43;
      }
      v49 = (double)v45 / v44;
      v50 = 1.0 < v49;
      v51 = 1.0 == v49;
      v37 = 1.0;
      if ( v50 != 0 || v51 != 0 )
      {
        v52 = *((_DWORD *)v1 + 876);
        v53 = v52 - 2 * sub_412DB9();
        v54 = *((_DWORD *)v1 + 877);
        v55 = (double)v53 / (double)*((signed int *)v1 + 866);
        v56 = v54 - 2 * sub_412D92();
        if ( (double)(v56 - sub_412E16()) / (double)*((signed int *)v1 + 867) <= v55 )
        {
          v61 = *((_DWORD *)v1 + 877);
          v62 = v61 - 2 * sub_412D92();
          v63 = sub_412E16();
          v59 = (double)*((signed int *)v1 + 867);
          v60 = v62 - v63;
        }
        else
        {
          v57 = *((_DWORD *)v1 + 876);
          v58 = sub_412DB9();
          v59 = (double)*((signed int *)v1 + 866);
          v60 = v57 - 2 * v58;
        }
        v37 = (double)v60 / v59;
      }
    }
    else
    {
      if ( v2 < 2 )
        v2 = 2;
      if ( v2 > 8 )
        v2 = 8;
      *((_DWORD *)this + 850) = v2;
      v64 = v3 - 2 * sub_412DB9();
      v65 = *((_DWORD *)v1 + 877);
      v66 = (double)v64 / (double)*((signed int *)v1 + 866);
      v67 = v65 - 2 * sub_412D92();
      if ( (double)(v67 - sub_412E16()) / (double)*((signed int *)v1 + 867) <= v66 )
      {
        v72 = *((_DWORD *)v1 + 877);
        v73 = v72 - 2 * sub_412D92();
        v74 = sub_412E16();
        v70 = (double)*((signed int *)v1 + 867);
        v71 = v73 - v74;
      }
      else
      {
        v68 = *((_DWORD *)v1 + 876);
        v69 = sub_412DB9();
        v70 = (double)*((signed int *)v1 + 866);
        v71 = v68 - 2 * v69;
      }
      v75 = (double)v71 / v70;
      v76 = 1.0 < v75;
      v77 = 1.0 == v75;
      v37 = 1.0;
      if ( v76 != 0 || v77 != 0 )
      {
        v78 = *((_DWORD *)v1 + 876);
        v79 = v78 - 2 * sub_412DB9();
        v80 = *((_DWORD *)v1 + 877);
        v81 = (double)v79 / (double)*((signed int *)v1 + 866);
        v82 = v80 - 2 * sub_412D92();
        if ( (double)(v82 - sub_412E16()) / (double)*((signed int *)v1 + 867) <= v81 )
        {
          v87 = *((_DWORD *)v1 + 877);
          v88 = v87 - 2 * sub_412D92();
          v89 = sub_412E16();
          v85 = (double)*((signed int *)v1 + 867);
          v86 = v88 - v89;
        }
        else
        {
          v83 = *((_DWORD *)v1 + 876);
          v84 = sub_412DB9();
          v85 = (double)*((signed int *)v1 + 866);
          v86 = v83 - 2 * v84;
        }
        v37 = (double)v86 / v85;
      }
      v90 = 0.5 * (double)*((signed int *)v1 + 850);
      if ( v90 <= v37 )
        v37 = v90;
    }
  }
  else
  {
    v4 = (double)(v3 - 2 * sub_412DB9());
    v5 = (double)*((signed int *)v1 + 849);
    v6 = (double)*((signed int *)v1 + 866);
    if ( v5 > v6 )
      v6 = v5;
    v7 = *((_DWORD *)v1 + 877);
    v94 = v4 / v6;
    v8 = v7 - 2 * sub_412D92();
    v9 = (double)(v8 - sub_412E16());
    v10 = (double)*((signed int *)v1 + 848);
    v11 = (double)*((signed int *)v1 + 867);
    if ( v10 > v11 )
      v11 = v10;
    if ( v9 / v11 <= v94 )
    {
      v16 = *((_DWORD *)v1 + 877);
      v17 = v16 - 2 * sub_412D92();
      v13 = (double)(v17 - sub_412E16());
      v14 = (double)*((signed int *)v1 + 848);
      v15 = (double)*((signed int *)v1 + 867);
    }
    else
    {
      v12 = *((_DWORD *)v1 + 876);
      v13 = (double)(v12 - 2 * sub_412DB9());
      v14 = (double)*((signed int *)v1 + 849);
      v15 = (double)*((signed int *)v1 + 866);
    }
    if ( v14 > v15 )
      v15 = v14;
    v18 = v13 / v15;
    v19 = 1.0 < v18;
    v20 = 1.0 == v18;
    v21 = 1.0;
    if ( v19 != 0 || v20 != 0 )
    {
      v22 = *((_DWORD *)v1 + 876);
      v23 = (double)(v22 - 2 * sub_412DB9());
      v24 = (double)*((signed int *)v1 + 849);
      v25 = (double)*((signed int *)v1 + 866);
      if ( v24 > v25 )
        v25 = v24;
      v26 = *((_DWORD *)v1 + 877);
      v95 = v23 / v25;
      v27 = v26 - 2 * sub_412D92();
      v28 = (double)(v27 - sub_412E16());
      v29 = (double)*((signed int *)v1 + 848);
      v30 = (double)*((signed int *)v1 + 867);
      if ( v29 > v30 )
        v30 = v29;
      if ( v28 / v30 <= v95 )
      {
        v35 = *((_DWORD *)v1 + 877);
        v36 = v35 - 2 * sub_412D92();
        v32 = (double)(v36 - sub_412E16());
        v33 = (double)*((signed int *)v1 + 848);
        v34 = (double)*((signed int *)v1 + 867);
      }
      else
      {
        v31 = *((_DWORD *)v1 + 876);
        v32 = (double)(v31 - 2 * sub_412DB9());
        v33 = (double)*((signed int *)v1 + 849);
        v34 = (double)*((signed int *)v1 + 866);
      }
      if ( v33 > v34 )
        v34 = v33;
      v21 = v32 / v34;
    }
    v37 = 0.5 * (double)(signed int)(v21 + v21);
  }
  v91 = *((_DWORD *)v1 + 866);
  v1[426] = v37;
  v92 = v1[426];
  *((_DWORD *)v1 + 748) = v91;
  result = *((_DWORD *)v1 + 867);
  v1[376] = v92;
  *((_DWORD *)v1 + 749) = result;
  return result;
}


// Address: 0x0040FEF6; symbol: sub_40FEF6
void __thiscall sub_40FEF6(signed int *this, char a2)
{
  signed int v2; // eax
  signed int *v3; // ebx
  int v4; // eax
  double v5; // ST28_8
  double v6; // st7
  bool v7; // c0
  bool v8; // c3
  double v9; // st7
  double v10; // ST20_8
  double v11; // ST20_8
  double v12; // ST20_8
  double v13; // st7
  bool v14; // c0
  bool v15; // c3
  double v16; // st7
  double v17; // ST20_8
  double v18; // ST20_8
  signed int v19; // eax
  signed int v20; // eax
  signed int v21; // eax
  int v22; // ecx
  int v23; // eax
  double v24; // st7
  double v25; // st6
  signed __int64 v26; // ST40_8
  int v27; // edx
  int v28; // esi
  int v29; // eax
  double v30; // st7
  double v31; // st6
  signed __int64 v32; // ST40_8
  LONG v33; // edi
  LONG v34; // esi
  int v35; // eax
  double v36; // [esp+30h] [ebp-58h]
  double v37; // [esp+30h] [ebp-58h]
  LPARAM dwData; // [esp+50h] [ebp-38h]
  int v39; // [esp+54h] [ebp-34h]
  int v40; // [esp+58h] [ebp-30h]
  int v41; // [esp+5Ch] [ebp-2Ch]
  struct tagRECT Rect; // [esp+60h] [ebp-28h]

  if ( byte_41E168 )
  {
    v2 = this[844];
    v3 = this;
    if ( v2 == -1 )
    {
      this[866] = this[22];
      v4 = this[23] + this[5];
    }
    else if ( v2 )
    {
      this[866] = this[24];
      v4 = this[25] + this[5];
    }
    else
    {
      if ( a2 )
      {
        this[724] = 0;
        sub_40BBDE(this + 192);
      }
      v3[866] = v3[8] * v3[192];
      v4 = v3[5] + v3[7] + v3[9] * v3[193];
    }
    v3[867] = v4;
    sub_40FA4C((double *)v3);
    v36 = (double)v3[870];
    v5 = (double)v3[876] - (double)v3[866] * *((double *)v3 + 426);
    v6 = (v5 - (double)(2 * sub_412DB9())) * 0.5;
    v7 = 0.0 < v6;
    v8 = 0.0 == v6;
    v9 = 0.0;
    if ( v7 != 0 || v8 != 0 )
    {
      v10 = (double)v3[876] - (double)v3[866] * *((double *)v3 + 426);
      v9 = (v10 - (double)(2 * sub_412DB9())) * 0.5;
    }
    v3[868] = (signed int)(v9 + v36);
    v37 = (double)v3[871];
    v11 = (double)v3[877] - (double)v3[867] * *((double *)v3 + 426);
    v12 = v11 - (double)(2 * sub_412D92());
    v13 = (v12 - (double)sub_412E16()) * 0.5;
    v14 = 0.0 < v13;
    v15 = 0.0 == v13;
    v16 = 0.0;
    if ( v14 != 0 || v15 != 0 )
    {
      v17 = (double)v3[877] - (double)v3[867] * *((double *)v3 + 426);
      v18 = v17 - (double)(2 * sub_412D92());
      v16 = (v18 - (double)sub_412E16()) * 0.5;
    }
    v19 = v3[846];
    v3[869] = (signed int)(v16 + v37);
    sub_412478();
    v20 = v3[847];
    sub_412478();
    v21 = v3[866];
    v23 = sub_412A2E(v22, v3[867]);
    v24 = *((double *)v3 + 426);
    v3[846] = v23;
    v25 = v24 * (double)v3[867];
    v26 = (signed __int64)(v24 * (double)v3[866]);
    v3[847] = sub_41251C(v3[182]);
    memset(&dwData, 0, 0x10u);
    if ( !EnumDisplayMonitors(0, 0, fnEnum, (LPARAM)&dwData) )
    {
      v27 = v39;
      v28 = v40 - dwData;
      v3[874] = dwData;
      v29 = v41;
      v3[875] = v27;
      v3[876] = v28;
      v3[877] = v29 - v27;
    }
    v30 = *((double *)v3 + 426);
    v31 = v30 * (double)v3[867];
    v32 = (signed __int64)(v30 * (double)v3[866]);
    v33 = v3[869] + v3[875];
    v34 = v3[868] + v3[874];
    Rect.top = v33;
    Rect.left = v34;
    Rect.bottom = v33 + (unsigned __int64)(signed __int64)v31;
    Rect.right = v34 + v32;
    AdjustWindowRect(&Rect, dwStyle, 0);
    MoveWindow(hWnd, v34, v33, Rect.right - Rect.left, Rect.bottom - Rect.top, 1);
    v35 = sub_40AAE4(0);
    sub_4117A3(v35);
  }
}


// Address: 0x00410270; symbol: sub_410270
int __thiscall sub_410270(int *this, int a2, int a3, int a4, signed int a5)
{
  bool v5; // bl
  signed int v6; // edx
  int result; // eax
  signed int v8; // esi
  int *v9; // esi
  int *v10; // ebx
  int j; // esi
  int i; // esi
  int v13; // eax
  int v14; // edi
  int v15; // edx
  int v16; // eax
  int v17; // eax
  char v18; // cl
  int v19; // eax
  int v20; // edx
  int v21; // eax
  int v22; // eax
  char v23; // cl
  int v24; // eax
  int v25; // edx
  int v26; // eax
  int v27; // edx
  char v28; // ST2C_1
  int v29; // ecx
  int v30; // edi
  int v31; // eax
  int v32; // edx
  int v33; // eax
  int v34; // edx
  char v35; // ST28_1
  int v36; // ecx
  int l; // esi
  int v38; // edi
  int v39; // eax
  int v40; // edx
  int v41; // eax
  int v42; // edx
  char v43; // cl
  int v44; // eax
  int v45; // ecx
  double v46; // st7
  int v47; // eax
  bool v48; // zf
  bool v49; // sf
  int *v50; // [esp+20h] [ebp-58h]
  int k; // [esp+24h] [ebp-54h]
  int v52; // [esp+28h] [ebp-50h]
  int v53; // [esp+2Ch] [ebp-4Ch]
  char v54; // [esp+38h] [ebp-40h]
  int v55[5]; // [esp+4Ch] [ebp-2Ch]
  int v56[6]; // [esp+60h] [ebp-18h]

  v5 = 1;
  v6 = this[760];
  result = a4;
  if ( v6 )
  {
    v8 = this[761];
    v5 = 0;
    if ( v8 <= 12 )
    {
      v9 = &this[v8];
      if ( v9[762] == a2 && v9[775] == a3 )
        v5 = (a4 & v9[788]) > 0;
    }
  }
  if ( (a2 != this[881] || a3 != this[882]) && v6 <= 1 && v5 )
  {
    v10 = this;
    this[758] = a2;
    this[759] = a3;
    if ( a4 == 1 )
    {
      v53 = this[195];
      if ( !this[195] && a3 >= this[197] && a5 > 2 )
      {
        v50 = this + 192;
        if ( v6 == 1 )
        {
          qmemcpy(&v54, &unk_418680, 0x14u);
          qmemcpy(v55, &unk_418694, sizeof(v55));
          for ( i = 0; ; ++i )
          {
            v13 = v10[193];
            if ( v13 <= i )
              break;
            v14 = 0;
            if ( i < v13 - 5 )
            {
              while ( v10[192] > v14 )
              {
                v24 = rand();
                v10[745] = i;
                v25 = v24 % v10[192];
                v26 = v10[203];
                v10[744] = v25;
                v27 = v26 + (v25 << 7);
                v28 = *(_BYTE *)(v27 + i);
                v29 = v14++;
                v29 <<= 7;
                *(_BYTE *)(v27 + i) = *(_BYTE *)(i + v26 + v29);
                *(_BYTE *)(i + v10[203] + v29) = v28;
              }
            }
            else
            {
              v15 = v10[203];
              v10[745] = i;
              v16 = v56[i - v13];
              v10[744] = v16;
              v17 = v15 + (v16 << 7);
              v18 = *(_BYTE *)(v17 + i);
              *(_BYTE *)(v17 + i) = *(_BYTE *)(v15 + i + 128);
              *(_BYTE *)(v10[203] + i + 128) = v18;
              v19 = i - v10[193];
              v20 = v10[203];
              v10[745] = i;
              v21 = v55[v19];
              v10[744] = v21;
              v22 = v20 + (v21 << 7);
              v23 = *(_BYTE *)(v22 + i);
              *(_BYTE *)(v22 + i) = *(_BYTE *)(v20 + i);
              *(_BYTE *)(v10[203] + i) = v23;
            }
          }
        }
        else
        {
          for ( j = 0; v10[193] > j; ++j )
          {
            v30 = 0;
            while ( v10[192] > v30 )
            {
              v31 = rand();
              v10[745] = j;
              v32 = v31 % v10[192];
              v33 = v10[203];
              v10[744] = v32;
              v34 = v33 + (v32 << 7);
              v35 = *(_BYTE *)(v34 + j);
              v36 = v30++;
              v36 <<= 7;
              *(_BYTE *)(v34 + j) = *(_BYTE *)(j + v33 + v36);
              *(_BYTE *)(j + v10[203] + v36) = v35;
            }
          }
          for ( k = 0; v10[194] > k; ++k )
          {
            for ( l = a3 - 1; a3 + 1 >= l; ++l )
            {
              v38 = (a2 - 1) << 7;
              v52 = a2 - 1;
              while ( a2 + 1 >= v52 )
              {
                if ( l >= 0 && v52 >= 0 && l < v10[193] && v52 < v10[192] && *(_BYTE *)(l + v10[203] + v38) )
                {
                  v39 = rand();
                  v10[745] = l;
                  v40 = v39 % v10[192];
                  v41 = v10[203];
                  v10[744] = v40;
                  v42 = v41 + (v40 << 7);
                  v43 = *(_BYTE *)(v42 + l);
                  *(_BYTE *)(v42 + l) = *(_BYTE *)(l + v41 + v38);
                  *(_BYTE *)(l + v10[203] + v38) = v43;
                }
                ++v52;
                v38 += 128;
              }
            }
          }
          v10[744] = a2;
          v10[745] = a3;
          v44 = v10[203];
          if ( *(_BYTE *)(v44 + (a2 << 7) + a3) )
          {
            v45 = v10[192];
            while ( v45 > v53 )
            {
              if ( !*(_BYTE *)(a3 + v44 + (v53 << 7)) )
              {
                v10[744] = v53;
                v10[745] = a3;
              }
              ++v53;
            }
            *(_BYTE *)((v10[744] << 7) + v44 + v10[745]) = 1;
            *(_BYTE *)(v10[203] + (a2 << 7) + a3) = 0;
          }
        }
        sub_40CEC4(v50);
        v46 = sub_412E2B();
        v47 = v10[298];
        *((double *)v10 + 359) = v46;
        v10[195] = 1;
        *((double *)v10 + 360) = v46;
        sub_40E31E((int)(v10 + 210), v47);
      }
      sub_4122D0(a2, a3, 1, a5);
    }
    else if ( a4 == 2 )
    {
      sub_4121F2(a2, a3, 1, a5);
    }
    sub_413B76(v10);
    sub_40CA82((int)(v10 + 192), 1);
    v48 = v10[760] == 0;
    v49 = v10[760] < 0;
    v10[881] = a2;
    v10[882] = a3;
    if ( !v49 && !v48 )
      ++v10[761];
    result = sub_413B76(v10);
  }
  return result;
}


// Address: 0x004106BE; symbol: sub_4106BE
__int16 __thiscall sub_4106BE(LPVOID lpParameter, int a2, int a3, int a4, int a5)
{
  double v5; // st7
  __int16 result; // ax
  double v7; // st6
  int v8; // esi
  int *v9; // ebx
  int v10; // ecx
  int v11; // eax
  int v12; // [esp+10h] [ebp-28h]
  int v13; // [esp+14h] [ebp-24h]
  __int16 v14; // [esp+1Eh] [ebp-1Ah]

  v5 = *((double *)lpParameter + 426);
  result = v14 | 0xC00;
  v7 = (double)a2 / v5;
  v8 = (signed int)((double)a3 / v5);
  if ( (signed int)v7 >= 0 )
  {
    v13 = *((_DWORD *)lpParameter + 5);
    v12 = *((_DWORD *)lpParameter + 7);
    result = v8 - v13;
    if ( v8 - v13 >= v12
      && !*((_DWORD *)lpParameter + 844)
      && *((_DWORD *)lpParameter + 195) <= 3
      && !*((_DWORD *)lpParameter + 196) )
    {
      v9 = (int *)lpParameter;
      v10 = (signed int)v7 / *((_DWORD *)lpParameter + 8);
      if ( v10 >= 0 )
      {
        v11 = (v8 - v12 - v13) / v9[9];
        if ( v10 < v9[192] && v11 >= 0 && v11 < v9[193] )
          sub_410270(v9, v10, v11, a4, a5);
      }
      result = sub_4139D4(v9, (signed int)v7, v8, 0);
    }
  }
  return result;
}


// Address: 0x004107AC; symbol: sub_4107AC
int __thiscall sub_4107AC(LPVOID lpParameter, int a2, int a3, int a4)
{
  signed int *v4; // ebx
  double v5; // st7
  int v6; // esi
  int v7; // eax
  __int64 v8; // rax
  int v9; // edx
  signed __int64 v10; // rt2
  int v11; // eax
  int v12; // ecx
  signed int v13; // edi
  int v14; // ecx
  int v15; // eax
  int v16; // esi
  int v17; // edi
  int v18; // ecx
  signed int v19; // edi
  int v20; // ecx
  int v21; // eax
  signed int v22; // edi
  int v23; // ecx
  int v24; // ecx
  int v25; // ecx
  int v26; // eax
  __int64 v27; // rax
  signed int v28; // esi
  int v29; // ecx
  int v30; // eax
  signed int v31; // esi
  int v32; // edi
  int v33; // ecx
  int v34; // eax
  int v35; // ecx
  int v36; // eax
  signed int v37; // ecx
  int v38; // edx
  int v39; // eax
  int i; // esi
  int v41; // eax
  int v42; // edx
  int v43; // eax
  int v44; // eax
  signed int v45; // esi
  int v46; // eax
  int v47; // eax
  signed int v48; // edx
  int v49; // eax
  double v51; // [esp+94h] [ebp-48h]
  double v52; // [esp+9Ch] [ebp-40h]
  int v53; // [esp+A8h] [ebp-34h]
  int v54; // [esp+ACh] [ebp-30h]
  signed int v55; // [esp+ACh] [ebp-30h]
  int v56; // [esp+ACh] [ebp-30h]
  signed int v57; // [esp+B4h] [ebp-28h]
  int v58; // [esp+B8h] [ebp-24h]
  int savedregs; // [esp+DCh] [ebp+0h]

  v4 = (signed int *)lpParameter;
  v5 = *((double *)lpParameter + 426);
  v54 = *((_DWORD *)lpParameter + 5);
  v58 = (signed int)((double)a2 / v5);
  v57 = (signed int)((double)a3 / v5);
  if ( v57 >= v54 )
  {
    v11 = *((_DWORD *)lpParameter + 844);
    if ( v11 )
    {
      v16 = *((_DWORD *)lpParameter + 17);
      v17 = *((_DWORD *)lpParameter + 16);
      if ( v11 != -1 )
      {
        v24 = *((_DWORD *)lpParameter + 24);
        if ( (unsigned __int8)sub_4140D8(v4[25] + v54 - (v16 + v4[31]) / 2, v17, v16) )
          sub_4138C4(v4, 0);
        v25 = -3 * v4[18];
        v26 = (v4[24] - v4[16]) / 2;
        if ( (unsigned __int8)sub_4140D8(v4[25] - (v4[31] + v4[17]) / 2 + v4[5], v4[20], v4[21]) )
        {
          sub_4138C4(v4, 0);
          sub_40BE12(v4 + 192, 1, v4[879]);
          sub_40FEF6(v4, 0);
          v4[760] = 1;
        }
        v55 = v4[844];
        if ( v55 > 1 )
        {
          v27 = v4[24] - v4[16];
          if ( (unsigned __int8)sub_4140D8(v4[25] - (v4[31] + v4[17]) / 2 + v4[5], v4[18], v4[19]) )
          {
            v4[844] = v55 - 1;
            sub_40EA0C((int)(v4 + 688), (int)&savedregs, v4[708]);
          }
        }
        v28 = v4[844];
        if ( v28 > 0 && v28 < v4[843] )
        {
          v29 = v4[18] + (v4[24] + v4[16]) / 2;
          if ( (unsigned __int8)sub_4140D8(v4[25] - (v4[31] + v4[17]) / 2 + v4[5], v4[18], v4[19]) )
          {
            v30 = v4[708];
            v4[844] = v28 + 1;
            sub_40EA0C((int)(v4 + 688), (int)&savedregs, v30);
            if ( v4[844] == v4[843] )
              sub_40E31E((int)(v4 + 210), v4[302]);
          }
        }
        if ( v4[844] == -2 )
        {
          v31 = v4[6];
          v32 = -5 * v31 / 2 + (v4[24] + (v4[16] + v4[24]) / 2) / 2;
          if ( (unsigned __int8)sub_4140D8(v4[25] - (v4[31] + v4[17]) / 2 + v4[5], 5 * v31, v4[7]) )
          {
            v4[884] = (v58 - v32) / v31;
            sub_40EA0C((int)(v4 + 688), (int)&savedregs, v4[708]);
          }
          v33 = -3 * v4[18];
          v34 = (v4[24] - v4[16]) / 2;
          if ( (unsigned __int8)sub_4140D8(v4[25] - (v4[31] + v4[17]) / 2 + v4[5], v4[20], v4[21]) )
          {
            sub_4138C4(v4, 0);
            sub_40BE12(v4 + 192, 1, v4[879]);
            sub_40FEF6(v4, 0);
            v4[760] = 1;
          }
        }
        if ( v4[844] == -3 )
        {
          v35 = -3 * v4[18];
          v36 = (v4[24] - v4[16]) / 2;
          if ( (unsigned __int8)sub_4140D8(v4[25] - (v4[31] + v4[17]) / 2 + v4[5], v4[20], v4[21]) )
          {
            sub_4138C4(v4, 0);
            sub_40BE12(v4 + 192, 1, v4[879]);
            sub_40FEF6(v4, 0);
            v4[760] = 1;
          }
          v56 = 0;
          v52 = (double)(v4[25] - v4[31] - 2 * v4[9] - v4[7]) / 9.0;
          do
          {
            v37 = v4[8];
            v51 = v52 * (double)v56;
            if ( (unsigned __int8)sub_4140D8((signed int)(v51 + (double)v4[5] + (double)v4[9]), v4[6], v4[7]) )
            {
              switch ( v56 )
              {
                case 0:
                  sub_40EA30(v56, (int)(v4 + 688), (int)&savedregs);
                  break;
                case 1:
                  sub_40F0C0((int)(v4 + 688), v38);
                  break;
                case 2:
                  sub_4136DC(v4);
                  break;
                case 4:
                  v4[850] = v4[850] == 0;
                  sub_40FEF6(v4, 0);
                  v39 = v4[709];
                  goto LABEL_69;
                case 5:
                  sub_413BC8(v4);
                  break;
                case 7:
                  v4[754] = v4[754] == 0;
                  goto LABEL_68;
                case 8:
                  *((_BYTE *)v4 + 3512) ^= 1u;
                  goto LABEL_68;
                case 9:
                  *((_BYTE *)v4 + 3540) ^= 1u;
LABEL_68:
                  v39 = v4[708];
LABEL_69:
                  sub_40EA0C((int)(v4 + 688), (int)&savedregs, v39);
                  break;
                default:
                  break;
              }
            }
            for ( i = 0; ; i = v53 )
            {
              v53 = i + 1;
              v41 = v4[24] / 4;
              if ( (unsigned __int8)sub_4140D8((signed int)(v51 + (double)v4[5] + (double)v4[9]), v4[6], v4[7]) )
              {
                switch ( v56 )
                {
                  case 1:
                    if ( i == 2 )
                      goto LABEL_101;
                    if ( *((unsigned __int8 *)v4 + 2857) == i )
                      sub_40F0C0((int)(v4 + 688), v42);
                    break;
                  case 2:
                    goto LABEL_82;
                  case 3:
                    i += 2;
LABEL_82:
                    if ( v4[879] != i )
                      sub_4136AC(i);
                    break;
                  case 4:
                    if ( v4[850] == i )
                      break;
                    v4[850] = i;
                    sub_40FEF6(v4, 0);
                    v44 = v4[709];
                    goto LABEL_97;
                  case 5:
                    goto LABEL_87;
                  case 6:
                    i += 3;
LABEL_87:
                    if ( v4[172] != i )
                      sub_413B8C(i);
                    break;
                  case 7:
                    if ( i == 2 )
                      goto LABEL_101;
                    if ( v4[754] != i )
                      break;
                    v4[754] = i ^ 1;
                    goto LABEL_96;
                  case 8:
                    if ( i == 2 )
                      goto LABEL_101;
                    if ( *((unsigned __int8 *)v4 + 3512) == i )
                    {
                      *((_BYTE *)v4 + 3512) ^= 1u;
LABEL_96:
                      v44 = v4[708];
LABEL_97:
                      sub_40EA0C((int)(v4 + 688), (int)&savedregs, v44);
                    }
                    break;
                  case 9:
                    if ( i == 2 )
                      goto LABEL_101;
                    if ( *((unsigned __int8 *)v4 + 3540) != i )
                    {
                      *((_BYTE *)v4 + 3540) ^= 1u;
                      sub_40EA0C((int)(v4 + 688), (int)&savedregs, v4[708]);
                    }
                    if ( v53 == 3 )
                      goto LABEL_102;
                    continue;
                  default:
                    if ( i == 2 )
                      goto LABEL_101;
                    v43 = *((unsigned __int8 *)v4 + 2856);
                    if ( v43 == i )
                      sub_40EA30(v43, (int)(v4 + 688), (int)&savedregs);
                    break;
                }
              }
              if ( v53 == 3 )
                break;
            }
LABEL_101:
            ++v56;
          }
          while ( v56 != 10 );
LABEL_102:
          v45 = v4[850];
          if ( v45 > 1 )
          {
            v46 = v4[24] / 4;
            if ( (unsigned __int8)sub_4140D8((signed int)(v52 * 4.0 + (double)v4[5] + (double)v4[9]), v4[6], v4[7]) )
            {
              v4[850] = v45 - (v45 != 2);
              sub_40FEF6(v4, 0);
              sub_40EA0C((int)(v4 + 688), (int)&savedregs, v4[709]);
            }
            v47 = v4[24] / 4;
            if ( (unsigned __int8)sub_4140D8((signed int)(v52 * 4.0 + (double)v4[5] + (double)v4[9]), v4[6], v4[7]) )
            {
              v48 = v4[850];
              v49 = 8;
              if ( v48 <= 7 )
                v49 = v48 + 1;
              v4[850] = v49;
              sub_40FEF6(v4, 0);
              goto LABEL_109;
            }
          }
        }
        return sub_413B76(v4);
      }
      v18 = *((_DWORD *)lpParameter + 22);
      if ( (unsigned __int8)sub_4140D8(v4[23] + v54 - (v16 + v4[31]) / 2, v17, v16) )
        sub_4138C4(v4, 0);
      v19 = v4[27];
      v20 = v4[22] - v19;
      if ( (unsigned __int8)sub_4140D8(v4[5] + (v4[26] - v19) / 2, v4[27], v4[27]) && !*((_BYTE *)v4 + 3381) )
      {
        sub_40EA0C((int)(v4 + 688), (int)&savedregs, v4[712]);
        v21 = v4[303];
        *((_BYTE *)v4 + 3381) = 1;
        *((_BYTE *)v4 + 1189) = 1;
        sub_40E31E((int)(v4 + 210), v21);
      }
      v22 = v4[27];
      v23 = v4[22] - v22;
      if ( !(unsigned __int8)sub_4140D8(v4[5] + (v4[26] - v22) / 2, v4[27], v4[27]) || *((_BYTE *)v4 + 3204) )
        return sub_413B76(v4);
      sub_40EA0C((int)(v4 + 688), (int)&savedregs, v4[712]);
      v15 = v4[303];
      v14 = (int)(v4 + 210);
      *((_BYTE *)v4 + 3204) = 1;
      *((_BYTE *)v4 + 1189) = 1;
    }
    else
    {
      if ( v57 - v54 >= *((_DWORD *)lpParameter + 7) )
      {
        if ( *((_DWORD *)lpParameter + 195) <= 3 && !*((_DWORD *)lpParameter + 196) )
          sub_4106BE(lpParameter, a2, a3, a4, *((_DWORD *)lpParameter + 879) + 4);
        return sub_413B76(v4);
      }
      v12 = *((_DWORD *)lpParameter + 866);
      v13 = v4[6];
      if ( v58 <= (v12 - v13) / 2 || v58 >= (v12 + v13) / 2 )
        return sub_413B76(v4);
      if ( a4 == 1 )
      {
        if ( v4[760] > 0 )
          goto LABEL_4;
        sub_40BBDE(v4 + 192);
        return sub_413B76(v4);
      }
      if ( a4 != 2 || (unsigned int)(v4[195] - 1) > 2 )
        return sub_413B76(v4);
      sub_4121C4(v4 + 192, (v12 + v13) % 2);
      sub_40EA0C((int)(v4 + 688), (int)&savedregs, v4[712]);
      v14 = (int)(v4 + 210);
      v15 = v4[301];
    }
    sub_40E31E(v14, v15);
    return sub_413B76(v4);
  }
  v6 = *((_DWORD *)lpParameter + 4);
  if ( v58 >= 3 * v6 )
  {
    v7 = *((_DWORD *)lpParameter + 866) - 5 * v6;
    if ( v58 > v7 )
    {
      v8 = v58 - v7;
      v10 = v8 % v6;
      LODWORD(v8) = v8 / v6;
      v9 = v10;
      switch ( (_DWORD)v8 )
      {
        case 0:
          sub_413700(lpParameter, v9);
          break;
        case 1:
          sub_4138C4(lpParameter, -2);
          break;
        case 2:
          sub_4138C4(lpParameter, -3);
          break;
        case 3:
          sub_4138C4(lpParameter, 1);
          break;
        case 4:
          sub_4138C4(lpParameter, -1);
          break;
        default:
          return sub_413B76(v4);
      }
    }
  }
  else
  {
    if ( *((_DWORD *)lpParameter + 760) > 0 )
    {
LABEL_4:
      v4[760] = 2;
LABEL_109:
      sub_40EA0C((int)(v4 + 688), (int)&savedregs, v4[709]);
      return sub_413B76(v4);
    }
    *((_DWORD *)lpParameter + 844) = 0;
    sub_40BE12((signed int *)lpParameter + 192, v58 / v6 + 1, *((_DWORD *)lpParameter + 879));
    sub_40FEF6(v4, 0);
  }
  return sub_413B76(v4);
}


// Address: 0x004112E4; symbol: fnEnum
BOOL __stdcall fnEnum(HMONITOR hMonitor, HDC a2, LPRECT a3, LPARAM a4)
{
  BOOL v4; // eax
  signed int v5; // edx
  LONG v6; // edi
  LONG v7; // esi
  LONG v8; // ecx
  int v10; // [esp+18h] [ebp-70h]
  LONG v11; // [esp+1Ch] [ebp-6Ch]
  struct tagMONITORINFO mi; // [esp+28h] [ebp-60h]

  mi.cbSize = 72;
  v11 = sub_412D61();
  v10 = sub_412D30();
  v4 = GetMonitorInfoA(hMonitor, &mi);
  v5 = 1;
  if ( v4 )
  {
    v6 = mi.rcWork.left;
    v7 = mi.rcWork.top;
    v8 = mi.rcWork.bottom;
    if ( v11 <= mi.rcWork.right && v11 >= mi.rcWork.left && v10 >= mi.rcWork.top && v10 <= mi.rcWork.bottom )
    {
      *(_DWORD *)(a4 + 8) = mi.rcWork.right;
      *(_DWORD *)a4 = v6;
      v5 = 0;
      *(_DWORD *)(a4 + 4) = v7;
      *(_DWORD *)(a4 + 12) = v8;
    }
    else
    {
      v5 = 1;
    }
  }
  return v5;
}


// Address: 0x00411371; symbol: sub_411371
void __usercall sub_411371(int a1@<ebp>)
{
  int v1; // [esp+18h] [ebp-4h]

  if ( hWnd )
  {
    v1 = a1;
    sub_412478();
    sub_412478();
    hdc = GetDC(hWnd);
    dword_456284 = (int)hdc;
    dword_45E330 = (int)&dword_456280;
    dword_456288 = dword_4561A0;
    dword_456280 = (int)hWnd;
    dword_45628C = dword_4561A4;
    dword_4561C0 = sub_41251C(0);
    *(_DWORD *)(dword_4561C0 + 16) = 1;
    sub_412D22();
  }
}


// Address: 0x00411402; symbol: StartAddress
DWORD __stdcall StartAddress()
{
  DWORD result; // eax
  struct tagRECT Rect; // [esp+30h] [ebp-18h]
  int savedregs; // [esp+48h] [ebp+0h]

  if ( !word_4562E4 )
  {
    WndClass.style = 3;
    WndClass.lpfnWndProc = (WNDPROC)sub_4115E6;
    WndClass.cbClsExtra = 0;
    WndClass.cbWndExtra = 0;
    WndClass.hInstance = hInstance;
    WndClass.hbrBackground = CreateSolidBrush(color);
    WndClass.lpszMenuName = 0;
    WndClass.lpszClassName = lpClassName;
    word_4562E4 = RegisterClassW(&WndClass);
  }
  Rect.top = Y;
  Rect.left = X;
  Rect.bottom = dword_4561A4 + Y;
  Rect.right = dword_4561A0 + X;
  AdjustWindowRect(&Rect, dwStyle, 0);
  dword_4561A0 = Rect.right - Rect.left;
  dword_4561A4 = Rect.bottom - Rect.top;
  hWnd = CreateWindowExW(
           0,
           lpClassName,
           0,
           dwStyle,
           X,
           Y,
           Rect.right - Rect.left,
           Rect.bottom - Rect.top,
           0,
           0,
           hInstance,
           0);
  sub_411371((int)&savedregs);
  byte_41E168 = 1;
  sub_412E2B();
  result = dword_45E328;
  dword_45E320 = dword_45E328;
  dword_45E324 = dword_45E32C;
  while ( byte_41E168 )
  {
    result = GetMessageA(&Msg, 0, 0, 0);
    if ( Msg.message )
    {
      TranslateMessage(&Msg);
      DispatchMessageA(&Msg);
      dword_456180 = ((_WORD)dword_456180 + 1) & 0xFFF;
      result = (DWORD)&unk_43A180 + 28 * dword_456180;
      qmemcpy((void *)result, &Msg, 0x1Cu);
    }
  }
  return result;
}


// Address: 0x004117A3; symbol: sub_4117A3
void sub_4117A3()
{
  char v0; // cl
  int v1; // eax
  unsigned int v2; // edx
  int v3; // eax
  unsigned int v4; // edx
  char v5; // cl

  sub_412875(0, 0, 0, 0);
  v0 = 0;
  v1 = dword_45E300 + 1;
  dword_45E300 = v1;
  v2 = v1;
  while ( v2 > 0xFFF )
  {
    v2 -= 4096;
    v0 = 1;
  }
  v3 = v1 & 0xFFF;
  if ( v0 )
    dword_45E300 = v3;
  dbl_456300[v3] = sub_412E2B();
  v4 = dword_4562E8;
  v5 = 0;
  while ( dbl_456300[dword_45E300] - 1.0 >= dbl_456300[v4] )
  {
    v5 = 1;
    v4 = v4 - ((v4 + 1) >> 12 << 12) + 1;
  }
  if ( v5 )
    dword_4562E8 = v4;
}


// Address: 0x00411866; symbol: sub_411866
LPSTR __usercall sub_411866@<eax>(LPCSTR lpString2@<ecx>, LPCSTR a2@<edx>, CHAR *lpString1@<eax>)
{
  const CHAR *v3; // esi
  CHAR *v4; // ebx

  v3 = lpString2;
  v4 = lpString1;
  lstrcpyA(lpString1, a2);
  lstrcatA(v4, String2);
  return lstrcatA(v4, v3);
}


// Address: 0x004118A7; symbol: sub_4118A7
BOOL __usercall sub_4118A7@<eax>(const CHAR *a1@<eax>)
{
  HANDLE v1; // eax
  void *v2; // ebx
  int v3; // edx
  const CHAR *lpPathName; // [esp+1Ch] [ebp-36Ch]
  CHAR String2; // [esp+28h] [ebp-360h]
  CHAR FileName; // [esp+12Ch] [ebp-25Ch]
  struct _WIN32_FIND_DATAA FindFileData; // [esp+230h] [ebp-158h]

  lpPathName = a1;
  sub_411866(&::String2[2], a1, &FileName);
  v1 = FindFirstFileA(&FileName, &FindFileData);
  if ( v1 != (HANDLE)-1 )
  {
    v2 = v1;
    do
    {
      sub_411866(FindFileData.cFileName, lpPathName, &String2);
      if ( FindFileData.dwFileAttributes & 0x10 )
      {
        if ( lstrcmpA(FindFileData.cFileName, &::String2[4]) && lstrcmpA(FindFileData.cFileName, "..") )
          sub_4118A7(v3, v3);
      }
      else
      {
        DeleteFileA(&String2);
      }
    }
    while ( FindNextFileA(v2, &FindFileData) );
    FindClose(v2);
  }
  return RemoveDirectoryA(lpPathName);
}


// Address: 0x00411986; symbol: sub_411986
signed int __usercall sub_411986@<eax>(const CHAR *a1@<eax>)
{
  const CHAR *v1; // esi
  char *v2; // eax
  DWORD v3; // eax
  signed int v4; // edx
  HANDLE v5; // eax
  CHAR *v6; // ecx
  void *v7; // ebx
  BOOL v8; // eax
  CHAR *v9; // edx
  LPSTR lpString1; // [esp+0h] [ebp-4B8h]
  LPCSTR lpString2; // [esp+4h] [ebp-4B4h]
  CHAR FileName; // [esp+2Ch] [ebp-48Ch]
  CHAR String1; // [esp+130h] [ebp-388h]
  CHAR String2; // [esp+234h] [ebp-284h]
  CHAR Text; // [esp+338h] [ebp-180h]
  CHAR v17; // [esp+364h] [ebp-154h]

  v1 = a1;
  lstrcpyA(&String1, a1);
  v2 = strrchr(&String1, 46);
  if ( v2 )
    *v2 = 0;
  CreateDirectoryA(&String1, 0);
  if ( SetupIterateCabinetA(v1, 0, MsgHandler, &String1) )
  {
    if ( !strstr(v1, "data.cab") )
      DeleteFileA(v1);
    sub_411866("*.cab", &String1, &FileName);
    v5 = FindFirstFileA(&FileName, (LPWIN32_FIND_DATAA)&Text);
    lpString2 = v6;
    v7 = v5;
    lpString1 = v6;
    v4 = 1;
    if ( v5 != (HANDLE)-1 )
    {
      do
      {
        sub_411866(&v17, &String1, &String2);
        sub_411986(lpString1, lpString2);
        v8 = FindNextFileA(v7, (LPWIN32_FIND_DATAA)&Text);
        lpString2 = v9;
        lpString1 = v9;
      }
      while ( v8 );
      FindClose(v7);
      v4 = 1;
    }
  }
  else
  {
    v3 = GetLastError();
    wsprintfA(&Text, "Failed to extract CAB file: %s. Error code: %lu", v1, v3);
    MessageBoxA(0, &Text, "Error", 0x10u);
    v4 = 0;
  }
  return v4;
}


// Address: 0x00411AE9; symbol: MsgHandler
UINT __stdcall MsgHandler(PVOID Context, UINT Notification, UINT_PTR Param1, UINT_PTR Param2)
{
  UINT result; // eax

  result = 0;
  if ( Notification == 17 )
  {
    sub_411866(*(LPCSTR *)Param1, (LPCSTR)Context, (CHAR *)(Param1 + 18));
    result = 1;
  }
  return result;
}


// Address: 0x00411B10; symbol: sub_411B10
int __fastcall sub_411B10(int a1, int a2, int a3)
{
  int v3; // ebx
  bool v4; // zf
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // edi
  int i; // edx
  int v10; // ecx
  int v11; // esi
  char v12; // cl
  int v13; // esi
  int j; // esi
  int v15; // eax
  int v16; // edi
  int v17; // edx
  char *v18; // edx
  char v19; // ST3C_1
  int v20; // eax
  int v21; // edx
  int v22; // edi
  char v23; // al
  int v24; // edx
  int v25; // eax
  bool v26; // sf
  int v27; // ecx
  int v28; // eax
  int v29; // edx
  int v30; // eax
  int v31; // ST08_4
  int v32; // edx
  int v33; // eax
  int v34; // edx
  int v35; // eax
  int v36; // ecx
  signed int v37; // esi
  int v38; // eax
  int result; // eax
  int v40; // [esp+28h] [ebp-40h]
  int v41; // [esp+34h] [ebp-34h]
  int v42; // [esp+3Ch] [ebp-2Ch]
  int v43[10]; // [esp+40h] [ebp-28h]
  int savedregs; // [esp+68h] [ebp+0h]

  v3 = a1;
  v4 = *(_BYTE *)(a1 + 2436) == 0;
  *(_DWORD *)(a1 + 2172) = 0;
  if ( v4 )
  {
    ++*(_DWORD *)(a1 + 20);
  }
  else
  {
    v5 = *(_DWORD *)(a1 + 2156);
    ++*(_DWORD *)(a1 + 2204);
    v6 = v5 + 1;
    if ( v6 > 999999 )
      v6 = 999999;
    *(_DWORD *)(a1 + 2156) = v6;
    sub_40C342(a1, a2, 0);
  }
  v7 = 0;
  v8 = 0;
  while ( *(_DWORD *)v3 > v8 )
  {
    for ( i = a3; i >= 0; --i )
    {
      v10 = *(_DWORD *)(v3 + 44);
      if ( i )
      {
        *(_BYTE *)(v10 + v7 + i) = *(_BYTE *)(v10 + v7 + i - 1);
        v11 = v7 + *(_DWORD *)(v3 + 52);
        v12 = *(_BYTE *)(v11 + i - 1);
        if ( v12 )
          v12 = *(_BYTE *)(v3 + 2436) ^ 1;
        *(_BYTE *)(v11 + i) = v12;
        *(_BYTE *)(v7 + *(_DWORD *)(v3 + 36) + i) = *(_BYTE *)(v7 + *(_DWORD *)(v3 + 36) + i - 1);
        *(_BYTE *)(v7 + *(_DWORD *)(v3 + 60) + i) = *(_BYTE *)(v7 + *(_DWORD *)(v3 + 60) + i - 1);
        *(_BYTE *)(v7 + *(_DWORD *)(v3 + 64) + i) = *(_BYTE *)(v7 + *(_DWORD *)(v3 + 64) + i - 1);
        *(_BYTE *)(v7 + *(_DWORD *)(v3 + 40) + i) = *(_BYTE *)(v7 + *(_DWORD *)(v3 + 40) + i - 1);
        *(_BYTE *)(v7 + *(_DWORD *)(v3 + 48) + i) = *(_BYTE *)(v7 + *(_DWORD *)(v3 + 48) + i - 1);
        *(_DWORD *)(*(_DWORD *)(v3 + 56) + (v8 << 9) + 4 * i) = *(_DWORD *)(*(_DWORD *)(v3 + 56)
                                                                          + (v8 << 9)
                                                                          + 4 * (i - 1));
      }
      else
      {
        *(_BYTE *)(v10 + v7) = v8 < *(_DWORD *)(v3 + 8);
        *(_BYTE *)(*(_DWORD *)(v3 + 52) + v7) = *(_BYTE *)(v3 + 2152) ^ 1;
        *(_BYTE *)(*(_DWORD *)(v3 + 36) + v7) = 0;
        *(_BYTE *)(*(_DWORD *)(v3 + 60) + v7) = 0;
        *(_BYTE *)(*(_DWORD *)(v3 + 64) + v7) = 0;
        *(_BYTE *)(*(_DWORD *)(v3 + 40) + v7) = 0;
        *(_BYTE *)(*(_DWORD *)(v3 + 48) + v7) = 0;
      }
    }
    ++v8;
    v7 += 128;
  }
  *(_BYTE *)(v3 + 2152) = 0;
  v13 = 0;
  while ( *(_DWORD *)v3 > v13 )
  {
    v15 = rand();
    v16 = *(_DWORD *)(v3 + 44);
    *(_DWORD *)(v3 + 2212) = 0;
    v17 = v15 % *(_DWORD *)v3;
    *(_DWORD *)(v3 + 2208) = v17;
    v18 = (char *)(v16 + (v17 << 7));
    v19 = *v18;
    v20 = v13++;
    v20 <<= 7;
    *v18 = *(_BYTE *)(v16 + v20);
    *(_BYTE *)(*(_DWORD *)(v3 + 44) + v20) = v19;
  }
  for ( j = 0; *(_DWORD *)v3 > j; ++j )
  {
    v21 = *(_DWORD *)(v3 + 4) - 1;
    if ( v21 > a3 + 1 )
      v21 = a3 + 1;
    v42 = j << 9;
    while ( a3 <= v21 )
    {
      *(_DWORD *)(4 * v21 + *(_DWORD *)(v3 + 56) + v42) = 0;
      v22 = 0;
      v41 = v42 + 4 * v21;
      do
      {
        v40 = v21;
        v23 = sub_40BEAE((_DWORD *)v3, v22, j, v21, (int *)(v3 + 28), (int *)(v3 + 32));
        v21 = v40;
        if ( v23 && *(_BYTE *)(*(_DWORD *)(v3 + 44) + (*(_DWORD *)(v3 + 28) << 7) + *(_DWORD *)(v3 + 32)) )
          ++*(_DWORD *)(*(_DWORD *)(v3 + 56) + v41);
        ++v22;
      }
      while ( v22 != 8 );
      v21 = v40 - 1;
    }
  }
  v24 = *(_DWORD *)(v3 + 2204) + 1;
  v25 = *(_DWORD *)(v3 + 2156) + 1;
  v26 = *(_DWORD *)(v3 + 2156) - 999998 < 0;
  *(_DWORD *)(v3 + 2204) = v24;
  if ( !((unsigned __int8)(v26 ^ __OFSUB__(v25, 999999)) | (v25 == 999999)) )
    v25 = 999999;
  v27 = *(_DWORD *)(v3 + 2188);
  *(_DWORD *)(v3 + 2156) = v25;
  if ( v24 == v25 + v27 )
  {
    sub_40E540(v3 + 72, v25, *(_DWORD *)(v3 + 2128), *(_DWORD *)(v3 + 688));
    if ( *(_DWORD *)(v3 + 2256) == 1 )
      sub_40E540(v3 + 72, *(_DWORD *)(v3 + 2156), *(_DWORD *)(v3 + 2128), *(_DWORD *)(v3 + 692));
    sub_40E540(v3 + 72, *(_DWORD *)(v3 + 2156) - *(_DWORD *)(v3 + 2196), *(_DWORD *)(v3 + 2128), *(_DWORD *)(v3 + 696));
    v28 = *(_DWORD *)(v3 + 2128);
    qmemcpy(v43, &unk_4186A8, 0x10u);
    sub_40E604((char *)(v3 + 72), *(_DWORD *)(v3 + 668), v43[v28], v28);
    if ( *(_DWORD *)(v3 + 2156) > 9999 )
      sub_40E31E(v3 + 72, *(_DWORD *)(v3 + 448));
  }
  if ( *(_DWORD *)(v3 + 4) - 3 <= *(_DWORD *)(v3 + 20) )
  {
    v29 = *(_DWORD *)(v3 + 700);
    v30 = *(_DWORD *)(v3 + 2188);
    ++*(_DWORD *)(v3 + 2204);
    v31 = v29;
    v32 = *(_DWORD *)(v3 + 2128);
    *(_DWORD *)(v3 + 2188) = ++v30;
    sub_40E540(v3 + 72, v30, v32, v31);
    v33 = *(_DWORD *)(v3 + 2200);
    if ( v33 < 0 )
      v33 = 0;
    v34 = v33 + *(_DWORD *)(v3 + 2204) + 4;
    v35 = v33 + *(_DWORD *)(v3 + 2156) + 4;
    *(_DWORD *)(v3 + 2204) = v34;
    if ( v35 > 999999 )
      v35 = 999999;
    v36 = *(_DWORD *)(v3 + 2188);
    *(_DWORD *)(v3 + 2156) = v35;
    if ( v34 == v35 + v36 )
    {
      sub_40E540(v3 + 72, v35, *(_DWORD *)(v3 + 2128), *(_DWORD *)(v3 + 688));
      if ( *(_DWORD *)(v3 + 2256) == 1 )
        sub_40E540(v3 + 72, *(_DWORD *)(v3 + 2156), *(_DWORD *)(v3 + 2128), *(_DWORD *)(v3 + 692));
      sub_40E540(
        v3 + 72,
        *(_DWORD *)(v3 + 2156) - *(_DWORD *)(v3 + 2196),
        *(_DWORD *)(v3 + 2128),
        *(_DWORD *)(v3 + 696));
    }
    v37 = 4;
    do
    {
      sub_40C342(v3, v34, 1);
      --v37;
    }
    while ( v37 );
    sub_40CA82(v3, 0);
    v38 = *(_DWORD *)(v3 + 2076);
    *(_DWORD *)(v3 + 12) = 3;
    *(_DWORD *)(v3 + 2200) = 4;
    sub_40EA0C(v3 + 1984, (int)&savedregs, v38);
    sub_40E604((char *)(v3 + 72), *(_DWORD *)(v3 + 664), 1, *(_DWORD *)(v3 + 2128));
  }
  while ( 1 )
  {
    result = *(_DWORD *)(v3 + 2160) + 1;
    if ( result * result > *(_DWORD *)(v3 + 2156) )
      break;
    *(_DWORD *)(v3 + 2160) = result;
    sub_40EA0C(v3 + 1984, (int)&savedregs, *(_DWORD *)(v3 + 2052));
  }
  return result;
}


// Address: 0x00411FFA; symbol: sub_411FFA
char __thiscall sub_411FFA(int *this, int a2, int a3)
{
  int v3; // edx
  int v4; // esi
  int v5; // ebx
  int v6; // edi
  char v7; // al
  int v8; // eax
  int v9; // eax
  int v10; // esi
  int v11; // edx
  int v12; // ecx
  int v13; // eax
  int v14; // ST04_4
  int v15; // eax
  int v17; // [esp+24h] [ebp-24h]
  int *v18; // [esp+28h] [ebp-20h]
  char v19; // [esp+28h] [ebp-20h]
  int *v20; // [esp+2Ch] [ebp-1Ch]
  char v21; // [esp+2Ch] [ebp-1Ch]
  int savedregs; // [esp+48h] [ebp+0h]

  v3 = 0;
  v4 = 0;
  v5 = (int)this;
  v6 = 0;
  v20 = this + 8;
  v18 = this + 7;
  do
  {
    v17 = v3;
    v7 = sub_40BEAE((_DWORD *)v5, v6, a2, a3, v18, v20);
    v3 = v17;
    if ( v7 )
    {
      v8 = *(_DWORD *)(v5 + 28) << 7;
      v4 -= (*(_BYTE *)(*(_DWORD *)(v5 + 32) + v8 + *(_DWORD *)(v5 + 36)) < 1u) - 1;
      v3 = v17 - ((*(_BYTE *)(*(_DWORD *)(v5 + 32) + *(_DWORD *)(v5 + 40) + v8) < 1u) - 1);
    }
    ++v6;
  }
  while ( v6 != 8 );
  v9 = *(_DWORD *)(*(_DWORD *)(v5 + 56) + (a2 << 9) + 4 * a3);
  if ( v9 == v4 || v9 == v3 + v4 )
  {
    v21 = 0;
    v10 = 0;
    do
    {
      LOBYTE(v9) = sub_40BEAE((_DWORD *)v5, v10, a2, a3, (int *)(v5 + 28), (int *)(v5 + 32));
      v19 = v9;
      if ( (_BYTE)v9 )
      {
        v11 = *(_DWORD *)(v5 + 32);
        v9 = *(_DWORD *)(v5 + 28) << 7;
        v12 = v9 + *(_DWORD *)(v5 + 48);
        if ( !*(_BYTE *)(v12 + v11)
          && !*(_BYTE *)(v9 + *(_DWORD *)(v5 + 36) + v11)
          && !*(_BYTE *)(v9 + *(_DWORD *)(v5 + 52) + v11) )
        {
          v9 += *(_DWORD *)(v5 + 40);
          if ( *(_BYTE *)(v9 + v11) )
          {
            if ( !*(_DWORD *)(v5 + 2260) || *(_DWORD *)(v5 + 2272) == 1 )
              *(_BYTE *)(v9 + v11) = 0;
          }
          else
          {
            *(_BYTE *)(v12 + v11) = 1;
            *(_BYTE *)(*(_DWORD *)(v5 + 40) + (*(_DWORD *)(v5 + 28) << 7) + *(_DWORD *)(v5 + 32)) = 0;
            v13 = *(_DWORD *)(v5 + 32);
            *(_BYTE *)(v5 + 2164) = 1;
            *(_BYTE *)(v5 + 2165) = 1;
            *(_BYTE *)(v5 + 2166) = 1;
            *(_BYTE *)(v5 + 2167) = 1;
            v14 = v13;
            v15 = *(_DWORD *)(v5 + 28);
            *(_BYTE *)(v5 + 2168) = 1;
            sub_40CCD0(v5, v15, v14);
            LOBYTE(v9) = v19;
            v21 = v19;
          }
        }
      }
      ++v10;
    }
    while ( v10 != 8 );
    if ( *(_BYTE *)(v5 + 2136) && v21 )
    {
      LOBYTE(v9) = sub_40EA0C(v5 + 1984, (int)&savedregs, *(_DWORD *)(v5 + 2068));
      *(_BYTE *)(v5 + 2136) = 0;
    }
  }
  if ( *(_BYTE *)(v5 + 2136) )
    LOBYTE(v9) = sub_40CE72(v5);
  return v9;
}


// Address: 0x004121C4; symbol: sub_4121C4
int __fastcall sub_4121C4(int a1, int a2)
{
  int v2; // ebx
  int v4; // [esp-4h] [ebp-8h]

  v4 = a2;
  v2 = a1;
  if ( !*(_DWORD *)(a1 + 16) )
    *(double *)(a1 + 2120) = sub_412E2B() - *(double *)(a1 + 2104);
  *(_DWORD *)(v2 + 16) = *(_DWORD *)(v2 + 16) == 0;
  return v4;
}


// Address: 0x004121F2; symbol: sub_4121F2
void __thiscall sub_4121F2(_DWORD *this, int a2, int a3, char a4, signed int a5)
{
  _DWORD *v5; // ebx
  int v6; // eax
  int v7; // eax
  char v8; // cl
  int i; // edx
  int savedregs; // [esp+38h] [ebp+0h]

  v5 = this;
  v6 = a2 << 7;
  if ( !*(_BYTE *)((a2 << 7) + this[13] + a3) && !*(_BYTE *)(v6 + this[9] + a3) )
  {
    if ( *(_BYTE *)(v6 + this[12] + a3) )
    {
      if ( a5 != 5 && a4 )
        sub_40BF70((int)this, a2, a3, 1);
    }
    else if ( a5 > 2 )
    {
      *(_BYTE *)(this[10] + v6 + a3) ^= 1u;
      if ( a4 )
        sub_40EA0C((int)(this + 496), (int)&savedregs, this[518]);
    }
  }
  v7 = v5[3];
  if ( !v7 )
  {
    v8 = 1;
    while ( *v5 > v7 )
    {
      for ( i = v5[5]; v5[1] > i; ++i )
      {
        if ( !*(_BYTE *)(v5[10] + (v7 << 7) + i) )
          v8 = 0;
      }
      ++v7;
    }
    if ( v8 )
      sub_40E31E((int)(v5 + 18), v5[113]);
  }
}


// Address: 0x004122D0; symbol: sub_4122D0
char __thiscall sub_4122D0(_DWORD *this, int a2, int a3, char a4, signed int a5)
{
  char result; // al
  int v6; // edx
  _DWORD *v7; // ebx
  int v8; // ecx
  int savedregs; // [esp+28h] [ebp+0h]

  result = a3;
  v6 = a2 << 7;
  if ( !*(_BYTE *)((a2 << 7) + this[13] + a3) && !*(_BYTE *)(v6 + this[9] + a3) )
  {
    v7 = this;
    v8 = v6 + this[12];
    if ( *(_BYTE *)(v8 + a3) )
    {
      if ( a4 )
      {
        v7[565] = a5 == 5;
        result = sub_40BF70((int)v7, a2, a3, 1);
        v7[565] = 0;
      }
    }
    else if ( a5 > 2 )
    {
      *(_BYTE *)(v8 + a3) = 1;
      *(_BYTE *)(v7[10] + v6 + a3) = 0;
      if ( v7[3] == 2 )
        v7[3] = 1;
      if ( v7[3] == 3 )
        v7[3] = 1;
      result = sub_40CE72((int)v7) - 1;
      if ( result )
      {
        result = a4;
        if ( a4 )
          result = sub_40EA0C((int)(v7 + 496), (int)&savedregs, v7[516]);
      }
    }
  }
  return result;
}


// Address: 0x004123AC; symbol: sub_4123AC
int __usercall sub_4123AC@<eax>(int a1@<eax>, LONG a2@<edx>, LONG a3@<ecx>, int a4, int a5, int a6, int a7)
{
  int v7; // ebx
  bool v8; // zf
  int v9; // esi
  int result; // eax
  RECT rc; // [esp+10h] [ebp-18h]

  v7 = a1;
  v8 = a1 == 0;
  v9 = a6;
  result = a7;
  if ( v8 )
    v7 = dword_4561C0;
  if ( !a6 )
    v9 = 1;
  if ( !a7 )
    result = dword_41E048;
  rc.left = a2;
  rc.top = a3;
  rc.right = a4 + a2;
  rc.bottom = a5 + a3;
  if ( result != 1 )
  {
    if ( result != dword_41863C )
      sub_40EFAF(v7, result);
    result = FillRect(*(HDC *)(v7 + 4), &rc, (HBRUSH)hbr);
  }
  if ( v9 != 1 )
  {
    if ( v9 != dword_41863C )
      sub_40EFAF(v7, v9);
    if ( v9 != dword_418638 )
      sub_40F008(v7, v9);
    result = FrameRect(*(HDC *)(v7 + 4), &rc, (HBRUSH)dword_4561E0);
  }
  return result;
}


// Address: 0x0041246A; symbol: sub_41246A
bool __usercall sub_41246A@<al>(int a1@<eax>)
{
  return dword_456188 == a1;
}


// Address: 0x00412478; symbol: sub_412478
void __usercall sub_412478(int a1@<eax>)
{
  int v1; // ebx
  HDC hDC; // eax

  if ( a1 )
  {
    v1 = a1;
    hDC = *(HDC *)(a1 + 4);
    if ( hDC == hdc )
      ReleaseDC(hWnd, hDC);
    if ( *(HDC *)(v1 + 4) != hdc )
      DeleteDC(*(HDC *)(v1 + 4));
    if ( *(HWND *)v1 != hWnd )
      DeleteObject(*(HGDIOBJ *)v1);
    if ( v1 != dword_45E330 )
      free((void *)v1);
  }
}


// Address: 0x004124DF; symbol: sub_4124DF
int __usercall sub_4124DF@<eax>(int a1@<eax>, int a2@<edx>)
{
  if ( !a1 )
    a1 = dword_4561C0;
  if ( !a2 )
    a2 = color;
  return sub_4123AC(a1, 0, 0, *(_DWORD *)(a1 + 8), *(_DWORD *)(a1 + 12), 0, a2);
}


// Address: 0x0041251C; symbol: sub_41251C
void *__usercall sub_41251C@<eax>(_DWORD *a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4)
{
  int v4; // edi
  int v5; // esi
  int v6; // ST1C_4
  void *v7; // ebx

  v4 = a2;
  v5 = a4;
  if ( !a1 )
    a1 = (_DWORD *)dword_4561C0;
  if ( !a2 )
    v4 = a1[2];
  if ( !a3 )
    a3 = a1[3];
  if ( !a4 )
    v5 = a1[4];
  v6 = a3;
  v7 = calloc(1u, 0x14u);
  *((_DWORD *)v7 + 2) = v4;
  *((_DWORD *)v7 + 4) = v5;
  *((_DWORD *)v7 + 3) = v6;
  while ( !*((_DWORD *)v7 + 1) )
    *((_DWORD *)v7 + 1) = CreateCompatibleDC(hdc);
  while ( !*(_DWORD *)v7 )
    *(_DWORD *)v7 = CreateCompatibleBitmap(hdc, *((_DWORD *)v7 + 2), *((_DWORD *)v7 + 3));
  SelectObject(*((HDC *)v7 + 1), *(HGDIOBJ *)v7);
  sub_4124DF((int)v7, v5);
  return v7;
}


// Address: 0x004125D2; symbol: sub_4125D2
void __usercall sub_4125D2(int a1@<eax>, int a2@<edx>, int xoriginSrc@<ecx>, int yoriginSrc, int a5, int a6, int xoriginDest, int yoriginDest, int a9, int a10, unsigned int a11)
{
  int v11; // esi
  int wDest; // edi
  int hDest; // ebx
  unsigned int v14; // eax
  HDC *v15; // ST38_4
  unsigned int v16; // [esp+3Ch] [ebp-3Ch]
  int v17; // [esp+44h] [ebp-34h]
  int crTransparent; // [esp+50h] [ebp-28h]
  int hSrc; // [esp+54h] [ebp-24h]
  int wSrc; // [esp+58h] [ebp-20h]
  int v21; // [esp+5Ch] [ebp-1Ch]

  v11 = a1;
  v21 = a2;
  v17 = xoriginSrc;
  wDest = a9;
  hDest = a10;
  wSrc = a5;
  hSrc = a6;
  v14 = a11;
  if ( !v11 )
    v11 = dword_4561C0;
  if ( !a2 )
    v21 = dword_4561C0;
  if ( !a5 )
    wSrc = *(_DWORD *)(v11 + 8);
  if ( !a6 )
    hSrc = *(_DWORD *)(v11 + 12);
  if ( !a9 )
    wDest = *(_DWORD *)(v11 + 8);
  if ( !a10 )
    hDest = *(_DWORD *)(v11 + 12);
  if ( !a11 )
    v14 = *(_DWORD *)(v11 + 16);
  crTransparent = v14 & 0xFFFFFF;
  v16 = v14 >> 24;
  if ( v14 >> 24 )
  {
    v15 = (HDC *)sub_41251C(0, wDest, hDest, crTransparent);
    StretchBlt(v15[1], 0, 0, wDest, hDest, *(HDC *)(v21 + 4), xoriginDest, yoriginDest, wDest, hDest, 0xCC0020u);
    TransparentBlt(v15[1], 0, 0, wDest, hDest, *(HDC *)(v11 + 4), v17, yoriginSrc, wSrc, hSrc, crTransparent);
    AlphaBlend(
      *(HDC *)(v21 + 4),
      xoriginDest,
      yoriginDest,
      wDest,
      hDest,
      v15[1],
      0,
      0,
      wDest,
      hDest,
      (BLENDFUNCTION)((unsigned __int8)~(_BYTE)v16 << 16));
    sub_412478((int)v15);
  }
  else
  {
    TransparentBlt(
      *(HDC *)(v21 + 4),
      xoriginDest,
      yoriginDest,
      wDest,
      hDest,
      *(HDC *)(v11 + 4),
      xoriginSrc,
      yoriginSrc,
      wSrc,
      hSrc,
      v14 & 0xFFFFFF);
  }
}


// Address: 0x004127DC; symbol: sub_4127DC
void __usercall sub_4127DC(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4, int a5, unsigned int a6)
{
  sub_4125D2(a1, 0, 0, 0, 0, 0, a2, a3, a4, a5, a6);
}


// Address: 0x00412826; symbol: sub_412826
void __usercall sub_412826(int a1@<eax>, int a2@<edx>, int a3@<ecx>, unsigned int a4)
{
  sub_4127DC(a1, a2, a3, 0, 0, a4);
}


// Address: 0x0041284E; symbol: sub_41284E
void __usercall sub_41284E(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4, int a5)
{
  sub_4127DC(a1, a2, a3, a4, a5, 0);
}


// Address: 0x00412875; symbol: sub_412875
void __usercall sub_412875(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4, int a5, int a6, unsigned int a7)
{
  sub_4125D2(a1, a2, 0, 0, 0, 0, a3, a4, a5, a6, a7);
}


// Address: 0x004128C0; symbol: sub_4128C0
void __usercall sub_4128C0(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4, int a5, int a6)
{
  sub_412875(a1, a2, a3, a4, a5, a6, 0);
}


// Address: 0x004128EE; symbol: sub_4128EE
_DWORD *__usercall sub_4128EE@<eax>(const CHAR *lpMultiByteStr@<eax>)
{
  int v1; // ebx
  _DWORD *v2; // ebx
  float cchWideChar; // ST14_4
  float lpWideCharStr; // ST10_4
  int v6; // [esp+38h] [ebp-10h]
  int v7; // [esp+3Ch] [ebp-Ch]

  v1 = color;
  MultiByteToWideChar(0, 0, lpMultiByteStr, -1, &WideCharStr, 127);
  GdiplusStartup(&dword_45E3D0, &dword_45E3C0, 0);
  GdipLoadImageFromFile(&WideCharStr, &dword_45E388);
  GdipGetImageWidth(dword_45E388, &v6);
  GdipGetImageHeight(dword_45E388, &v7);
  v2 = sub_41251C(0, v6, v7, v1);
  GdipCreateFromHDC(v2[1], &dword_45E384);
  cchWideChar = (double)(unsigned int)v7;
  lpWideCharStr = (double)(unsigned int)v6;
  GdipDrawImageRect(dword_45E384, dword_45E388, 0.0, 0.0, LODWORD(lpWideCharStr), LODWORD(cchWideChar));
  GdipDisposeImage(dword_45E388);
  GdipDeleteGraphics(dword_45E384);
  GdiplusShutdown(dword_45E3D0);
  return v2;
}


// Address: 0x00412A2E; symbol: sub_412A2E
void *__usercall sub_412A2E@<eax>(int a1@<eax>, int a2@<edx>)
{
  return sub_41251C(0, a1, a2, 0);
}


// Address: 0x00412A48; symbol: sub_412A48
int __usercall sub_412A48@<eax>(LONG a1@<eax>, LONG a2@<edx>, int a3@<ecx>, int a4, int a5, int a6)
{
  return sub_4123AC(0, a1, a2, a3, a4, a5, a6);
}


// Address: 0x00412A78; symbol: sub_412A78
BOOL __usercall sub_412A78@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4, int a5)
{
  int y; // esi
  int x; // ebx
  int v7; // edx
  int v8; // edi
  int v10; // [esp+1Ch] [ebp-1Ch]

  y = a2;
  x = a1;
  v7 = a5;
  v10 = a3;
  v8 = dword_4561C0;
  if ( !a5 )
    v7 = dword_41E048;
  if ( v7 != dword_418638 )
    sub_40F008(dword_4561C0, v7);
  MoveToEx(*(HDC *)(v8 + 4), x, y, 0);
  return LineTo(*(HDC *)(v8 + 4), v10 + x, a4 + y);
}


// Address: 0x00412AEC; symbol: sub_412AEC
int __usercall sub_412AEC@<eax>(int *a1@<eax>, _DWORD *a2@<edx>, COLORREF *a3@<ecx>, COLORREF *a4)
{
  int *v4; // ebx
  int v5; // eax

  v4 = a1;
  if ( !*a1 )
    *a1 = dword_4561C0;
  if ( !*(_BYTE *)*a2 )
    *a2 = L"  ";
  if ( !*a3 )
    *a3 = 0xFFFFFF;
  SetTextColor(*(HDC *)(*a1 + 4), *a3);
  v5 = *v4;
  if ( !*a4 )
    return SetBkMode(*(HDC *)(v5 + 4), 1);
  SetBkColor(*(HDC *)(v5 + 4), *a4);
  return SetBkMode(*(HDC *)(*v4 + 4), 2);
}


// Address: 0x00412B70; symbol: sub_412B70
int __usercall sub_412B70@<eax>(int *a1@<eax>, _DWORD *a2@<edx>, COLORREF *a3@<ecx>, COLORREF *a4)
{
  int *v4; // ebx
  int v5; // eax

  v4 = a1;
  if ( !*a1 )
    *a1 = dword_4561C0;
  if ( !*(_WORD *)*a2 )
    *a2 = 4299726;
  if ( !*a3 )
    *a3 = 0xFFFFFF;
  SetTextColor(*(HDC *)(*a1 + 4), *a3);
  v5 = *v4;
  if ( !*a4 )
    return SetBkMode(*(HDC *)(v5 + 4), 1);
  SetBkColor(*(HDC *)(v5 + 4), *a4);
  return SetBkMode(*(HDC *)(*v4 + 4), 2);
}


// Address: 0x00412BF5; symbol: sub_412BF5
unsigned int __usercall sub_412BF5@<eax>(const CHAR *lpString@<eax>)
{
  unsigned int result; // eax

  GetTextExtentPoint32A(hdc, lpString, strlen(lpString), &psizl);
  result = 0;
  if ( psizl.cy > 0 )
    result = (unsigned int)(cHeight * psizl.cx) / psizl.cy;
  return result;
}


// Address: 0x00412C4D; symbol: sub_412C4D
HGDIOBJ __usercall sub_412C4D@<eax>(int a1@<eax>)
{
  int v1; // ebx
  HGDIOBJ result; // eax

  v1 = a1;
  DeleteObject(ho);
  ho = CreateFontA(cHeight, 0, 0, 0, cWeight, 0, 0, 0, 0, 0, 0, 0, 0, pszFaceName);
  result = SelectObject(*(HDC *)(v1 + 4), ho);
  if ( !cHeight )
  {
    GetTextMetricsA(hdc, &tm);
    result = (HGDIOBJ)tm.tmHeight;
    cHeight = tm.tmHeight;
  }
  return result;
}


// Address: 0x00412D22; symbol: sub_412D22
HGDIOBJ sub_412D22()
{
  return sub_412C4D(dword_4561C0);
}


// Address: 0x00412D30; symbol: sub_412D30
LONG __cdecl sub_412D30()
{
  struct tagRECT Rect; // [esp+10h] [ebp-18h]

  memset(&Rect, 0, sizeof(Rect));
  GetWindowRect(hWnd, &Rect);
  return Rect.top;
}


// Address: 0x00412D61; symbol: sub_412D61
LONG sub_412D61()
{
  struct tagRECT Rect; // [esp+10h] [ebp-18h]

  memset(&Rect, 0, sizeof(Rect));
  GetWindowRect(hWnd, &Rect);
  return Rect.left;
}


// Address: 0x00412D92; symbol: sub_412D92
int sub_412D92()
{
  int result; // eax

  if ( dwStyle & 0x40000 )
    result = GetSystemMetrics(33);
  else
    result = GetSystemMetrics(8);
  return result;
}


// Address: 0x00412DB9; symbol: sub_412DB9
int sub_412DB9()
{
  int result; // eax

  if ( dwStyle & 0x40000 )
    result = GetSystemMetrics(32);
  else
    result = GetSystemMetrics(7);
  return result;
}


// Address: 0x00412DE0; symbol: sub_412DE0
int sub_412DE0()
{
  LONG v0; // ebx
  int v1; // ebx
  int v2; // eax
  struct tagPOINT Point; // [esp+18h] [ebp-10h]

  GetCursorPos(&Point);
  v0 = Point.x;
  v1 = v0 - sub_412D61();
  v2 = 0;
  if ( (dwStyle & 0x80000000) == 0 )
    v2 = sub_412DB9();
  return v1 - v2;
}


// Address: 0x00412E16; symbol: sub_412E16
int sub_412E16()
{
  return GetSystemMetrics(4);
}


// Address: 0x00412E2B; symbol: sub_412E2B
double __cdecl sub_412E2B()
{
  LARGE_INTEGER PerformanceCount; // [esp+20h] [ebp-18h]
  LARGE_INTEGER Frequency; // [esp+28h] [ebp-10h]

  if ( QueryPerformanceFrequency(&Frequency) )
    qword_45E338 = Frequency.QuadPart;
  if ( QueryPerformanceCounter(&PerformanceCount) )
    qword_45E328 = PerformanceCount.QuadPart;
  return (double)(PerformanceCount.QuadPart - qword_45E320) / (double)qword_45E338;
}


// Address: 0x00412E98; symbol: sub_412E98
LRESULT sub_412E98()
{
  return SendMessageA(hWnd, 0x10u, 0, 0);
}


// Address: 0x00412EC8; symbol: sub_412EC8
int sub_412EC8()
{
  void *v0; // esp
  int v1; // ecx
  const void *v2; // esi
  int (__thiscall ***v3)(_DWORD, const char *); // eax
  int (__thiscall **v4)(_DWORD, const char *); // edx
  int v6; // [esp+0h] [ebp-1406Ch]
  int v7; // [esp+4h] [ebp-14068h]
  int v8; // [esp+8h] [ebp-14064h]
  int v9; // [esp+Ch] [ebp-14060h]
  int v10; // [esp+10h] [ebp-1405Ch]
  int v11; // [esp+14h] [ebp-14058h]
  int v12; // [esp+18h] [ebp-14054h]
  int v13; // [esp+1Ch] [ebp-14050h]
  int v14; // [esp+20h] [ebp-1404Ch]
  int v15; // [esp+24h] [ebp-14048h]
  int v16; // [esp+28h] [ebp-14044h]
  int v17; // [esp+2Ch] [ebp-14040h]
  int v18; // [esp+30h] [ebp-1403Ch]
  int v19; // [esp+34h] [ebp-14038h]
  int v20; // [esp+38h] [ebp-14034h]
  int v21; // [esp+3Ch] [ebp-14030h]
  int v22; // [esp+40h] [ebp-1402Ch]
  int v23; // [esp+44h] [ebp-14028h]
  int v24; // [esp+48h] [ebp-14024h]
  int v25; // [esp+4Ch] [ebp-14020h]
  int v26; // [esp+50h] [ebp-1401Ch]
  int v27; // [esp+54h] [ebp-14018h]
  int v28; // [esp+58h] [ebp-14014h]
  int v29; // [esp+5Ch] [ebp-14010h]
  char v30; // [esp+64h] [ebp-14008h]
  char v31; // [esp+4064h] [ebp-10008h]
  char v32; // [esp+8064h] [ebp-C008h]
  char v33; // [esp+C064h] [ebp-8008h]
  char v34; // [esp+10064h] [ebp-4008h]
  const char *v35; // [esp+14064h] [ebp-8h]
  int *v36; // [esp+14068h] [ebp-4h]
  int vars0; // [esp+1406Ch] [ebp+0h]

  v0 = alloca(sub_414DF0((char)v35));
  v6 = *(_DWORD *)(v1 + 2896);
  v7 = *(_DWORD *)(v1 + 768);
  v8 = *(_DWORD *)(v1 + 772);
  v9 = *(_DWORD *)(v1 + 776);
  v10 = *(_DWORD *)(v1 + 2916);
  v11 = *(_DWORD *)(v1 + 780);
  v12 = *(_DWORD *)(v1 + 2924);
  v13 = *(_DWORD *)(v1 + 2928);
  v14 = *(_DWORD *)(v1 + 2956);
  v15 = *(_DWORD *)(v1 + 2960);
  v16 = *(_DWORD *)(v1 + 2964);
  v17 = *(_DWORD *)(v1 + 2972);
  v18 = *(_DWORD *)(v1 + 788);
  v19 = *(_DWORD *)(v1 + 792);
  v20 = *(_DWORD *)(v1 + 2908);
  v21 = *(_DWORD *)(v1 + 3044);
  v2 = *(const void **)(v1 + 804);
  v22 = *(_DWORD *)(v1 + 3040);
  v23 = *(_DWORD *)(v1 + 2940);
  v24 = *(_DWORD *)(v1 + 784);
  v25 = *(_DWORD *)(v1 + 3032);
  v26 = *(_DWORD *)(v1 + 3036);
  v27 = *(_DWORD *)(v1 + 2968);
  v28 = *(_DWORD *)(v1 + 3024);
  v29 = *(_DWORD *)(v1 + 3300);
  qmemcpy(&v30, v2, 0x4000u);
  qmemcpy(&v31, *(const void **)(v1 + 808), 0x4000u);
  qmemcpy(&v32, *(const void **)(v1 + 812), 0x4000u);
  qmemcpy(&v33, *(const void **)(v1 + 816), 0x4000u);
  qmemcpy(&v34, *(const void **)(v1 + 820), 0x4000u);
  v3 = (int (__thiscall ***)(_DWORD, const char *))sub_40E28A();
  v4 = *v3;
  vars0 = 82020;
  v35 = "board.dat";
  v36 = &v6;
  return (*v4)(v3, "board.dat");
}


// Address: 0x00413088; symbol: sub_413088
char sub_413088()
{
  void *v0; // esp
  int v1; // ecx
  int v2; // ebx
  int *v3; // eax
  int v4; // edx
  char *v5; // edi
  int v7; // [esp+0h] [ebp-1407Ch]
  int v8; // [esp+4h] [ebp-14078h]
  int v9; // [esp+8h] [ebp-14074h]
  int v10; // [esp+Ch] [ebp-14070h]
  int v11; // [esp+10h] [ebp-1406Ch]
  int v12; // [esp+14h] [ebp-14068h]
  int v13; // [esp+18h] [ebp-14064h]
  int v14; // [esp+1Ch] [ebp-14060h]
  int v15; // [esp+20h] [ebp-1405Ch]
  int v16; // [esp+24h] [ebp-14058h]
  int v17; // [esp+28h] [ebp-14054h]
  int v18; // [esp+2Ch] [ebp-14050h]
  int v19; // [esp+30h] [ebp-1404Ch]
  int v20; // [esp+34h] [ebp-14048h]
  int v21; // [esp+38h] [ebp-14044h]
  int v22; // [esp+3Ch] [ebp-14040h]
  int v23; // [esp+40h] [ebp-1403Ch]
  int v24; // [esp+44h] [ebp-14038h]
  int v25; // [esp+48h] [ebp-14034h]
  int v26; // [esp+4Ch] [ebp-14030h]
  int v27; // [esp+50h] [ebp-1402Ch]
  int v28; // [esp+54h] [ebp-14028h]
  int v29; // [esp+58h] [ebp-14024h]
  int v30; // [esp+5Ch] [ebp-14020h]
  char v31; // [esp+64h] [ebp-14018h]
  char v32; // [esp+4064h] [ebp-10018h]
  char v33; // [esp+8064h] [ebp-C018h]
  char v34; // [esp+C064h] [ebp-8018h]
  char v35; // [esp+10064h] [ebp-4018h]
  const char *v36; // [esp+14070h] [ebp-Ch]
  int *v37; // [esp+14074h] [ebp-8h]
  int v38; // [esp+14078h] [ebp-4h]

  v0 = alloca(sub_414DF0((char)v36));
  v2 = v1;
  v3 = (int *)sub_40E28A();
  v4 = *v3;
  v38 = 82020;
  v36 = "board.dat";
  v37 = &v7;
  (*(void (__thiscall **)(int *, const char *))(v4 + 4))(v3, "board.dat");
  *(_DWORD *)(v2 + 2896) = v7;
  *(_DWORD *)(v2 + 768) = v8;
  *(_DWORD *)(v2 + 772) = v9;
  *(_DWORD *)(v2 + 776) = v10;
  *(_DWORD *)(v2 + 2916) = v11;
  *(_DWORD *)(v2 + 780) = v12;
  *(_DWORD *)(v2 + 2924) = v13;
  *(_DWORD *)(v2 + 2928) = v14;
  *(_DWORD *)(v2 + 2956) = v15;
  *(_DWORD *)(v2 + 2960) = v16;
  *(_DWORD *)(v2 + 2964) = v17;
  *(_DWORD *)(v2 + 2972) = v18;
  *(_DWORD *)(v2 + 788) = v19;
  *(_DWORD *)(v2 + 792) = v20;
  *(_DWORD *)(v2 + 2908) = v21;
  *(_DWORD *)(v2 + 3044) = v22;
  v5 = *(char **)(v2 + 804);
  *(_DWORD *)(v2 + 3040) = v23;
  *(_DWORD *)(v2 + 2940) = v24;
  *(_DWORD *)(v2 + 784) = v25;
  *(_DWORD *)(v2 + 3032) = v26;
  *(_DWORD *)(v2 + 3036) = v27;
  *(_DWORD *)(v2 + 2968) = v28;
  *(_DWORD *)(v2 + 3024) = v29;
  *(_DWORD *)(v2 + 3300) = v30;
  qmemcpy(v5, &v31, 0x4000u);
  qmemcpy(*(void **)(v2 + 808), &v32, 0x4000u);
  qmemcpy(*(void **)(v2 + 812), &v33, 0x4000u);
  qmemcpy(*(void **)(v2 + 816), &v34, 0x4000u);
  qmemcpy(*(void **)(v2 + 820), &v35, 0x4000u);
  return sub_40CEC4((int *)(v2 + 768));
}


// Address: 0x00413256; symbol: sub_413256
int __thiscall sub_413256(double *this, const CHAR *a2)
{
  return (signed __int64)((double)sub_412BF5(a2) / this[426]);
}


// Address: 0x0041329C; symbol: sub_41329C
unsigned int __thiscall sub_41329C(double *this, int a2, const CHAR *a3, signed int a4, signed int a5, int a6, int a7)
{
  double v7; // st7
  int v9; // [esp+30h] [ebp-18h]
  LPCSTR lpString; // [esp+34h] [ebp-14h]
  int v11; // [esp+38h] [ebp-10h]
  int v12; // [esp+3Ch] [ebp-Ch]

  v7 = this[426];
  v9 = a2;
  lpString = a3;
  v11 = a6;
  v12 = a7;
  sub_412AEC(&v9, &lpString, (COLORREF *)&v11, (COLORREF *)&v12);
  TextOutA(*(HDC *)(v9 + 4), (signed int)(v7 * (double)a4), (signed int)(v7 * (double)a5), lpString, strlen(lpString));
  return sub_412BF5(lpString);
}


// Address: 0x0041333E; symbol: sub_41333E
int __thiscall sub_41333E(double *this, int a2, const CHAR *a3, signed int a4, signed int a5, unsigned int a6, unsigned int a7, int a8, int a9)
{
  double v9; // st7
  int v11; // [esp+50h] [ebp-38h]
  LPCSTR lpchText; // [esp+54h] [ebp-34h]
  int v13; // [esp+58h] [ebp-30h]
  int v14; // [esp+5Ch] [ebp-2Ch]
  struct tagRECT rc; // [esp+60h] [ebp-28h]

  v9 = this[426];
  v11 = a2;
  lpchText = a3;
  v13 = a8;
  v14 = a9;
  sub_412AEC(&v11, &lpchText, (COLORREF *)&v13, (COLORREF *)&v14);
  rc.top = (signed int)(v9 * (double)a5);
  rc.left = (signed int)(v9 * (double)a4);
  rc.right = (unsigned __int64)(signed __int64)((double)a6 * v9) + rc.left;
  rc.bottom = (unsigned __int64)(signed __int64)(v9 * (double)a7) + rc.top;
  return DrawTextA(*(HDC *)(v11 + 4), lpchText, strlen(lpchText), &rc, 0x25u);
}


// Address: 0x0041344A; symbol: sub_41344A
int __thiscall sub_41344A(double *this, int a2, const WCHAR *a3, signed int a4, signed int a5, unsigned int a6, unsigned int a7, int a8, int a9)
{
  double v9; // st7
  int cchText; // eax
  int v12; // [esp+50h] [ebp-28h]
  LPCWSTR Str; // [esp+54h] [ebp-24h]
  int v14; // [esp+58h] [ebp-20h]
  int v15; // [esp+5Ch] [ebp-1Ch]
  struct tagRECT rc; // [esp+60h] [ebp-18h]

  v9 = this[426];
  v12 = a2;
  Str = a3;
  v14 = a8;
  v15 = a9;
  sub_412B70(&v12, &Str, (COLORREF *)&v14, (COLORREF *)&v15);
  rc.top = (signed int)(v9 * (double)a5);
  rc.left = (signed int)(v9 * (double)a4);
  rc.right = (unsigned __int64)(signed __int64)((double)a6 * v9) + rc.left;
  rc.bottom = (unsigned __int64)(signed __int64)(v9 * (double)a7) + rc.top;
  cchText = wcslen(Str);
  return DrawTextW(*(HDC *)(v12 + 4), Str, cchText, &rc, 0x25u);
}


// Address: 0x00413552; symbol: sub_413552
int __thiscall sub_413552(double *this, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, UINT format)
{
  double v10; // st7
  int cchText; // eax
  int v13; // [esp+50h] [ebp-28h]
  LPCWSTR Str; // [esp+54h] [ebp-24h]
  int v15; // [esp+58h] [ebp-20h]
  int v16; // [esp+5Ch] [ebp-1Ch]
  struct tagRECT rc; // [esp+60h] [ebp-18h]

  v10 = this[426];
  v13 = a2;
  Str = (LPCWSTR)a3;
  v15 = a8;
  v16 = a9;
  sub_412B70(&v13, &Str, (COLORREF *)&v15, (COLORREF *)&v16);
  rc.top = (signed int)(v10 * (double)a5);
  rc.left = (signed int)(v10 * (double)a4);
  rc.right = (unsigned __int64)(signed __int64)((double)(unsigned int)a6 * v10) + rc.left;
  rc.bottom = (unsigned __int64)(signed __int64)(v10 * (double)(unsigned int)a7) + rc.top;
  cchText = wcslen(Str);
  return DrawTextW(*(HDC *)(v13 + 4), Str, cchText, &rc, format);
}


// Address: 0x00413658; symbol: sub_413658
HGDIOBJ __thiscall sub_413658(double *this, unsigned int a2)
{
  double *v2; // ebx

  v2 = this;
  cHeight = (signed __int64)((double)a2 * this[426]);
  sub_412D22();
  return sub_412C4D(*((_DWORD *)v2 + 847));
}


// Address: 0x004136AC; symbol: sub_4136AC
int __thiscall sub_4136AC(int *this, signed int a2)
{
  int savedregs; // [esp+0h] [ebp+0h]

  this[879] = a2;
  if ( a2 > 1 )
    this[756] = 0;
  return sub_40EA0C((int)(this + 688), (int)&savedregs, this[708]);
}


// Address: 0x004136DC; symbol: sub_4136DC
int __thiscall sub_4136DC(int *this)
{
  return sub_4136AC(this, (this[879] + 1) % 4);
}


// Address: 0x00413700; symbol: sub_413700
int __thiscall sub_413700(void *this)
{
  int v1; // esi
  struct tm *v2; // eax
  _DWORD *v3; // edi
  int v4; // eax
  LPSTR lpBuffer; // [esp+14h] [ebp-244h]
  time_t Time; // [esp+34h] [ebp-224h]
  char Dest; // [esp+38h] [ebp-220h]
  CHAR Buffer; // [esp+13Ch] [ebp-11Ch]
  int savedregs; // [esp+258h] [ebp+0h]

  v1 = (int)this;
  GetTempPathA(0x104u, &Buffer);
  strcat(&Buffer, "screenshot_");
  time(&Time);
  v2 = localtime(&Time);
  sprintf(&Dest, "%d%d%d%d%d%d", v2->tm_mday, v2->tm_mon + 1, v2->tm_year + 1900, v2->tm_hour, v2->tm_min, v2->tm_sec);
  strcat(&Buffer, &Dest);
  strcat(&Buffer, ".png");
  v3 = (_DWORD *)dword_4561C0;
  MultiByteToWideChar(0, 0, &Buffer, -1, &WideCharStr, 127);
  GdiplusStartup(&dword_45E3D0, &dword_45E3C0, 0);
  GdipCreateBitmapFromHBITMAP(*v3, 0, &dword_45E4E0);
  GdipSaveImageToFile(dword_45E4E0, &WideCharStr, &unk_419C00, 0);
  GdipDisposeImage(dword_45E4E0);
  GdiplusShutdown(dword_45E3D0);
  if ( *(_BYTE *)(v1 + 1188) )
  {
    v4 = SteamInternal_ContextInit(&off_4186BC, lpBuffer);
    (*(void (__cdecl **)(CHAR *, _DWORD, _DWORD, _DWORD))(**(_DWORD **)v4 + 4))(
      &Buffer,
      0,
      *(_DWORD *)(dword_4561C0 + 8),
      *(_DWORD *)(dword_4561C0 + 12));
  }
  return sub_40EA0C(v1 + 2752, (int)&savedregs, *(_DWORD *)(v1 + 2848));
}


// Address: 0x004138C4; symbol: sub_4138C4
void __fastcall sub_4138C4(LPVOID lpParameter, int a2, int a3)
{
  signed int *v3; // ebx
  int v4; // eax
  signed int v5; // eax
  signed int v6; // eax
  int savedregs; // [esp+28h] [ebp+0h]

  v3 = (signed int *)lpParameter;
  v4 = *((_DWORD *)lpParameter + 844);
  *((_BYTE *)lpParameter + 3532) = 0;
  if ( v4 || 0 != a3 )
    sub_40EA0C((int)lpParameter + 2752, (int)&savedregs, *((_DWORD *)lpParameter + 708));
  v5 = v3[844];
  if ( v5 <= 0 )
  {
    if ( a3 != v5 && a3 )
    {
      if ( !v5 )
      {
        v6 = v3[195];
        if ( v6 > 0 && !v3[196] && v6 <= 3 )
        {
          sub_4121C4((int)(v3 + 192), a2);
          v3[196] = 2;
        }
      }
      goto LABEL_14;
    }
  }
  else if ( a3 < 0 )
  {
LABEL_14:
    v3[844] = a3;
    goto LABEL_19;
  }
  if ( v3[196] == 2 && (unsigned int)(v3[195] - 1) <= 2 )
    sub_4121C4((int)(v3 + 192), a2);
  v3[844] = 0;
LABEL_19:
  sub_40FEF6(v3, 0);
  if ( v3[844] == -2 && !*((_BYTE *)v3 + 3382) )
    CreateThread(0, 0, sub_40F16C, v3, 0, 0);
}


// Address: 0x004139D4; symbol: sub_4139D4
unsigned __int8 __thiscall sub_4139D4(LPVOID lpParameter, int a2, int a3, int a4)
{
  double *v4; // ebx
  int v5; // edx
  char v6; // al
  int v7; // eax
  int v8; // eax
  int v9; // edx
  int v10; // ST3C_4
  int v11; // esi
  int v12; // edi
  unsigned __int8 result; // al
  unsigned __int8 v14; // ST40_1
  double v15; // st7
  int v16; // edx
  int v17; // eax
  unsigned __int8 v18; // [esp+37h] [ebp-25h]
  int savedregs; // [esp+5Ch] [ebp+0h]

  v4 = (double *)lpParameter;
  v5 = 12 * *((_DWORD *)lpParameter + 8);
  v6 = sub_4140D8(
         *((_DWORD *)v4 + 7) + *((_DWORD *)v4 + 5) + 10 * *((_DWORD *)v4 + 9),
         *((_DWORD *)lpParameter + 16),
         *((_DWORD *)lpParameter + 17));
  if ( *((_DWORD *)v4 + 760) == 1 && (v6 || (_BYTE)a4) )
  {
    v7 = *((_DWORD *)v4 + 761);
    if ( v7 == 13 )
    {
      v8 = *((_DWORD *)v4 + 708);
      ++*((_DWORD *)v4 + 198);
      *((_DWORD *)v4 + 761) = 14;
      sub_40EA0C((int)(v4 + 344), (int)&savedregs, v8);
    }
    else if ( v7 == 14 )
    {
      *((_DWORD *)v4 + 760) = 0;
      v4[359] = sub_412E2B();
      *((_BYTE *)v4 + 3380) = 0;
      sub_4138C4(v4, v9, 1);
    }
  }
  v10 = *((_DWORD *)v4 + 17);
  v11 = *((_DWORD *)v4 + 7) + *((_DWORD *)v4 + 5) + 10 * *((_DWORD *)v4 + 9);
  v12 = 6 * *((_DWORD *)v4 + 8) - 1;
  v18 = sub_4140D8(v11, v12, v10);
  result = sub_4140D8(v11, v12, v10);
  if ( *((_DWORD *)v4 + 760) == 2 )
  {
    if ( result | v18 )
    {
      if ( !(_BYTE)a4 && !v18 )
        goto LABEL_15;
    }
    else if ( !(_BYTE)a4 )
    {
      return result;
    }
    *((_DWORD *)v4 + 760) = 0;
    v14 = result;
    v15 = sub_412E2B();
    v16 = *((_DWORD *)v4 + 708);
    v4[359] = v15;
    *((_BYTE *)v4 + 3380) = 0;
    sub_40EA0C((int)(v4 + 344), (int)&savedregs, v16);
    result = v14;
LABEL_15:
    if ( result )
    {
      v17 = *((_DWORD *)v4 + 708);
      *((_DWORD *)v4 + 760) = 1;
      result = sub_40EA0C((int)(v4 + 344), (int)&savedregs, v17);
    }
  }
  return result;
}


// Address: 0x00413B76; symbol: sub_413B76
int sub_413B76()
{
  return sub_40AAE4(1);
}


// Address: 0x00413B8C; symbol: sub_413B8C
int __thiscall sub_413B8C(_DWORD *this, int a2)
{
  bool v2; // zf
  _DWORD *v3; // ebx
  int savedregs; // [esp+4h] [ebp+0h]

  v2 = byte_41E168 == 0;
  v3 = this;
  this[172] = a2;
  if ( !v2 )
    sub_40D14C((int)this);
  sub_413B76();
  return sub_40EA0C((int)(v3 + 688), (int)&savedregs, v3[709]);
}


// Address: 0x00413BC8; symbol: sub_413BC8
int __thiscall sub_413BC8(_DWORD *this)
{
  return sub_413B8C(this, (this[172] + 1) % 6);
}


// Address: 0x00413EEC; symbol: sub_413EEC
unsigned int __usercall sub_413EEC@<eax>(int a1@<eax>)
{
  int v1; // ebx

  v1 = a1;
  sprintf(Dest, "seek s%lu to %lu", a1, 0);
  sub_40F074();
  sprintf(Dest, "play s%lu%s", v1, &unk_419C39);
  return sub_40F074();
}


// Address: 0x00413F44; symbol: sub_413F44
void __usercall sub_413F44(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4, int a5, int a6, int a7, int a8)
{
  sub_4125D2(a1, a2, a3, a4, a5, a6, 0, 0, a7, a8, 0);
}


// Address: 0x00413F90; symbol: sub_413F90
LSTATUS __usercall sub_413F90@<eax>(HKEY hKey@<eax>, const CHAR *lpValueName@<edx>, int a3@<ecx>)
{
  BYTE Data[4]; // [esp+2Ch] [ebp-Ch]

  *(_DWORD *)Data = a3;
  return RegSetValueExA(hKey, lpValueName, 0, 4u, Data, 4u);
}


// Address: 0x00413FCA; symbol: sub_413FCA
void __thiscall sub_413FCA(_DWORD *this, _DWORD *a2, int a3, int a4, int a5)
{
  _DWORD *v5; // ebx

  v5 = this;
  sub_40F672(this, a2, a3, a4);
  sub_4127DC(v5[149], v5[8] + a3 + v5[8] / 2, v5[9] / 2 + a4 + v5[5] + v5[9] * a5, v5[32], v5[33], 0xC0C0C0u);
}


// Address: 0x00414046; symbol: sub_414046
int __thiscall sub_414046(_DWORD *this, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  _DWORD *v10; // ebx

  v10 = this;
  sub_40F5F2(this, a2, a3, a4, a5, a7, 1, a8, 1, a9, a10);
  return sub_40F528(v10, a6, 7, a9 + v10[8] * (a7 + a8 + 2), a10);
}


// Address: 0x004140D8; symbol: sub_4140D8
bool __usercall sub_4140D8@<al>(int a1@<eax>, int a2@<edx>, int a3@<ecx>, int a4, int a5, int a6)
{
  int v6; // edi
  bool result; // al

  v6 = a1;
  result = a1 > a3 && a2 > a4;
  if ( result )
  {
    result = 0;
    if ( v6 < a5 + a3 )
      result = a2 < a6 + a4;
  }
  return result;
}


// Address: 0x00414108; symbol: timeEndPeriod
MMRESULT __stdcall timeEndPeriod(UINT uPeriod)
{
  return timeEndPeriod(uPeriod);
}


// Address: 0x00414110; symbol: timeBeginPeriod
MMRESULT __stdcall timeBeginPeriod(UINT uPeriod)
{
  return timeBeginPeriod(uPeriod);
}


// Address: 0x00414118; symbol: mciSendStringA
MCIERROR __stdcall mciSendStringA(LPCSTR lpstrCommand, LPSTR lpstrReturnString, UINT uReturnLength, HWND hwndCallback)
{
  return mciSendStringA(lpstrCommand, lpstrReturnString, uReturnLength, hwndCallback);
}


// Address: 0x00414120; symbol: GdiplusStartup
int __stdcall GdiplusStartup(int a1, int a2, int a3)
{
  return GdiplusStartup(a1, a2, a3);
}


// Address: 0x00414128; symbol: GdiplusShutdown
int __stdcall GdiplusShutdown(int a1)
{
  return GdiplusShutdown(a1);
}


// Address: 0x00414130; symbol: GdipSaveImageToFile
int __stdcall GdipSaveImageToFile(int a1, int a2, int a3, int a4)
{
  return GdipSaveImageToFile(a1, a2, a3, a4);
}


// Address: 0x00414138; symbol: GdipLoadImageFromFile
int __stdcall GdipLoadImageFromFile(int a1, int a2)
{
  return GdipLoadImageFromFile(a1, a2);
}


// Address: 0x00414140; symbol: GdipGetImageWidth
int __stdcall GdipGetImageWidth(int a1, int a2)
{
  return GdipGetImageWidth(a1, a2);
}


// Address: 0x00414148; symbol: GdipGetImageHeight
int __stdcall GdipGetImageHeight(int a1, int a2)
{
  return GdipGetImageHeight(a1, a2);
}


// Address: 0x00414158; symbol: GdipDrawImageRect
int __stdcall GdipDrawImageRect(int a1, int a2, int a3, int a4, int a5, int a6)
{
  return GdipDrawImageRect(a1, a2, a3, a4, a5, a6);
}


// Address: 0x00414160; symbol: GdipDisposeImage
int __stdcall GdipDisposeImage(int a1)
{
  return GdipDisposeImage(a1);
}


// Address: 0x00414170; symbol: GdipDeleteGraphics
int __stdcall GdipDeleteGraphics(int a1)
{
  return GdipDeleteGraphics(a1);
}


// Address: 0x00414188; symbol: GdipCreateFromHDC
int __stdcall GdipCreateFromHDC(int a1, int a2)
{
  return GdipCreateFromHDC(a1, a2);
}


// Address: 0x00414190; symbol: GdipCreateBitmapFromHBITMAP
int __stdcall GdipCreateBitmapFromHBITMAP(int a1, int a2, int a3)
{
  return GdipCreateBitmapFromHBITMAP(a1, a2, a3);
}


// Address: 0x004141A8; symbol: TextOutA
BOOL __stdcall TextOutA(HDC hdc, int x, int y, LPCSTR lpString, int c)
{
  return TextOutA(hdc, x, y, lpString, c);
}


// Address: 0x004141B0; symbol: StretchBlt
BOOL __stdcall StretchBlt(HDC hdcDest, int xDest, int yDest, int wDest, int hDest, HDC hdcSrc, int xSrc, int ySrc, int wSrc, int hSrc, DWORD rop)
{
  return StretchBlt(hdcDest, xDest, yDest, wDest, hDest, hdcSrc, xSrc, ySrc, wSrc, hSrc, rop);
}


// Address: 0x004141B8; symbol: SetTextColor
COLORREF __stdcall SetTextColor(HDC hdc, COLORREF color)
{
  return SetTextColor(hdc, color);
}


// Address: 0x004141C8; symbol: SetBkMode
int __stdcall SetBkMode(HDC hdc, int mode)
{
  return SetBkMode(hdc, mode);
}


// Address: 0x004141D0; symbol: SetBkColor
COLORREF __stdcall SetBkColor(HDC hdc, COLORREF color)
{
  return SetBkColor(hdc, color);
}


// Address: 0x004141D8; symbol: SelectObject
HGDIOBJ __stdcall SelectObject(HDC hdc, HGDIOBJ h)
{
  return SelectObject(hdc, h);
}


// Address: 0x004141E0; symbol: MoveToEx
BOOL __stdcall MoveToEx(HDC hdc, int x, int y, LPPOINT lppt)
{
  return MoveToEx(hdc, x, y, lppt);
}


// Address: 0x004141E8; symbol: LineTo
BOOL __stdcall LineTo(HDC hdc, int x, int y)
{
  return LineTo(hdc, x, y);
}


// Address: 0x004141F0; symbol: GetTextMetricsA
BOOL __stdcall GetTextMetricsA(HDC hdc, LPTEXTMETRICA lptm)
{
  return GetTextMetricsA(hdc, lptm);
}


// Address: 0x004141F8; symbol: GetTextExtentPoint32A
BOOL __stdcall GetTextExtentPoint32A(HDC hdc, LPCSTR lpString, int c, LPSIZE psizl)
{
  return GetTextExtentPoint32A(hdc, lpString, c, psizl);
}


// Address: 0x00414200; symbol: GetStockObject
HGDIOBJ __stdcall GetStockObject(int i)
{
  return GetStockObject(i);
}


// Address: 0x00414208; symbol: GetPixel
COLORREF __stdcall GetPixel(HDC hdc, int x, int y)
{
  return GetPixel(hdc, x, y);
}


// Address: 0x00414218; symbol: DeleteObject
BOOL __stdcall DeleteObject(HGDIOBJ ho)
{
  return DeleteObject(ho);
}


// Address: 0x00414220; symbol: DeleteDC
BOOL __stdcall DeleteDC(HDC hdc)
{
  return DeleteDC(hdc);
}


// Address: 0x00414228; symbol: CreateSolidBrush
HBRUSH __stdcall CreateSolidBrush(COLORREF color)
{
  return CreateSolidBrush(color);
}


// Address: 0x00414230; symbol: CreatePen
HPEN __stdcall CreatePen(int iStyle, int cWidth, COLORREF color)
{
  return CreatePen(iStyle, cWidth, color);
}


// Address: 0x00414238; symbol: CreateFontA
HFONT __stdcall CreateFontA(int cHeight, int cWidth, int cEscapement, int cOrientation, int cWeight, DWORD bItalic, DWORD bUnderline, DWORD bStrikeOut, DWORD iCharSet, DWORD iOutPrecision, DWORD iClipPrecision, DWORD iQuality, DWORD iPitchAndFamily, LPCSTR pszFaceName)
{
  return CreateFontA(
           cHeight,
           cWidth,
           cEscapement,
           cOrientation,
           cWeight,
           bItalic,
           bUnderline,
           bStrikeOut,
           iCharSet,
           iOutPrecision,
           iClipPrecision,
           iQuality,
           iPitchAndFamily,
           pszFaceName);
}


// Address: 0x00414240; symbol: CreateCompatibleDC
HDC __stdcall CreateCompatibleDC(HDC hdc)
{
  return CreateCompatibleDC(hdc);
}


// Address: 0x00414248; symbol: CreateCompatibleBitmap
HBITMAP __stdcall CreateCompatibleBitmap(HDC hdc, int cx, int cy)
{
  return CreateCompatibleBitmap(hdc, cx, cy);
}


// Address: 0x00414250; symbol: TransparentBlt
BOOL __stdcall TransparentBlt(HDC hdcDest, int xoriginDest, int yoriginDest, int wDest, int hDest, HDC hdcSrc, int xoriginSrc, int yoriginSrc, int wSrc, int hSrc, UINT crTransparent)
{
  return TransparentBlt(
           hdcDest,
           xoriginDest,
           yoriginDest,
           wDest,
           hDest,
           hdcSrc,
           xoriginSrc,
           yoriginSrc,
           wSrc,
           hSrc,
           crTransparent);
}


// Address: 0x00414258; symbol: AlphaBlend
BOOL __stdcall AlphaBlend(HDC hdcDest, int xoriginDest, int yoriginDest, int wDest, int hDest, HDC hdcSrc, int xoriginSrc, int yoriginSrc, int wSrc, int hSrc, BLENDFUNCTION ftn)
{
  return AlphaBlend(hdcDest, xoriginDest, yoriginDest, wDest, hDest, hdcSrc, xoriginSrc, yoriginSrc, wSrc, hSrc, ftn);
}


// Address: 0x004142A0; symbol: sub_4142A0
int sub_4142A0()
{
  const char *v0; // esi
  void *v1; // esp
  char *v2; // edx
  int v3; // eax
  int v4; // ecx
  char v5; // bl
  char *v6; // ecx
  char *v7; // eax
  int result; // eax
  int v9; // edi
  bool v10; // cl
  int v11; // edi
  char *v12; // eax
  char *v13; // edi
  char *v14; // ecx
  int v15; // ebx
  char *v16; // edi
  char *Str; // [esp+0h] [ebp-58h]
  char v18; // [esp+10h] [ebp-48h]
  int v19; // [esp+18h] [ebp-40h]
  char **v20; // [esp+1Ch] [ebp-3Ch]
  int v21; // [esp+20h] [ebp-38h]
  char *v22; // [esp+24h] [ebp-34h]
  int v23; // [esp+28h] [ebp-30h]
  int v24; // [esp+2Ch] [ebp-2Ch]
  int v25; // [esp+30h] [ebp-28h]
  int v26; // [esp+34h] [ebp-24h]
  int v27; // [esp+38h] [ebp-20h]
  int v28; // [esp+3Ch] [ebp-1Ch]

  if ( !(dword_4186C8 & 2) )
    return sub_4012A0();
  v20 = &Str;
  v0 = GetCommandLineA();
  strlen(v0);
  v1 = alloca(sub_414DF0((char)Str));
  v28 = 0;
  v24 = 0;
  v23 = 0;
  v2 = &v18;
  v22 = &v18;
  v21 = dword_4186C8 & 0x4400 | 0x10;
  v3 = 0;
LABEL_3:
  while ( 1 )
  {
    v4 = *(++v0 - 1);
    v5 = *(v0 - 1);
    if ( !*(v0 - 1) )
      break;
    while ( 1 )
    {
      if ( v5 == 63 )
        goto LABEL_40;
      if ( v5 > 63 )
      {
        switch ( v5 )
        {
          case 92:
            if ( v24 == 39 )
              *v2++ = 92;
            else
              ++v3;
            goto LABEL_3;
          case 127:
            goto LABEL_40;
          case 91:
            if ( dword_4186C8 & 0x20 )
            {
LABEL_40:
              v9 = v3 - 1;
              if ( v3 )
              {
                v10 = v24 != 0 || v4 == 127;
                goto LABEL_26;
              }
              v10 = v24 != 0 || v4 == 127;
              v12 = v2;
LABEL_28:
              if ( v10 )
              {
                v2 = v12;
                goto LABEL_31;
              }
            }
            else
            {
              v9 = v3 - 1;
              v10 = 1;
              if ( v3 )
              {
LABEL_26:
                v11 = (int)&v2[v9 + 1];
                v12 = v2;
                do
                  *(++v12 - 1) = 92;
                while ( v12 != (char *)v11 );
                goto LABEL_28;
              }
LABEL_31:
              v12 = v2 + 1;
              *v2 = 127;
            }
            v2 = v12 + 1;
            *v12 = v5;
            v3 = 0;
            goto LABEL_3;
        }
LABEL_32:
        v13 = &v2[v3];
        if ( v3 )
        {
          do
            *(++v2 - 1) = 92;
          while ( v2 != v13 );
        }
        else
        {
          v13 = v2;
        }
        if ( v24 )
        {
LABEL_39:
          v2 = v13 + 1;
          *v13 = v5;
          v3 = 0;
          goto LABEL_3;
        }
        if ( _mb_cur_max == 1 )
        {
          if ( !(pctype[v4] & 0x40) )
            goto LABEL_38;
        }
        else
        {
          v19 = v4;
          if ( !isctype(v4, 64) )
          {
            v4 = v19;
LABEL_38:
            if ( v4 != 9 )
              goto LABEL_39;
          }
        }
        if ( v22 < v13 || v23 )
        {
          *v13 = 0;
          v15 = v21;
          v16 = v22;
          sub_415DC0(v22, v21, 0, (int)&v25);
          v2 = v16;
          v23 = 0;
          v21 = v15 | 1;
          v3 = 0;
        }
        else
        {
          v2 = v13;
          v3 = 0;
          v23 = 0;
        }
        goto LABEL_3;
      }
      if ( v5 == 39 )
        break;
      if ( v5 == 42 )
        goto LABEL_40;
      if ( v5 != 34 )
        goto LABEL_32;
      if ( v3 >> 1 )
      {
        v6 = &v2[v3 >> 1];
        do
          *(++v2 - 1) = 92;
        while ( v2 != v6 );
      }
      else
      {
        v6 = v2;
      }
      if ( v24 == 39 || v3 & 1 )
      {
        v2 = v6 + 1;
        *v6 = 34;
        v3 = 0;
        v23 = 1;
        goto LABEL_3;
      }
      ++v0;
      v2 = v6;
      v24 ^= 0x22u;
      v4 = *(v0 - 1);
      v3 = 0;
      v23 = 1;
      v5 = v4;
      if ( !v4 )
        goto LABEL_15;
    }
    if ( !(dword_4186C8 & 0x10) )
      goto LABEL_32;
    if ( v3 >> 1 )
    {
      v14 = &v2[v3 >> 1];
      do
        *(++v2 - 1) = 92;
      while ( v2 != v14 );
    }
    else
    {
      v14 = v2;
    }
    if ( v24 == 34 || v3 & 1 )
    {
      v2 = v14 + 1;
      *v14 = 39;
      v3 = 0;
      v23 = 1;
    }
    else
    {
      v24 ^= 0x27u;
      v2 = v14;
      v3 = 0;
      v23 = 1;
    }
  }
LABEL_15:
  if ( v3 )
  {
    v7 = &v2[v3];
    do
      *(++v2 - 1) = 92;
    while ( v2 != v7 );
  }
  else
  {
    v7 = v2;
  }
  if ( v22 < v7 || v23 )
  {
    *v7 = 0;
    sub_415DC0(v22, v21, 0, (int)&v25);
  }
  dword_41E004 = v26;
  result = v27;
  dword_41E000 = v27;
  return result;
}


// Address: 0x00414640; symbol: sub_414640
unsigned int sub_414640()
{
  unsigned int v0; // et0
  unsigned int v1; // ST04_4
  unsigned int v2; // et0
  unsigned int v3; // eax
  unsigned int v4; // et0
  unsigned int result; // eax

  v0 = __getcallerseflags();
  v1 = v0;
  v2 = __readeflags();
  v3 = v2;
  __writeeflags(v2 ^ 0x200000);
  v4 = __readeflags();
  __writeeflags(v1);
  result = v4 ^ v3;
  if ( result & 0x200000 )
  {
    _EAX = 0;
    __asm { cpuid }
    if ( result )
    {
      _EAX = 1;
      __asm { cpuid }
      if ( _EDX & 0x100 )
        dword_45E5A4 |= 1u;
      if ( (_EDX & 0x8000) != 0 )
        dword_45E5A4 |= 2u;
      if ( _EDX & 0x800000 )
        dword_45E5A4 |= 4u;
      if ( _EDX & 0x1000000 )
        dword_45E5A4 |= 8u;
      if ( _EDX & 0x2000000 )
        dword_45E5A4 |= 0x10u;
      if ( _EDX & 0x4000000 )
        dword_45E5A4 |= 0x20u;
      if ( _ECX & 1 )
        dword_45E5A4 |= 0x40u;
      if ( _ECX & 0x2000 )
        dword_45E5A4 |= 0x80u;
      _EAX = 2147483648;
      __asm { cpuid }
      if ( result > 0x80000000 )
      {
        _EAX = -2147483647;
        __asm { cpuid }
        if ( _EDX < 0 )
          dword_45E5A4 |= 0x100u;
        if ( _EDX & 0x40000000 )
          dword_45E5A4 |= 0x200u;
      }
    }
  }
  return result;
}


// Address: 0x00414720; symbol: sub_414720
void __cdecl sub_414720()
{
  void (*v0)(void); // eax

  v0 = (void (*)(void))(*off_4186D4)[0];
  if ( (*off_4186D4)[0] )
  {
    do
    {
      v0();
      v0 = (void (*)(void))(*off_4186D4)[1];
      off_4186D4 = (int (*)[11])((char *)off_4186D4 + 4);
    }
    while ( v0 );
  }
}


// Address: 0x004147A0; symbol: sub_4147A0
int sub_4147A0()
{
  int i; // ebx
  int result; // eax

  result = dword_45E5A8;
  if ( !dword_45E5A8 )
  {
    dword_45E5A8 = 1;
    for ( i = 0; dword_4171C0[i + 1]; ++i )
      ;
    for ( ; i; --i )
      ((void (*)(void))dword_4171C0[i])();
    result = atexit(sub_414720);
  }
  return result;
}


// Address: 0x004147C0; symbol: TlsCallback_1
signed int __stdcall TlsCallback_1(int a1, int a2, int a3)
{
  if ( a2 != 3 && a2 )
    return 1;
  sub_414A40(a1, a2);
  return 1;
}


// Address: 0x00414810; symbol: TlsCallback_0
signed int __stdcall TlsCallback_0(int a1, int a2, int a3)
{
  if ( dword_45E5E4 != 2 )
    dword_45E5E4 = 2;
  if ( a2 != 2 && a2 == 1 )
    sub_414A40(a1, 1);
  return 1;
}


// Address: 0x004148B0; symbol: sub_4148B0
void sub_4148B0()
{
  int i; // ebx
  LPVOID v1; // esi

  EnterCriticalSection(&CriticalSection);
  for ( i = dword_45E5BC; i; i = *(_DWORD *)(i + 8) )
  {
    v1 = TlsGetValue(*(_DWORD *)i);
    if ( !GetLastError() && v1 )
      (*(void (__cdecl **)(LPVOID))(i + 4))(v1);
  }
  LeaveCriticalSection(&CriticalSection);
}


// Address: 0x00414A40; symbol: sub_414A40
signed int __cdecl sub_414A40(int a1, unsigned int a2)
{
  signed int result; // eax

  if ( a2 == 1 )
  {
    if ( !dword_45E5C0 )
      InitializeCriticalSection(&CriticalSection);
    dword_45E5C0 = 1;
    result = 1;
  }
  else
  {
    if ( a2 < 1 )
    {
      if ( dword_45E5C0 )
        sub_4148B0();
      if ( dword_45E5C0 == 1 )
      {
        dword_45E5C0 = 0;
        DeleteCriticalSection(&CriticalSection);
      }
    }
    else if ( a2 == 3 )
    {
      if ( dword_45E5C0 )
        sub_4148B0();
    }
    result = 1;
  }
  return result;
}


// Address: 0x00414AE0; symbol: sub_414AE0
void __noreturn sub_414AE0(char *Format, ...)
{
  va_list va; // [esp+24h] [ebp+8h]

  va_start(va, Format);
  fwrite("Mingw runtime failure:\n", 1u, 0x17u, (FILE *)&iob[16]);
  vfprintf((FILE *)&iob[16], Format, va);
  abort();
}


// Address: 0x00414B30; symbol: sub_414B30
void *__usercall sub_414B30@<eax>(size_t Size@<ecx>, void *Src@<edx>, void *lpAddress@<eax>)
{
  size_t v3; // edi
  void *v4; // ebx
  void *v5; // esi
  void *result; // eax
  DWORD v7; // [esp+1Ch] [ebp-40h]
  DWORD flOldProtect; // [esp+20h] [ebp-3Ch]
  struct _MEMORY_BASIC_INFORMATION Buffer; // [esp+24h] [ebp-38h]

  v3 = Size;
  v4 = lpAddress;
  v5 = Src;
  if ( !VirtualQuery(lpAddress, &Buffer, 0x1Cu) )
    sub_414AE0("  VirtualQuery failed for %d bytes at address %p", 28, v4);
  if ( Buffer.Protect == 64 || Buffer.Protect == 4 )
    return memcpy(v4, v5, v3);
  VirtualProtect(Buffer.BaseAddress, Buffer.RegionSize, 0x40u, &flOldProtect);
  v7 = Buffer.Protect;
  result = memcpy(v4, v5, v3);
  if ( v7 != 64 && v7 != 4 )
    result = (void *)VirtualProtect(Buffer.BaseAddress, Buffer.RegionSize, flOldProtect, &flOldProtect);
  return result;
}


// Address: 0x00414C20; symbol: sub_414C20
int sub_414C20()
{
  int result; // eax

  result = dword_45E5DC;
  if ( !dword_45E5DC )
  {
    dword_45E5DC = 1;
    result = 0;
  }
  return result;
}


// Address: 0x00414DF0; symbol: sub_414DF0
void __usercall __spoils<ecx> sub_414DF0(unsigned int a1@<eax>, int a2@<ecx>, char a3)
{
  char *v3; // ecx
  int v4; // [esp-4h] [ebp-4h]

  v4 = a2;
  v3 = &a3;
  if ( a1 >= 0x1000 )
  {
    do
    {
      v3 -= 4096;
      *(_DWORD *)v3 = *(_DWORD *)v3;
      a1 -= 4096;
    }
    while ( a1 > 0x1000 );
  }
  *(_DWORD *)&v3[-a1] = *(_DWORD *)&v3[-a1];
}


// Address: 0x00414E20; symbol: sub_414E20
int __cdecl sub_414E20(int a1)
{
  unsigned int v3; // [esp+Ch] [ebp-10h]

  _EAX = a1;
  v3 = 8064;
  if ( a1 == -3 )
  {
    dword_4186D8 = -1;
    goto LABEL_12;
  }
  if ( a1 != -4 )
  {
    if ( !a1 )
      _EAX = dword_4186D8;
    if ( _EAX != -1 )
    {
      if ( _EAX != -2 )
      {
        __asm { fldenv  byte ptr [eax] }
        v3 = *(unsigned __int16 *)(_EAX + 28);
        goto LABEL_8;
      }
      goto LABEL_14;
    }
LABEL_12:
    __asm { fninit }
    goto LABEL_8;
  }
  dword_4186D8 = -2;
LABEL_14:
  fpreset();
LABEL_8:
  if ( dword_45E5A4 & 0x10 )
    _mm_setcsr(v3);
  return 0;
}


// Address: 0x00414E90; symbol: sub_414E90
signed int __usercall sub_414E90@<eax>(char *a1@<eax>, unsigned int a2@<edx>)
{
  signed int v2; // ecx
  char v3; // bl
  int i; // edx
  bool v5; // zf

  if ( !a1 )
    return 0;
  v2 = 0;
  v3 = ((a2 >> 5) ^ 1) & 1;
LABEL_3:
  for ( i = *a1; *a1; v2 = v5 )
  {
    if ( v3 && i == 127 )
    {
      if ( !a1[1] )
        return 0;
      a1 += 2;
    }
    else
    {
      ++a1;
    }
    if ( v2 )
    {
      if ( v2 <= 1 || i != 93 )
      {
        v2 += i != 33;
        goto LABEL_3;
      }
      return 1;
    }
    if ( i == 42 || i == 63 )
      return 1;
    v5 = i == 91;
    i = *a1;
  }
  return i;
}


// Address: 0x00414F30; symbol: sub_414F30
signed int __usercall sub_414F30@<eax>(int a1@<eax>)
{
  int v1; // esi
  int v2; // ebx
  _DWORD *v3; // eax
  _DWORD *v4; // ecx
  signed int result; // eax
  int v6; // edx

  if ( !a1 )
    return 0;
  v1 = a1;
  v2 = *(_DWORD *)(a1 + 12) + 1;
  v3 = malloc(4 * v2);
  v4 = v3;
  *(_DWORD *)(v1 + 8) = v3;
  result = 3;
  if ( v4 )
  {
    v6 = v2;
    *(_DWORD *)(v1 + 4) = 0;
    if ( v2 > 0 )
    {
      do
        v4[--v6] = 0;
      while ( v6 );
    }
    result = 0;
  }
  return result;
}


// Address: 0x00414FA0; symbol: sub_414FA0
int __usercall sub_414FA0@<eax>(char *a1@<eax>, int a2@<edx>, __int16 a3@<cx>)
{
  char *v3; // edi
  int v4; // ebx
  int C; // ebp
  char *v6; // esi
  char v7; // dl
  char v8; // ST24_1
  int v9; // esi
  int v10; // eax
  int v11; // eax
  int v12; // ebp
  int v13; // edi
  char *v14; // esi
  char v15; // al
  char v17; // al
  int v18; // edi
  int v19; // ebp
  char v20; // al
  int v21; // [esp+1Ch] [ebp-30h]
  __int16 v22; // [esp+20h] [ebp-2Ch]
  int v23; // [esp+24h] [ebp-28h]
  int v24; // [esp+28h] [ebp-24h]
  int v25; // [esp+2Ch] [ebp-20h]

  v3 = a1;
  v4 = *a1;
  v21 = a2;
  v22 = a3;
  C = *a1;
  if ( v4 != 93 && v4 != 45 )
    goto LABEL_3;
  if ( v4 == a2 )
  {
    v3 = a1 + 1;
    while ( 1 )
    {
      v17 = *v3;
      if ( *v3 == 93 )
        return (int)(v3 + 1);
      if ( v17 != 127 )
        goto LABEL_45;
      if ( a3 & 0x20 )
      {
        ++v3;
      }
      else
      {
        v17 = (v3++)[1];
LABEL_45:
        ++v3;
        if ( !v17 )
          return 0;
      }
    }
  }
  v4 = a1[1];
  v3 = a1 + 1;
LABEL_3:
  v24 = ~a2;
  v25 = 1 - a2;
  while ( 1 )
  {
    v6 = v3 + 1;
    if ( v4 == 93 )
      return 0;
    if ( v4 != 45 )
    {
      if ( !v4 )
        return 0;
      goto LABEL_9;
    }
    v7 = v3[1];
    if ( v7 == 93 )
    {
      C = 45;
      ++v3;
      goto LABEL_12;
    }
    v4 = v7;
    if ( !v7 )
      return 0;
    v6 = v3 + 2;
    if ( C < v7 )
      break;
    if ( C > v7 )
    {
      v23 = (int)(v3 + 2);
      do
      {
        v18 = C - 1;
        if ( v22 & 0x4000 )
        {
          if ( !(v25 + v18) )
            goto LABEL_58;
        }
        else
        {
          v19 = tolower(C);
          if ( v19 == tolower(v21) )
          {
LABEL_58:
            v14 = (char *)v23;
            while ( 1 )
            {
              v20 = *v14;
              if ( *v14 == 93 )
                return (int)(v14 + 1);
              if ( v20 != 127 )
                goto LABEL_61;
              if ( v22 & 0x20 )
              {
                ++v14;
              }
              else
              {
                v20 = (v14++)[1];
LABEL_61:
                ++v14;
                if ( !v20 )
                  return 0;
              }
            }
          }
        }
        C = v18;
      }
      while ( v4 != v18 );
LABEL_37:
      v6 = (char *)v23;
    }
LABEL_9:
    if ( v4 == 47 || v4 == 92 )
      return 0;
    v7 = *v6;
    C = v4;
    v3 = v6;
LABEL_12:
    if ( v22 & 0x4000 )
    {
      if ( C == v21 )
        goto LABEL_17;
    }
    else
    {
      v8 = v7;
      v9 = tolower(C);
      v10 = tolower(v21);
      v7 = v8;
      if ( v9 == v10 )
      {
        while ( 1 )
        {
LABEL_17:
          if ( v7 == 93 )
            return (int)(v3 + 1);
          if ( v7 == 127 )
          {
            if ( v22 & 0x20 )
            {
              ++v3;
              goto LABEL_16;
            }
            v7 = (v3++)[1];
          }
          ++v3;
          if ( !v7 )
            return 0;
LABEL_16:
          v7 = *v3;
        }
      }
    }
    v4 = v7;
  }
  v23 = (int)(v3 + 2);
  v11 = C;
  while ( 1 )
  {
    v12 = v11 + 1;
    if ( v22 & 0x4000 )
    {
      if ( !(v24 + v12) )
        break;
      goto LABEL_26;
    }
    v13 = tolower(v11);
    if ( v13 == tolower(v21) )
      break;
LABEL_26:
    v11 = v12;
    if ( v4 == v12 )
      goto LABEL_37;
  }
  v14 = (char *)v23;
  while ( 1 )
  {
    v15 = *v14;
    if ( *v14 == 93 )
      return (int)(v14 + 1);
    while ( v15 == 127 )
    {
      if ( !(v22 & 0x20) )
      {
        v15 = (v14++)[1];
        break;
      }
      v15 = *++v14;
      if ( *v14 == 93 )
        return (int)(v14 + 1);
    }
    ++v14;
    if ( !v15 )
      return 0;
  }
}


// Address: 0x00415260; symbol: sub_415260
int __usercall sub_415260@<eax>(char *a1@<eax>, _BYTE *a2@<edx>, unsigned int a3@<ecx>)
{
  char *v3; // ebp
  char v4; // cl
  int v5; // edi
  int C; // edx
  char *v7; // esi
  char *v8; // eax
  int v9; // ebx
  int v10; // ST1C_4
  int v11; // esi
  int v12; // eax
  int v13; // esi
  int result; // eax
  char v15; // dl
  _BYTE *v16; // ebx
  int v17; // edx
  char *v18; // ebx
  char v19; // al
  unsigned int v20; // [esp+14h] [ebp-28h]

  v3 = a1;
  v20 = a3;
  v4 = *a1;
  if ( *a2 == 46 && v4 != 46 )
  {
    result = v4 - 46;
    if ( !(v20 & 0x10000) )
      return result;
  }
  v5 = (int)(a2 + 1);
LABEL_3:
  C = v4;
  v7 = (char *)(v5 - 1);
  v8 = v3 + 1;
  switch ( v4 )
  {
    case 0:
      return -*v7;
    case 63:
      if ( *(_BYTE *)(v5 - 1) )
      {
        ++v3;
        goto LABEL_27;
      }
      return 63;
    case 91:
      v17 = *(char *)(v5 - 1);
      if ( !*(_BYTE *)(v5 - 1) )
        return 91;
      if ( v3[1] != 33 )
      {
        v3 = (char *)sub_414FA0(v8, v17, v20);
        goto LABEL_26;
      }
      v18 = v3 + 2;
      if ( sub_414FA0(v3 + 2, v17, v20) )
      {
        v3 += 2;
        goto LABEL_26;
      }
      v19 = v3[2];
      if ( v19 == 93 )
      {
        v18 = v3 + 3;
        v19 = v3[3];
      }
      while ( 1 )
      {
        if ( v19 == 93 )
        {
          v3 = v18 + 1;
LABEL_26:
          if ( !v3 )
            return 93;
LABEL_27:
          v4 = *v3;
          ++v5;
          goto LABEL_3;
        }
        if ( v19 == 127 )
        {
          if ( v20 & 0x20 )
          {
            ++v18;
            goto LABEL_43;
          }
          v19 = (v18++)[1];
        }
        ++v18;
        if ( !v19 )
          return 93;
LABEL_43:
        v19 = *v18;
      }
    case 42:
      v15 = v3[1];
      v16 = v3 + 1;
      if ( v15 == 42 )
      {
        do
          v15 = *++v16;
        while ( *v16 == 42 );
      }
      result = 0;
      if ( v15 )
      {
        do
        {
          result = sub_415260(v20 | 0x10000, v7);
          if ( !result )
            break;
          ++v7;
        }
        while ( *(v7 - 1) );
      }
      break;
    default:
      if ( !(((unsigned __int8)(v20 >> 5) ^ 1) & 1) || v4 != 127 || (C = v3[1], v3 += 2, !C) )
        v3 = v8;
      v9 = *(char *)(v5 - 1);
      if ( (_BYTE)v9 )
      {
        if ( v20 & 0x4000 )
        {
          v13 = C - v9;
        }
        else
        {
          v10 = C;
          v11 = tolower(C);
          v12 = tolower(v9);
          C = v10;
          v13 = v11 - v12;
        }
        if ( !v13 )
          goto LABEL_27;
      }
      else
      {
        v9 = 0;
      }
      result = C - v9;
      break;
  }
  return result;
}


// Address: 0x00415480; symbol: sub_415480
signed int __usercall sub_415480@<eax>(int a1@<eax>, int a2@<edx>)
{
  int v2; // esi
  _DWORD *v3; // ebx
  _DWORD *v4; // eax
  int v5; // ecx
  int v6; // edx

  v2 = a1;
  v3 = (_DWORD *)a2;
  v4 = realloc(*(void **)(a2 + 8), 4 * (*(_DWORD *)(a2 + 4) + *(_DWORD *)(a2 + 12)) + 8);
  if ( !v4 )
    return 1;
  v5 = v3[1];
  v6 = v3[3];
  v3[2] = v4;
  v3[1] = v5 + 1;
  v4[v6 + v5] = v2;
  v4[v5 + 1 + v6] = 0;
  return 0;
}


// Address: 0x004154E0; symbol: sub_4154E0
void __usercall sub_4154E0(_DWORD *a1@<eax>, int a2@<edx>, int a3@<ecx>)
{
  _DWORD *Memory; // ebx
  int v4; // esi
  int v5; // eax

  Memory = a1;
  v4 = a2;
  if ( *a1 )
    ((void (*)(void))sub_4154E0)();
  v5 = Memory[2];
  if ( v5 && v4 )
    sub_415480(v5, v4);
  if ( Memory[1] )
    sub_4154E0(a3, v4);
  free(Memory);
}


// Address: 0x00415530; symbol: sub_415530
int __usercall sub_415530@<eax>(const char *a1@<eax>, unsigned int a2@<edx>, int a3@<ecx>, int a4)
{
  char *v4; // ebx
  size_t v5; // eax
  size_t v6; // edx
  unsigned int v7; // eax
  int v8; // ecx
  void *v9; // esp
  char *v10; // eax
  char *v11; // esi
  unsigned int v12; // edi
  unsigned int v13; // edx
  char v14; // al
  bool v15; // zf
  char *v16; // esi
  const char *v17; // edi
  signed int v18; // ecx
  char *v19; // eax
  char v20; // cl
  char *v21; // edx
  char v22; // al
  char *v23; // edx
  char j; // si
  char *v25; // eax
  void *v26; // edi
  int v27; // esi
  int v28; // ecx
  size_t v29; // edx
  unsigned int v30; // eax
  void *v31; // esp
  size_t v32; // eax
  int v33; // ecx
  void *v34; // esp
  char *v35; // eax
  char *v36; // esi
  char v37; // dl
  char v38; // dl
  char *v39; // esi
  _DWORD *v40; // ebx
  int v41; // edi
  int v42; // eax
  _DWORD *v43; // edx
  _DWORD *v44; // ecx
  void *v45; // eax
  _DWORD *v46; // eax
  signed int v47; // edx
  size_t v49; // eax
  int v50; // ecx
  void *v51; // esp
  char *v52; // esi
  char *v53; // edi
  char v54; // al
  char *v55; // edi
  char *v56; // edx
  signed int v57; // ecx
  char v58; // al
  char v59; // al
  bool v60; // bl
  int v61; // eax
  signed int v62; // esi
  char v63; // bl
  int v64; // ecx
  char *v65; // ecx
  char i; // al
  int v67; // esi
  int v68; // eax
  size_t v69; // eax
  int v70; // ecx
  char *v71; // edx
  void *v72; // esp
  char *v73; // ecx
  char v74; // al
  char *v75; // eax
  int v76; // ecx
  void *v77; // edi
  void **v78; // ebx
  _DWORD *v79; // edi
  void **v80; // eax
  void *v81; // eax
  char v82; // al
  int (*v83)(void); // edi
  void **v84; // esi
  size_t v85; // eax
  int v86; // ecx
  void *v87; // esp
  char *v88; // edx
  char v89; // al
  char *v90; // eax
  char v91; // bl
  char *Str; // [esp+0h] [ebp-78h]
  void *Src; // [esp+4h] [ebp-74h]
  size_t Size; // [esp+8h] [ebp-70h]
  char Dst[15]; // [esp+Ch] [ebp-6Ch]
  char v96; // [esp+1Bh] [ebp-5Dh]
  char *v97; // [esp+1Ch] [ebp-5Ch]
  char **v98; // [esp+20h] [ebp-58h]
  size_t v99; // [esp+24h] [ebp-54h]
  char **v100; // [esp+28h] [ebp-50h]
  size_t v101; // [esp+2Ch] [ebp-4Ch]
  _DWORD *v102; // [esp+30h] [ebp-48h]
  void *Memory; // [esp+34h] [ebp-44h]
  size_t v104; // [esp+38h] [ebp-40h]
  int (*v105)(void); // [esp+3Ch] [ebp-3Ch]
  char *v106; // [esp+40h] [ebp-38h]
  char *v107; // [esp+44h] [ebp-34h]
  unsigned int v108; // [esp+48h] [ebp-30h]
  char *v109; // [esp+4Ch] [ebp-2Ch]
  char v110; // [esp+50h] [ebp-28h]
  _DWORD *v111; // [esp+58h] [ebp-20h]
  int v112; // [esp+5Ch] [ebp-1Ch]

  v4 = (char *)a1;
  v108 = a2;
  v105 = (int (*)(void))a3;
  if ( a2 & 0x400 )
  {
    v104 = (size_t)&Str;
    v49 = 16 * ((strlen(a1) + 16) >> 4);
    sub_414DF0(v49, v50, (char)Str);
    v51 = alloca(v49);
    v52 = v4;
    v53 = Dst;
    v106 = Dst;
    v54 = *v4;
LABEL_56:
    if ( v54 != 127 )
    {
LABEL_57:
      if ( v54 == 123 )
      {
        v107 = v53;
        v55 = v52;
        goto LABEL_64;
      }
      goto LABEL_58;
    }
    while ( 1 )
    {
      v54 = v52[1];
      *v53 = 127;
      if ( v54 )
      {
        v53[1] = v54;
        v52 += 2;
        v54 = *v52;
        v53 += 2;
        goto LABEL_56;
      }
      ++v53;
      ++v52;
LABEL_58:
      *v53 = v54;
      if ( !v54 || v54 == 123 )
        break;
      v54 = v52[1];
      ++v53;
      ++v52;
      if ( v54 != 127 )
        goto LABEL_57;
    }
    if ( v54 == 123 )
    {
      v107 = v53 + 1;
      v55 = v52 + 1;
      while ( 1 )
      {
LABEL_64:
        v56 = v107;
        v57 = 1;
LABEL_65:
        v58 = v55[1];
        if ( v58 != 127 )
        {
LABEL_66:
          ++v55;
          goto LABEL_67;
        }
        while ( 1 )
        {
          v59 = v55[2];
          *v56 = 127;
          v56[1] = v59;
          if ( !v59 )
          {
            v56[2] = 0;
            return 1;
          }
          v58 = v55[3];
          v56 += 2;
          v55 += 3;
LABEL_67:
          if ( v58 != 125 && (v58 != 44 || v57 != 1) )
          {
            if ( v58 == 123 )
            {
              ++v57;
              v60 = 1;
              LOBYTE(v109) = 1;
            }
            else
            {
              LOBYTE(v109) = v58 != 0;
              v60 = v58 != 0;
            }
            *v56 = v58;
            if ( v60 )
            {
              ++v56;
              goto LABEL_65;
            }
            if ( (_BYTE)v109 )
            {
              ++v56;
              if ( v58 == 44 )
                goto LABEL_83;
LABEL_100:
              *v56 = 0;
              return 1;
            }
            return 1;
          }
          if ( !--v57 )
            break;
          *v56 = v58;
          v58 = v55[1];
          ++v56;
          if ( v58 != 127 )
            goto LABEL_66;
        }
        if ( v58 == 44 )
        {
LABEL_83:
          v61 = (int)v55;
          v62 = 1;
          do
          {
            while ( 1 )
            {
              while ( 1 )
              {
                v63 = *(_BYTE *)(v61 + 1);
                v64 = v61 + 1;
                if ( v63 == 127 )
                {
                  if ( !*(_BYTE *)(v61 + 2) )
                    goto LABEL_100;
                  while ( 1 )
                  {
                    v63 = *(_BYTE *)(v64 + 2);
                    v61 = v64 + 2;
                    if ( v63 != 127 )
                      break;
                    if ( !*(_BYTE *)(v64 + 3) )
                      goto LABEL_100;
                    v64 += 2;
                  }
                }
                else
                {
                  ++v61;
                }
                if ( v63 != 123 )
                  break;
                ++v62;
              }
              if ( v63 != 125 )
                break;
              if ( !--v62 )
                goto LABEL_93;
            }
          }
          while ( v63 );
          goto LABEL_100;
        }
        v61 = (int)v55;
LABEL_93:
        v65 = (char *)(v61 + 1);
        for ( i = *(_BYTE *)(v61 + 1); ; i = *v65 )
        {
          ++v56;
          ++v65;
          *(v56 - 1) = i;
          if ( !i )
            break;
        }
        v67 = v108 | 1;
        v68 = sub_415530(v105, v108, a4);
        v108 = v67;
        if ( v68 == 1 )
          return 1;
        if ( *v55 != 44 )
          return v68;
      }
    }
  }
  v98 = &Str;
  v5 = strlen(v4);
  v6 = v5 + 1;
  v7 = 16 * ((v5 + 16) >> 4);
  sub_414DF0(v7, v8, (char)Str);
  v9 = alloca(v7);
  v10 = (char *)memcpy(Dst, v4, v6);
  v109 = (char *)sub_415F10(v10);
  v11 = v109;
  v112 = 0;
  v107 = (char *)sub_414F30((int)&v110);
  if ( !v107 )
  {
    v12 = v108;
    if ( sub_414E90(v11, v108) )
    {
      v13 = v12;
      BYTE1(v13) |= 0x80u;
      v107 = (char *)sub_415530(v105, v13, &v110);
    }
    else
    {
      v69 = 16 * ((strlen(v109) + 16) >> 4);
      sub_414DF0(v69, v70, (char)Str);
      v71 = v109;
      v72 = alloca(v69);
      v73 = Dst;
      do
      {
        v74 = *v71;
        if ( *v71 == 127 )
          v74 = (v71++)[1];
        ++v73;
        ++v71;
        *(v73 - 1) = v74;
      }
      while ( v74 );
      v75 = strdup(Dst);
      if ( !v75 )
        return 1;
      v107 = (char *)sub_415480((int)v75, (int)&v110);
    }
    if ( !v107 )
    {
      v14 = v4[1];
      if ( v14 == 47 )
        goto LABEL_161;
      v15 = v14 == 92;
      if ( v14 == 92 )
        goto LABEL_161;
      v16 = v109;
      v17 = ".";
      v18 = 2;
      do
      {
        if ( !v18 )
          break;
        v15 = *v16++ == *v17++;
        --v18;
      }
      while ( v15 );
      if ( v15 )
      {
        if ( v108 & 0x10 )
        {
          v107 = (char *)sub_414E90(v4, v108);
          if ( !v107 )
          {
            v85 = 16 * ((strlen(v4) + 16) >> 4);
            sub_414DF0(v85, v86, (char)Str);
            v87 = alloca(v85);
            v88 = Dst;
            do
            {
              v89 = *v4;
              if ( *v4 == 127 )
                v89 = (v4++)[1];
              ++v88;
              ++v4;
              *(v88 - 1) = v89;
            }
            while ( v89 );
            v90 = strdup(Dst);
            if ( v90 && a4 )
            {
              sub_415480((int)v90, a4);
              Memory = v111;
            }
            else
            {
LABEL_136:
              Memory = v111;
            }
            goto LABEL_127;
          }
        }
        v106 = v4;
        v96 = 92;
        v97 = 0;
      }
      else
      {
LABEL_161:
        v19 = &v4[strlen(v109)];
        if ( v4 >= v19 )
        {
          v91 = *v19;
          v106 = v19;
          v96 = v91;
        }
        else
        {
          v96 = *v19;
          if ( v96 != 47 && v96 != 92 )
          {
            do
            {
              v21 = v19 - 1;
              if ( v4 == v19 - 1 )
              {
                v22 = *(v19 - 1);
                v106 = v21;
                v96 = v22;
                goto LABEL_20;
              }
              v20 = *(v19-- - 1);
            }
            while ( v20 != 47 && v20 != 92 );
            v106 = v21;
            v96 = v20;
          }
          else
          {
            v106 = v19;
          }
        }
LABEL_20:
        if ( v96 != 47 && v96 != 92 )
        {
          v96 = 92;
          v97 = v109;
        }
        else
        {
          v23 = v106;
          for ( j = v96; ; j = *v23 )
          {
            ++v23;
            if ( *v23 != 92 && *v23 != 47 )
              break;
          }
          v106 = v23;
          v96 = j;
          v97 = v109;
        }
      }
      v107 = (char *)2;
      Memory = v111;
      v25 = (char *)*v111;
      v109 = (char *)(v108 & 0x8000);
      if ( !v25 )
        goto LABEL_127;
LABEL_27:
      v26 = (void *)sub_416490(v25);
      if ( v26 )
      {
        if ( v97 )
        {
          Str = *(char **)Memory;
          v104 = strlen(Str);
        }
        else
        {
          v104 = 0;
        }
        v102 = 0;
        v99 = v104 + 2;
        while ( 1 )
        {
          while ( 1 )
          {
LABEL_31:
            v27 = sub_416650(v26);
            if ( !v27 )
            {
              sub_4166A0(v26);
              if ( v102 )
                sub_4154E0(v102, a4, v76);
LABEL_115:
              v77 = Memory;
              v78 = (void **)((char *)Memory + 4);
              free(*(void **)Memory);
              v25 = (char *)*((_DWORD *)v77 + 1);
              if ( !v25 )
                goto LABEL_136;
              if ( v107 == (char *)1 )
                goto LABEL_124;
              Memory = v78;
              goto LABEL_27;
            }
            if ( v109 && *(_DWORD *)(v27 + 8) != 16 || sub_415260(v106, (_BYTE *)(v27 + 12), v108) )
              continue;
            v29 = *(unsigned __int16 *)(v27 + 6);
            v100 = &Str;
            v30 = 16 * ((v29 + v99 + 15) >> 4);
            sub_414DF0(v30, v28, (char)Str);
            v31 = alloca(v30);
            v101 = 0;
            if ( v104 )
            {
              v101 = v29;
              memcpy(Dst, *(const void **)Memory, v104);
              v29 = v101;
              v82 = *((_BYTE *)&Size + v104 + 3);
              if ( v82 == 47 || v82 == 92 )
              {
                v101 = v104;
              }
              else
              {
                v101 = v104 + 1;
                Dst[v104] = v96;
              }
            }
            memcpy(&Dst[v101], (const void *)(v27 + 12), v29 + 1);
            v32 = 16 * ((strlen(Dst) + 16) >> 4);
            sub_414DF0(v32, v33, (char)Str);
            v34 = alloca(v32);
            v35 = Dst;
            v36 = Dst;
            do
            {
              while ( 1 )
              {
                v37 = *v35;
                if ( *v35 == 127 )
                  break;
                ++v36;
                ++v35;
                *(v36 - 1) = v37;
                if ( !v37 )
                  goto LABEL_40;
              }
              v38 = v35[1];
              ++v36;
              v35 += 2;
              *(v36 - 1) = v38;
            }
            while ( v38 );
LABEL_40:
            v39 = strdup(Dst);
            if ( !v39 )
            {
              v107 = (char *)3;
              continue;
            }
            v107 = (char *)(v107 == (char *)2 ? 0 : (unsigned int)v107);
            if ( v108 & 0x40 )
            {
              if ( a4 )
                sub_415480((int)v39, a4);
              continue;
            }
            v40 = v102;
            if ( v102 )
              break;
            v46 = malloc(0xCu);
            if ( v46 )
            {
              v46[2] = v39;
              v46[1] = 0;
              *v46 = 0;
              goto LABEL_135;
            }
          }
          v101 = (size_t)v26;
          v41 = v108 & 0x4000;
          while ( 1 )
          {
            v45 = (void *)v40[2];
            Str = v39;
            Src = v45;
            if ( !v41 )
              break;
            v42 = strcoll(Str, (const char *)Src);
            v43 = (_DWORD *)*v40;
            v44 = (_DWORD *)v40[1];
            if ( v42 <= 0 )
              goto LABEL_49;
LABEL_45:
            if ( !v44 )
              goto LABEL_50;
LABEL_46:
            v40 = v44;
          }
          v42 = stricoll(Str, (const char *)Src);
          v43 = (_DWORD *)*v40;
          v44 = (_DWORD *)v40[1];
          if ( v42 > 0 )
            goto LABEL_45;
LABEL_49:
          v44 = v43;
          if ( v43 )
            goto LABEL_46;
LABEL_50:
          v26 = (void *)v101;
          v101 = v42;
          v46 = malloc(0xCu);
          if ( !v46 )
            goto LABEL_31;
          v47 = v101;
          v46[2] = v39;
          v46[1] = 0;
          *v46 = 0;
          if ( v47 > 0 )
          {
            v40[1] = v46;
            goto LABEL_31;
          }
          *v40 = v46;
          if ( !v102 )
LABEL_135:
            v102 = v46;
        }
      }
      if ( v108 & 4 )
      {
        v79 = Memory;
        v78 = (void **)((char *)Memory + 4);
        v80 = (void **)Memory;
      }
      else
      {
        v83 = v105;
        if ( !v105 )
          goto LABEL_115;
        Src = (void *)*errno();
        v84 = (void **)Memory;
        Str = *(char **)Memory;
        if ( !v83() )
          goto LABEL_115;
        v80 = v84;
        v78 = v84 + 1;
        v79 = v84;
      }
      free(*v80);
      if ( v79[1] )
      {
LABEL_124:
        v81 = (void *)*((_DWORD *)Memory + 1);
        do
        {
          ++v78;
          free(v81);
          v81 = *v78;
        }
        while ( *v78 );
      }
      v107 = (char *)1;
      Memory = v111;
LABEL_127:
      free(Memory);
      return (int)v107;
    }
  }
  return (int)v107;
}


// Address: 0x00415DC0; symbol: sub_415DC0
char **__cdecl sub_415DC0(char *a1, int a2, int a3, int a4)
{
  char *v4; // ebx
  char **v5; // ecx
  size_t v7; // eax
  int v8; // ecx
  char **v9; // ecx
  void *v10; // esp
  char *v11; // edx
  char v12; // al
  char v13; // al
  char *v14; // eax
  char *Str; // [esp+0h] [ebp-38h]
  char Src; // [esp+4h] [ebp-34h]
  char **v17; // [esp+18h] [ebp-20h]
  char **v18; // [esp+1Ch] [ebp-1Ch]

  v4 = a1;
  if ( a4 && !(a2 & 2) )
    *(_DWORD *)(a4 + 12) = 0;
  if ( *(char **)a4 != "glob-1.0-mingw32" )
  {
    sub_414F30(a4);
    *(_DWORD *)a4 = "glob-1.0-mingw32";
  }
  v5 = (char **)sub_415530(a1, a2, a3, a4);
  if ( v5 == (char **)2 && a2 & 0x10 )
  {
    v17 = (char **)2;
    v18 = &Str;
    v7 = 16 * ((strlen(a1) + 16) >> 4);
    sub_414DF0(v7, v8, (char)Str);
    v9 = v17;
    v10 = alloca(v7);
    v11 = &Src;
    do
    {
      while ( 1 )
      {
        v12 = *v4;
        if ( *v4 == 127 )
          break;
        ++v11;
        ++v4;
        *(v11 - 1) = v12;
        if ( !v12 )
          goto LABEL_13;
      }
      v13 = v4[1];
      ++v11;
      v4 += 2;
      *(v11 - 1) = v13;
    }
    while ( v13 );
LABEL_13:
    v17 = v9;
    v14 = strdup(&Src);
    v5 = v17;
    if ( v14 )
    {
      v18 = v17;
      sub_415480((int)v14, a4);
      v5 = v18;
    }
  }
  return v5;
}


// Address: 0x00415F10; symbol: sub_415F10
char *__cdecl sub_415F10(char *Source)
{
  const char *v1; // eax
  char *v2; // ebx
  size_t MaxCount; // esi
  size_t v5; // eax
  size_t v6; // edx
  unsigned int v7; // eax
  int v8; // ecx
  void *v9; // esp
  bool v10; // cf
  bool v11; // zf
  _WORD *v12; // ecx
  __int16 v13; // dx
  _WORD *v14; // esi
  __int16 v15; // dx
  _WORD *i; // eax
  size_t v17; // eax
  _WORD *v18; // eax
  char *v19; // esi
  int v20; // eax
  __int16 v21; // dx
  wchar_t *v22; // ecx
  wchar_t v23; // dx
  wchar_t *v24; // eax
  size_t v25; // eax
  size_t v26; // eax
  __int16 v27; // dx
  char *Src; // [esp+0h] [ebp-38h]
  wchar_t Dest; // [esp+Ch] [ebp-2Ch]
  __int16 v30; // [esp+Eh] [ebp-2Ah]
  size_t v31; // [esp+10h] [ebp-28h]
  char **v32; // [esp+14h] [ebp-24h]
  __int16 v33; // [esp+1Ah] [ebp-1Eh]
  size_t v34; // [esp+1Ch] [ebp-1Ch]

  v1 = (const char *)setlocale(2, 0);
  v2 = (char *)v1;
  if ( v1 )
    v2 = strdup(v1);
  setlocale(2, &unk_419D0C);
  if ( !Source || !*Source )
    goto LABEL_66;
  v32 = &Src;
  v5 = mbstowcs(0, Source, 0);
  v6 = v5;
  v7 = 16 * ((2 * v5 + 18) >> 4);
  sub_414DF0(v7, v8, (char)Src);
  v9 = alloca(v7);
  v31 = mbstowcs(&Dest, Source, v6);
  v10 = v31 < 1;
  v11 = v31 == 1;
  *(&Dest + v31) = 0;
  v34 = (size_t)&Dest;
  v33 = Dest;
  if ( !v10 && !v11 )
  {
    if ( Dest == 47 || Dest == 92 )
    {
      if ( v33 == v30 && !(_WORD)v31 )
      {
        setlocale(2, v2);
        free(v2);
        return Source;
      }
    }
    else if ( v30 == 58 )
    {
      v34 = (size_t)&v31;
      v33 = v31;
    }
  }
  if ( !v33 )
  {
LABEL_66:
    MaxCount = wcstombs(0, ".", 0) + 1;
    Memory = realloc(Memory, MaxCount);
    wcstombs((char *)Memory, ".", MaxCount);
    setlocale(2, v2);
    free(v2);
    return (char *)Memory;
  }
  v12 = (_WORD *)v34;
  v13 = v33;
  v14 = (_WORD *)v34;
  do
  {
    while ( v13 != 47 && v13 != 92 )
    {
      v13 = v12[1];
      ++v12;
      if ( !v13 )
        goto LABEL_21;
    }
    v15 = *v12;
    for ( i = v12; *i == 47; v15 = *i )
LABEL_17:
      ++i;
    if ( v15 == 92 )
      goto LABEL_17;
    if ( !v15 )
      break;
    v13 = i[1];
    v14 = i;
    v12 = i + 1;
  }
  while ( v13 );
LABEL_21:
  if ( v34 < (unsigned int)v14 )
  {
    while ( 1 )
    {
      v20 = (int)(v14 - 1);
      if ( v34 >= (unsigned int)(v14 - 1) )
        break;
      v21 = *(v14 - 1);
      --v14;
      if ( v21 != 47 && v21 != 92 )
        goto LABEL_30;
    }
    if ( (_WORD *)v34 == v14 - 1 && (v33 == 47 || v33 == 92) && *v14 == v33 )
    {
      v27 = *(_WORD *)(v20 + 4);
      if ( v27 != 47 && v27 != 92 )
        v20 = (int)v14;
    }
LABEL_30:
    v22 = &Dest;
    *(_WORD *)(v20 + 2) = 0;
    v23 = Dest;
    if ( Dest == 47 || Dest == 92 )
    {
      do
      {
        do
          ++v22;
        while ( *v22 == 47 );
      }
      while ( *v22 == 92 );
      if ( (char *)v22 - (char *)&Dest > 5 )
        goto LABEL_67;
    }
    if ( v30 != Dest )
LABEL_67:
      v22 = &Dest;
    else
      v23 = *v22;
    v24 = v22;
    while ( v23 )
    {
      while ( 1 )
      {
        ++v22;
        *(v22 - 1) = v23;
        if ( v23 == 47 )
          break;
        if ( *v24 == 92 )
        {
          ++v24;
          break;
        }
        v23 = v24[1];
        ++v24;
        if ( !v23 )
          goto LABEL_41;
      }
      v23 = *v24;
      if ( *v24 == 92 || v23 == 47 )
      {
        do
        {
          do
          {
            ++v24;
            v23 = *v24;
          }
          while ( *v24 == 47 );
        }
        while ( v23 == 92 );
      }
    }
LABEL_41:
    v25 = v31;
    *v22 = 0;
    v26 = wcstombs(Source, &Dest, v25);
    v19 = Source;
    if ( v26 != -1 )
      Source[v26] = 0;
  }
  else
  {
    if ( v33 == 47 || v33 == 92 )
    {
      v18 = (_WORD *)(v34 + 2);
    }
    else
    {
      v17 = v34;
      *(_WORD *)v34 = 46;
      v18 = (_WORD *)(v17 + 2);
    }
    *v18 = 0;
    v34 = wcstombs(0, &Dest, 0) + 1;
    Memory = realloc(Memory, v34);
    v19 = (char *)Memory;
    wcstombs((char *)Memory, &Dest, v34);
  }
  setlocale(2, v2);
  free(v2);
  return v19;
}


// Address: 0x00416310; symbol: sub_416310
HANDLE __usercall sub_416310@<eax>(const CHAR *lpFileName@<eax>, int a2@<edx>)
{
  int v2; // ebx
  HANDLE v3; // esi
  CHAR *v4; // ecx
  unsigned __int16 i; // ax
  CHAR v6; // al
  DWORD v7; // eax
  int *v9; // ebx
  DWORD v10; // eax
  struct _WIN32_FIND_DATAA FindFileData; // [esp+10h] [ebp-14Ch]

  v2 = a2;
  v3 = FindFirstFileA(lpFileName, &FindFileData);
  if ( v3 == (HANDLE)-1 )
  {
    v9 = errno();
    v10 = GetLastError();
    *v9 = v10;
    if ( v10 == 3 )
    {
      *errno() = 2;
    }
    else if ( *errno() == 267 )
    {
      *errno() = 20;
    }
    else if ( *errno() != 2 )
    {
      *errno() = 22;
    }
    return v3;
  }
  v4 = (CHAR *)(v2 + 12);
  *(_WORD *)(v2 + 6) = 0;
  for ( i = 0; ; v4 += i < 0x104u )
  {
    v6 = FindFileData.cFileName[i];
    *v4 = v6;
    if ( !v6 )
      break;
    i = *(_WORD *)(v2 + 6) + 1;
    *(_WORD *)(v2 + 6) = i;
  }
  v7 = FindFileData.dwFileAttributes;
  LOBYTE(v7) = FindFileData.dwFileAttributes & 0x58;
  if ( v7 > 0x10 )
  {
    *(_DWORD *)(v2 + 8) = 24;
    return v3;
  }
  *(_DWORD *)(v2 + 8) = v7;
  return v3;
}


// Address: 0x004163E0; symbol: sub_4163E0
BOOL __usercall sub_4163E0@<eax>(void *hFindFile@<eax>, int a2@<edx>)
{
  int v2; // ebx
  BOOL v3; // esi
  CHAR *v4; // ecx
  unsigned __int16 i; // ax
  CHAR v6; // al
  DWORD v7; // eax
  BOOL result; // eax
  struct _WIN32_FIND_DATAA FindFileData; // [esp+10h] [ebp-14Ch]

  v2 = a2;
  v3 = FindNextFileA(hFindFile, &FindFileData);
  if ( v3 )
  {
    v4 = (CHAR *)(v2 + 12);
    *(_WORD *)(v2 + 6) = 0;
    for ( i = 0; ; v4 += i < 0x104u )
    {
      v6 = FindFileData.cFileName[i];
      *v4 = v6;
      if ( !v6 )
        break;
      i = *(_WORD *)(v2 + 6) + 1;
      *(_WORD *)(v2 + 6) = i;
    }
    v7 = FindFileData.dwFileAttributes;
    LOBYTE(v7) = FindFileData.dwFileAttributes & 0x58;
    if ( v7 <= 0x10 )
    {
      *(_DWORD *)(v2 + 8) = v7;
      return v3;
    }
    *(_DWORD *)(v2 + 8) = 24;
    result = v3;
  }
  else
  {
    if ( GetLastError() == 18 )
      return v3;
    *errno() = 2;
    result = 0;
  }
  return result;
}


// Address: 0x00416490; symbol: sub_416490
int __cdecl sub_416490(char *Path)
{
  char *v1; // eax
  int v2; // ecx
  unsigned int v3; // edx
  int v4; // eax
  char v5; // dl
  int v6; // ecx
  unsigned int v7; // edx
  char *v8; // kr00_4
  char *v9; // eax
  int v10; // esi
  const CHAR *v11; // ebp
  HANDLE v12; // eax
  char *FullPath; // ST00_4
  char v15; // [esp+1Bh] [ebp-121h]
  char Src[288]; // [esp+1Ch] [ebp-120h]

  if ( Path )
  {
    if ( *Path )
    {
      fullpath(Src, Path, 0x104u);
      v1 = Src;
      if ( Src[0] )
      {
        do
        {
          v2 = *(_DWORD *)v1;
          v1 += 4;
          v3 = ~v2 & (v2 - 16843009) & 0x80808080;
        }
        while ( !v3 );
        if ( !(~v2 & (v2 - 16843009) & 0x8080) )
        {
          v3 >>= 16;
          v1 += 2;
        }
        v4 = &v1[-__CFADD__((_BYTE)v3, (_BYTE)v3) - 3] - Src;
        v5 = *(&v15 + v4);
        if ( v5 != 47 && v5 != 92 )
          *(_WORD *)&Src[v4++] = 92;
      }
      else
      {
        do
        {
          v6 = *(_DWORD *)v1;
          v1 += 4;
          v7 = ~v6 & (v6 - 16843009) & 0x80808080;
        }
        while ( !v7 );
        if ( !(~v6 & (v6 - 16843009) & 0x8080) )
        {
          v7 >>= 16;
          v1 += 2;
        }
        v4 = &v1[-__CFADD__((_BYTE)v7, (_BYTE)v7) - 3] - Src;
      }
      *(_WORD *)&Src[v4] = 42;
      v8 = &Src[strlen(Src)];
      v9 = (char *)malloc(v8 - Src + 284);
      v10 = (int)v9;
      if ( v9 )
      {
        v11 = v9 + 280;
        memcpy(v9 + 280, Src, v8 - Src + 1);
        v12 = sub_416310(v11, v10);
        *(_DWORD *)(v10 + 272) = v12;
        if ( v12 == (HANDLE)-1 )
        {
          FullPath = (char *)v10;
          v10 = 0;
          free(FullPath);
        }
        else
        {
          *(_DWORD *)(v10 + 276) = 0;
          *(_DWORD *)v10 = 0;
          *(_WORD *)(v10 + 4) = 272;
        }
      }
      else
      {
        *errno() = 12;
      }
    }
    else
    {
      v10 = 0;
      *errno() = 2;
    }
  }
  else
  {
    v10 = 0;
    *errno() = 22;
  }
  return v10;
}


// Address: 0x00416650; symbol: sub_416650
BOOL __cdecl sub_416650(int a1)
{
  int v1; // eax
  BOOL result; // eax

  if ( a1 )
  {
    v1 = *(_DWORD *)(a1 + 276);
    *(_DWORD *)(a1 + 276) = v1 + 1;
    if ( v1 <= 0 || (result = sub_4163E0(*(void **)(a1 + 272), a1)) != 0 )
      result = a1;
  }
  else
  {
    *errno() = 9;
    result = 0;
  }
  return result;
}


// Address: 0x004166A0; symbol: sub_4166A0
int __cdecl sub_4166A0(void *Memory)
{
  int result; // eax

  if ( Memory && FindClose(*((HANDLE *)Memory + 68)) )
  {
    free(Memory);
    result = 0;
  }
  else
  {
    *errno() = 9;
    result = -1;
  }
  return result;
}


// Address: 0x004166F0; symbol: sub_4166F0
_DWORD *__cdecl sub_4166F0(int a1)
{
  _DWORD *result; // eax

  if ( a1 && FindClose(*(HANDLE *)(a1 + 272)) )
  {
    result = sub_416310((const CHAR *)(a1 + 280), a1);
    *(_DWORD *)(a1 + 272) = result;
    if ( result != (_DWORD *)-1 )
      *(_DWORD *)(a1 + 276) = 0;
  }
  else
  {
    result = errno();
    *result = 9;
  }
  return result;
}


// Address: 0x00416800; symbol: wcstombs
size_t __cdecl wcstombs(char *Dest, const wchar_t *Source, size_t MaxCount)
{
  return wcstombs(Dest, Source, MaxCount);
}


// Address: 0x00416808; symbol: wcslen
size_t __cdecl wcslen(const wchar_t *Str)
{
  return wcslen(Str);
}


// Address: 0x00416810; symbol: vfprintf
int __cdecl vfprintf(FILE *File, const char *Format, va_list ArgList)
{
  return vfprintf(File, Format, ArgList);
}


// Address: 0x00416818; symbol: tolower
int __cdecl tolower(int C)
{
  return tolower(C);
}


// Address: 0x00416820; symbol: time
time_t __cdecl time(time_t *Time)
{
  return time(Time);
}


// Address: 0x00416828; symbol: strtoul
unsigned int __cdecl strtoul(const char *Str, char **EndPtr, int Radix)
{
  return strtoul(Str, EndPtr, Radix);
}


// Address: 0x00416830; symbol: strlen
size_t __cdecl strlen(const char *Str)
{
  return strlen(Str);
}


// Address: 0x00416838; symbol: strcoll
int __cdecl strcoll(const char *Str1, const char *Str2)
{
  return strcoll(Str1, Str2);
}


// Address: 0x00416840; symbol: strcmp
int __cdecl strcmp(const char *Str1, const char *Str2)
{
  return strcmp(Str1, Str2);
}


// Address: 0x00416848; symbol: srand
void __cdecl srand(unsigned int Seed)
{
  srand(Seed);
}


// Address: 0x00416850; symbol: signal
int __cdecl signal(int a1, int a2)
{
  return signal(a1, a2);
}


// Address: 0x00416858; symbol: setlocale
int __cdecl setlocale(int a1, int a2)
{
  return setlocale(a1, a2);
}


// Address: 0x00416860; symbol: realloc
void *__cdecl realloc(void *Memory, size_t NewSize)
{
  return realloc(Memory, NewSize);
}


// Address: 0x00416868; symbol: rand
int __cdecl rand()
{
  return rand();
}


// Address: 0x00416870; symbol: memcpy
void *__cdecl memcpy(void *Dst, const void *Src, size_t Size)
{
  return memcpy(Dst, Src, Size);
}


// Address: 0x00416878; symbol: mbstowcs
size_t __cdecl mbstowcs(wchar_t *Dest, const char *Source, size_t MaxCount)
{
  return mbstowcs(Dest, Source, MaxCount);
}


// Address: 0x00416880; symbol: malloc
void *__cdecl malloc(size_t Size)
{
  return malloc(Size);
}


// Address: 0x00416888; symbol: localtime
struct tm *__cdecl localtime(const time_t *Time)
{
  return localtime(Time);
}


// Address: 0x00416890; symbol: fwrite
size_t __cdecl fwrite(const void *Str, size_t Size, size_t Count, FILE *File)
{
  return fwrite(Str, Size, Count, File);
}


// Address: 0x00416898; symbol: free
void __cdecl free(void *Memory)
{
  free(Memory);
}


// Address: 0x004168A0; symbol: clock
clock_t __cdecl clock()
{
  return clock();
}


// Address: 0x004168A8; symbol: calloc
void *__cdecl calloc(size_t NumOfElements, size_t SizeOfElements)
{
  return calloc(NumOfElements, SizeOfElements);
}


// Address: 0x004168B0; symbol: abort
void __cdecl __noreturn abort()
{
  abort();
}


// Address: 0x004168B8; symbol: _setmode
int __cdecl setmode(int a1, int a2)
{
  return _setmode(a1, a2);
}


// Address: 0x004168C0; symbol: _isctype
int __cdecl isctype(int C, int Type)
{
  return _isctype(C, Type);
}


// Address: 0x004168C8; symbol: _fullpath
char *__cdecl fullpath(char *FullPath, const char *Path, size_t SizeInBytes)
{
  return _fullpath(FullPath, Path, SizeInBytes);
}


// Address: 0x004168D0; symbol: _errno
int *__cdecl errno()
{
  return _errno();
}


// Address: 0x004168D8; symbol: _cexit
int cexit(void)
{
  return _cexit();
}


// Address: 0x004168E0; symbol: __p__fmode
int _p__fmode(void)
{
  return __p__fmode();
}


// Address: 0x004168E8; symbol: __p__environ
int _p__environ(void)
{
  return __p__environ();
}


// Address: 0x004168F0; symbol: __getmainargs
int __cdecl _getmainargs(int a1, int a2, int a3, int a4, int a5)
{
  return __getmainargs(a1, a2, a3, a4, a5);
}


// Address: 0x004168F8; symbol: RegSetValueExA
LSTATUS __stdcall RegSetValueExA(HKEY hKey, LPCSTR lpValueName, DWORD Reserved, DWORD dwType, const BYTE *lpData, DWORD cbData)
{
  return RegSetValueExA(hKey, lpValueName, Reserved, dwType, lpData, cbData);
}


// Address: 0x00416900; symbol: RegQueryValueExA
LSTATUS __stdcall RegQueryValueExA(HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData)
{
  return RegQueryValueExA(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData);
}


// Address: 0x00416908; symbol: RegCreateKeyExA
LSTATUS __stdcall RegCreateKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD Reserved, LPSTR lpClass, DWORD dwOptions, REGSAM samDesired, const LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition)
{
  return RegCreateKeyExA(
           hKey,
           lpSubKey,
           Reserved,
           lpClass,
           dwOptions,
           samDesired,
           lpSecurityAttributes,
           phkResult,
           lpdwDisposition);
}


// Address: 0x00416910; symbol: RegCloseKey
LSTATUS __stdcall RegCloseKey(HKEY hKey)
{
  return RegCloseKey(hKey);
}


// Address: 0x00416920; symbol: UpdateWindow
BOOL __stdcall UpdateWindow(HWND hWnd)
{
  return UpdateWindow(hWnd);
}


// Address: 0x00416928; symbol: TranslateMessage
BOOL __stdcall TranslateMessage(const MSG *lpMsg)
{
  return TranslateMessage(lpMsg);
}


// Address: 0x00416930; symbol: SystemParametersInfoA
BOOL __stdcall SystemParametersInfoA(UINT uiAction, UINT uiParam, PVOID pvParam, UINT fWinIni)
{
  return SystemParametersInfoA(uiAction, uiParam, pvParam, fWinIni);
}


// Address: 0x00416938; symbol: ShowWindow
BOOL __stdcall ShowWindow(HWND hWnd, int nCmdShow)
{
  return ShowWindow(hWnd, nCmdShow);
}


// Address: 0x00416940; symbol: SetWindowTextW
BOOL __stdcall SetWindowTextW(HWND hWnd, LPCWSTR lpString)
{
  return SetWindowTextW(hWnd, lpString);
}


// Address: 0x00416950; symbol: SetWindowLongA
LONG __stdcall SetWindowLongA(HWND hWnd, int nIndex, LONG dwNewLong)
{
  return SetWindowLongA(hWnd, nIndex, dwNewLong);
}


// Address: 0x00416958; symbol: SetForegroundWindow
BOOL __stdcall SetForegroundWindow(HWND hWnd)
{
  return SetForegroundWindow(hWnd);
}


// Address: 0x00416960; symbol: SetCursor
HCURSOR __stdcall SetCursor(HCURSOR hCursor)
{
  return SetCursor(hCursor);
}


// Address: 0x00416968; symbol: SendMessageA
LRESULT __stdcall SendMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  return SendMessageA(hWnd, Msg, wParam, lParam);
}


// Address: 0x00416970; symbol: ReleaseDC
int __stdcall ReleaseDC(HWND hWnd, HDC hDC)
{
  return ReleaseDC(hWnd, hDC);
}


// Address: 0x00416978; symbol: RegisterClassW
ATOM __stdcall RegisterClassW(const WNDCLASSW *lpWndClass)
{
  return RegisterClassW(lpWndClass);
}


// Address: 0x00416980; symbol: MoveWindow
BOOL __stdcall MoveWindow(HWND hWnd, int X, int Y, int nWidth, int nHeight, BOOL bRepaint)
{
  return MoveWindow(hWnd, X, Y, nWidth, nHeight, bRepaint);
}


// Address: 0x00416988; symbol: MessageBoxW
int __stdcall MessageBoxW(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType)
{
  return MessageBoxW(hWnd, lpText, lpCaption, uType);
}


// Address: 0x00416990; symbol: MessageBoxA
int __stdcall MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
{
  return MessageBoxA(hWnd, lpText, lpCaption, uType);
}


// Address: 0x00416998; symbol: LoadImageA
HANDLE __stdcall LoadImageA(HINSTANCE hInst, LPCSTR name, UINT type, int cx, int cy, UINT fuLoad)
{
  return LoadImageA(hInst, name, type, cx, cy, fuLoad);
}


// Address: 0x004169A0; symbol: LoadCursorA
HCURSOR __stdcall LoadCursorA(HINSTANCE hInstance, LPCSTR lpCursorName)
{
  return LoadCursorA(hInstance, lpCursorName);
}


// Address: 0x004169A8; symbol: IsZoomed
BOOL __stdcall IsZoomed(HWND hWnd)
{
  return IsZoomed(hWnd);
}


// Address: 0x004169B0; symbol: IsIconic
BOOL __stdcall IsIconic(HWND hWnd)
{
  return IsIconic(hWnd);
}


// Address: 0x004169B8; symbol: InvalidateRect
BOOL __stdcall InvalidateRect(HWND hWnd, const RECT *lpRect, BOOL bErase)
{
  return InvalidateRect(hWnd, lpRect, bErase);
}


// Address: 0x004169D0; symbol: GetWindowRect
BOOL __stdcall GetWindowRect(HWND hWnd, LPRECT lpRect)
{
  return GetWindowRect(hWnd, lpRect);
}


// Address: 0x004169D8; symbol: GetSystemMetrics
int __stdcall GetSystemMetrics(int nIndex)
{
  return GetSystemMetrics(nIndex);
}


// Address: 0x004169E0; symbol: GetMonitorInfoA
BOOL __stdcall GetMonitorInfoA(HMONITOR hMonitor, LPMONITORINFO lpmi)
{
  return GetMonitorInfoA(hMonitor, lpmi);
}


// Address: 0x004169E8; symbol: GetMessageA
BOOL __stdcall GetMessageA(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax)
{
  return GetMessageA(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);
}


// Address: 0x004169F8; symbol: GetDC
HDC __stdcall GetDC(HWND hWnd)
{
  return GetDC(hWnd);
}


// Address: 0x00416A00; symbol: GetCursorPos
BOOL __stdcall GetCursorPos(LPPOINT lpPoint)
{
  return GetCursorPos(lpPoint);
}


// Address: 0x00416A08; symbol: GetAsyncKeyState
SHORT __stdcall GetAsyncKeyState(int vKey)
{
  return GetAsyncKeyState(vKey);
}


// Address: 0x00416A10; symbol: FrameRect
int __stdcall FrameRect(HDC hDC, const RECT *lprc, HBRUSH hbr)
{
  return FrameRect(hDC, lprc, hbr);
}


// Address: 0x00416A18; symbol: FindWindowA
HWND __stdcall FindWindowA(LPCSTR lpClassName, LPCSTR lpWindowName)
{
  return FindWindowA(lpClassName, lpWindowName);
}


// Address: 0x00416A20; symbol: FillRect
int __stdcall FillRect(HDC hDC, const RECT *lprc, HBRUSH hbr)
{
  return FillRect(hDC, lprc, hbr);
}


// Address: 0x00416A28; symbol: EnumDisplayMonitors
BOOL __stdcall EnumDisplayMonitors(HDC hdc, LPCRECT lprcClip, MONITORENUMPROC lpfnEnum, LPARAM dwData)
{
  return EnumDisplayMonitors(hdc, lprcClip, lpfnEnum, dwData);
}


// Address: 0x00416A30; symbol: DrawTextW
int __stdcall DrawTextW(HDC hdc, LPCWSTR lpchText, int cchText, LPRECT lprc, UINT format)
{
  return DrawTextW(hdc, lpchText, cchText, lprc, format);
}


// Address: 0x00416A38; symbol: DrawTextA
int __stdcall DrawTextA(HDC hdc, LPCSTR lpchText, int cchText, LPRECT lprc, UINT format)
{
  return DrawTextA(hdc, lpchText, cchText, lprc, format);
}


// Address: 0x00416A40; symbol: DispatchMessageA
LRESULT __stdcall DispatchMessageA(const MSG *lpMsg)
{
  return DispatchMessageA(lpMsg);
}


// Address: 0x00416A48; symbol: DestroyWindow
BOOL __stdcall DestroyWindow(HWND hWnd)
{
  return DestroyWindow(hWnd);
}


// Address: 0x00416A50; symbol: DefWindowProcW
LRESULT __stdcall DefWindowProcW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
  return DefWindowProcW(hWnd, Msg, wParam, lParam);
}


// Address: 0x00416A58; symbol: CreateWindowExW
HWND __stdcall CreateWindowExW(DWORD dwExStyle, LPCWSTR lpClassName, LPCWSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam)
{
  return CreateWindowExW(
           dwExStyle,
           lpClassName,
           lpWindowName,
           dwStyle,
           X,
           Y,
           nWidth,
           nHeight,
           hWndParent,
           hMenu,
           hInstance,
           lpParam);
}


// Address: 0x00416A60; symbol: AdjustWindowRect
BOOL __stdcall AdjustWindowRect(LPRECT lpRect, DWORD dwStyle, BOOL bMenu)
{
  return AdjustWindowRect(lpRect, dwStyle, bMenu);
}


// Address: 0x00416A68; symbol: lstrcpyA
LPSTR __stdcall lstrcpyA(LPSTR lpString1, LPCSTR lpString2)
{
  return lstrcpyA(lpString1, lpString2);
}


// Address: 0x00416A70; symbol: lstrcmpA
int __stdcall lstrcmpA(LPCSTR lpString1, LPCSTR lpString2)
{
  return lstrcmpA(lpString1, lpString2);
}


// Address: 0x00416A78; symbol: lstrcatA
LPSTR __stdcall lstrcatA(LPSTR lpString1, LPCSTR lpString2)
{
  return lstrcatA(lpString1, lpString2);
}


// Address: 0x00416A80; symbol: VirtualQuery
SIZE_T __stdcall VirtualQuery(LPCVOID lpAddress, PMEMORY_BASIC_INFORMATION lpBuffer, SIZE_T dwLength)
{
  return VirtualQuery(lpAddress, lpBuffer, dwLength);
}


// Address: 0x00416A88; symbol: VirtualProtect
BOOL __stdcall VirtualProtect(LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD lpflOldProtect)
{
  return VirtualProtect(lpAddress, dwSize, flNewProtect, lpflOldProtect);
}


// Address: 0x00416A90; symbol: TlsGetValue
LPVOID __stdcall TlsGetValue(DWORD dwTlsIndex)
{
  return TlsGetValue(dwTlsIndex);
}


// Address: 0x00416A98; symbol: Sleep
void __stdcall Sleep(DWORD dwMilliseconds)
{
  Sleep(dwMilliseconds);
}


// Address: 0x00416AA0; symbol: SetUnhandledExceptionFilter
LPTOP_LEVEL_EXCEPTION_FILTER __stdcall SetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter)
{
  return SetUnhandledExceptionFilter(lpTopLevelExceptionFilter);
}


// Address: 0x00416AA8; symbol: RemoveDirectoryA
BOOL __stdcall RemoveDirectoryA(LPCSTR lpPathName)
{
  return RemoveDirectoryA(lpPathName);
}


// Address: 0x00416AB0; symbol: ReleaseMutex
BOOL __stdcall ReleaseMutex(HANDLE hMutex)
{
  return ReleaseMutex(hMutex);
}


// Address: 0x00416AB8; symbol: ReadFile
BOOL __stdcall ReadFile(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped)
{
  return ReadFile(hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped);
}


// Address: 0x00416AC0; symbol: QueryPerformanceFrequency
BOOL __stdcall QueryPerformanceFrequency(LARGE_INTEGER *lpFrequency)
{
  return QueryPerformanceFrequency(lpFrequency);
}


// Address: 0x00416AC8; symbol: QueryPerformanceCounter
BOOL __stdcall QueryPerformanceCounter(LARGE_INTEGER *lpPerformanceCount)
{
  return QueryPerformanceCounter(lpPerformanceCount);
}


// Address: 0x00416AD0; symbol: MultiByteToWideChar
int __stdcall MultiByteToWideChar(UINT CodePage, DWORD dwFlags, LPCSTR lpMultiByteStr, int cbMultiByte, LPWSTR lpWideCharStr, int cchWideChar)
{
  return MultiByteToWideChar(CodePage, dwFlags, lpMultiByteStr, cbMultiByte, lpWideCharStr, cchWideChar);
}


// Address: 0x00416AD8; symbol: LoadLibraryA
HMODULE __stdcall LoadLibraryA(LPCSTR lpLibFileName)
{
  return LoadLibraryA(lpLibFileName);
}


// Address: 0x00416AE0; symbol: LeaveCriticalSection
void __stdcall LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
  LeaveCriticalSection(lpCriticalSection);
}


// Address: 0x00416AE8; symbol: InitializeCriticalSection
void __stdcall InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
  InitializeCriticalSection(lpCriticalSection);
}


// Address: 0x00416AF0; symbol: GetUserDefaultUILanguage
LANGID __stdcall GetUserDefaultUILanguage()
{
  return GetUserDefaultUILanguage();
}


// Address: 0x00416AF8; symbol: GetTickCount
DWORD __stdcall GetTickCount()
{
  return GetTickCount();
}


// Address: 0x00416B00; symbol: GetTempPathA
DWORD __stdcall GetTempPathA(DWORD nBufferLength, LPSTR lpBuffer)
{
  return GetTempPathA(nBufferLength, lpBuffer);
}


// Address: 0x00416B08; symbol: GetStartupInfoA
void __stdcall GetStartupInfoA(LPSTARTUPINFOA lpStartupInfo)
{
  GetStartupInfoA(lpStartupInfo);
}


// Address: 0x00416B10; symbol: GetProcAddress
FARPROC __stdcall GetProcAddress(HMODULE hModule, LPCSTR lpProcName)
{
  return GetProcAddress(hModule, lpProcName);
}


// Address: 0x00416B18; symbol: GetModuleHandleA
HMODULE __stdcall GetModuleHandleA(LPCSTR lpModuleName)
{
  return GetModuleHandleA(lpModuleName);
}


// Address: 0x00416B20; symbol: GetLastError
DWORD __stdcall GetLastError()
{
  return GetLastError();
}


// Address: 0x00416B28; symbol: GetFileAttributesA
DWORD __stdcall GetFileAttributesA(LPCSTR lpFileName)
{
  return GetFileAttributesA(lpFileName);
}


// Address: 0x00416B30; symbol: GetCommandLineA
LPSTR __stdcall GetCommandLineA()
{
  return GetCommandLineA();
}


// Address: 0x00416B38; symbol: FreeLibrary
BOOL __stdcall FreeLibrary(HMODULE hLibModule)
{
  return FreeLibrary(hLibModule);
}


// Address: 0x00416B40; symbol: FindNextFileA
BOOL __stdcall FindNextFileA(HANDLE hFindFile, LPWIN32_FIND_DATAA lpFindFileData)
{
  return FindNextFileA(hFindFile, lpFindFileData);
}


// Address: 0x00416B48; symbol: FindFirstFileA
HANDLE __stdcall FindFirstFileA(LPCSTR lpFileName, LPWIN32_FIND_DATAA lpFindFileData)
{
  return FindFirstFileA(lpFileName, lpFindFileData);
}


// Address: 0x00416B50; symbol: FindClose
BOOL __stdcall FindClose(HANDLE hFindFile)
{
  return FindClose(hFindFile);
}


// Address: 0x00416B58; symbol: ExitThread
void __stdcall __noreturn ExitThread(DWORD dwExitCode)
{
  ExitThread(dwExitCode);
}


// Address: 0x00416B60; symbol: ExitProcess
void __stdcall __noreturn ExitProcess(UINT uExitCode)
{
  ExitProcess(uExitCode);
}


// Address: 0x00416B68; symbol: EnterCriticalSection
void __stdcall EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
  EnterCriticalSection(lpCriticalSection);
}


// Address: 0x00416B70; symbol: DeleteFileA
BOOL __stdcall DeleteFileA(LPCSTR lpFileName)
{
  return DeleteFileA(lpFileName);
}


// Address: 0x00416B78; symbol: DeleteCriticalSection
void __stdcall DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
  DeleteCriticalSection(lpCriticalSection);
}


// Address: 0x00416B80; symbol: CreateThread
HANDLE __stdcall CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes, SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlags, LPDWORD lpThreadId)
{
  return CreateThread(lpThreadAttributes, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId);
}


// Address: 0x00416B88; symbol: CreateMutexA
HANDLE __stdcall CreateMutexA(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCSTR lpName)
{
  return CreateMutexA(lpMutexAttributes, bInitialOwner, lpName);
}


// Address: 0x00416B90; symbol: CreateFileA
HANDLE __stdcall CreateFileA(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile)
{
  return CreateFileA(
           lpFileName,
           dwDesiredAccess,
           dwShareMode,
           lpSecurityAttributes,
           dwCreationDisposition,
           dwFlagsAndAttributes,
           hTemplateFile);
}


// Address: 0x00416B98; symbol: CreateDirectoryA
BOOL __stdcall CreateDirectoryA(LPCSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
{
  return CreateDirectoryA(lpPathName, lpSecurityAttributes);
}


// Address: 0x00416BA0; symbol: CloseHandle
BOOL __stdcall CloseHandle(HANDLE hObject)
{
  return CloseHandle(hObject);
}


// Address: 0x00416BA8; symbol: _stricoll
int __cdecl stricoll(const char *Str1, const char *Str2)
{
  return _stricoll(Str1, Str2);
}


// Address: 0x00416BB0; symbol: _strdup
char *__cdecl strdup(const char *Src)
{
  return _strdup(Src);
}


// Address: 0x00416BB8; symbol: strstr
char *__cdecl strstr(const char *Str, const char *SubStr)
{
  return strstr(Str, SubStr);
}


// Address: 0x00416BC0; symbol: strrchr
char *__cdecl strrchr(const char *Str, int Ch)
{
  return strrchr(Str, Ch);
}


// Address: 0x00416BC8; symbol: strcpy
char *__cdecl strcpy(char *Dest, const char *Source)
{
  return strcpy(Dest, Source);
}


// Address: 0x00416BD0; symbol: strcat
char *__cdecl strcat(char *Dest, const char *Source)
{
  return strcat(Dest, Source);
}


// Address: 0x00416BE0; symbol: sub_416BE0
void __thiscall sub_416BE0(void *Memory)
{
  void *v1; // ebx

  v1 = Memory;
  *(_DWORD *)Memory = &off_419DD8;
  nullsub_1();
  j_j_free(v1);
}


// Address: 0x00416C10; symbol: sub_416C10
int __thiscall sub_416C10(_DWORD *this)
{
  *this = &off_419DD8;
  return nullsub_1();
}


// Address: 0x00416C20; symbol: sub_416C20
void __thiscall sub_416C20(void *Memory)
{
  void *v1; // ebx

  v1 = Memory;
  *(_DWORD *)Memory = &off_419E04;
  sub_416C10(Memory);
  j_j_free(v1);
}


// Address: 0x00416C50; symbol: sub_416C50
int __thiscall sub_416C50(_DWORD *this)
{
  *this = &off_419E04;
  return sub_416C10(this);
}


// Address: 0x00416C60; symbol: sub_416C60
int __thiscall sub_416C60(void *this, int a2, int a3, unsigned int a4)
{
  void *v4; // esi
  int result; // eax

  v4 = this;
  result = sub_417000(a2);
  if ( !(_BYTE)result && a4 <= 3 )
    result = (*(int (__thiscall **)(int, void *, int))(*(_DWORD *)a2 + 20))(a2, v4, a3);
  return result;
}


// Address: 0x00416CB0; symbol: sub_416CB0
int __stdcall sub_416CB0(int a1, int a2, _DWORD *a3)
{
  int result; // eax

  result = sub_417000(a1);
  if ( (_BYTE)result )
  {
    a3[3] = 8;
    a3[1] = 6;
    *a3 = a2;
  }
  return result;
}


// Address: 0x00416CF0; symbol: sub_416CF0
signed int __thiscall sub_416CF0(int *this, int a2, _DWORD *a3)
{
  int v3; // eax
  signed int result; // eax
  int v5; // [esp+10h] [ebp-1Ch]
  int v6; // [esp+14h] [ebp-18h]
  int v7; // [esp+18h] [ebp-14h]
  int v8; // [esp+1Ch] [ebp-10h]

  v3 = *this;
  v5 = 0;
  v6 = 0;
  v7 = 16;
  v8 = 0;
  (*(void (__stdcall **)(int, _DWORD, int *))(v3 + 24))(a2, *a3, &v5);
  result = 0;
  if ( (v6 & 6) == 6 )
  {
    *a3 = v5;
    result = 1;
  }
  return result;
}


// Address: 0x00416D60; symbol: sub_416D60
int __stdcall sub_416D60(int a1, int a2, int a3, int a4, int a5, int a6, _DWORD *a7)
{
  int result; // eax

  if ( a4 == a6 && (unsigned __int8)sub_417000(a5) )
  {
    a7[2] = a2;
    result = 0;
  }
  else
  {
    if ( (unsigned __int8)sub_417000(a3) )
    {
      *a7 = a4;
      a7[3] = 1;
      a7[1] = a2;
    }
    result = 0;
  }
  return result;
}


// Address: 0x00416DE0; symbol: sub_416DE0
int __stdcall sub_416DE0(int a1, int a2, int a3, int a4)
{
  return 5 * (a4 == a2) + 1;
}


// Address: 0x00416E00; symbol: sub_416E00
int __thiscall sub_416E00(_DWORD **this, int a2, int a3, _DWORD *a4)
{
  _DWORD **v4; // ebp
  int result; // eax

  v4 = this;
  result = sub_416CB0(a2, a3, a4);
  if ( !(_BYTE)result )
    result = (*(int (__stdcall **)(int, int, _DWORD *))(*v4[2] + 24))(a2, a3, a4);
  return result;
}


// Address: 0x00416E60; symbol: sub_416E60
int __thiscall sub_416E60(_DWORD **this, int a2, int a3, int a4, int a5, int a6, int a7, _DWORD *a8)
{
  char v8; // al
  int v9; // edx
  int result; // eax
  char v11; // al
  _DWORD **v12; // [esp+18h] [ebp-24h]

  v12 = this;
  v8 = sub_417000(a4);
  v9 = a4;
  if ( v8 )
  {
    *a8 = a5;
    a8[1] = a3;
    if ( a2 < 0 )
    {
      if ( a2 == -2 )
        a8[3] = 1;
    }
    else
    {
      a8[3] = 5 * (a7 == a5 + a2) + 1;
    }
    result = 0;
  }
  else if ( a5 == a7 && (v11 = sub_417000(a6), v9 = a4, v11) )
  {
    a8[2] = a3;
    result = 0;
  }
  else
  {
    result = (*(int (__stdcall **)(int, int, int, int, int, int, _DWORD *))(*v12[2] + 28))(a2, a3, v9, a5, a6, a7, a8);
  }
  return result;
}


// Address: 0x00416F50; symbol: sub_416F50
int __thiscall sub_416F50(_DWORD **this, int a2, int a3, int a4, int a5)
{
  _DWORD **v5; // edx
  int result; // eax
  _DWORD **v7; // ST1C_4
  char v8; // al

  v5 = this;
  if ( a5 == a3 && (v7 = this, v8 = sub_417000(a4), v5 = v7, v8) )
    result = 6;
  else
    result = (*(int (__stdcall **)(int, int, int, int))(*v5[2] + 32))(a2, a3, a4, a5);
  return result;
}


// Address: 0x00416FF0; symbol: sub_416FF0
int sub_416FF0()
{
  return 0;
}


// Address: 0x00417000; symbol: sub_417000
bool __thiscall sub_417000(const char **this, int a2)
{
  if ( (const char **)a2 == this )
    return 1;
  if ( *this[1] == 42 )
    return 0;
  return strcmp(this[1], (const char *)((**(_BYTE **)(a2 + 4) == 42) + *(_DWORD *)(a2 + 4))) == 0;
}


// Address: 0x00417080; symbol: nullsub_1
void nullsub_1()
{
  ;
}


// Address: 0x00417090; symbol: j_free
void __cdecl j_free(void *Memory)
{
  free(Memory);
}


// Address: 0x004170A0; symbol: j_j_free
void __cdecl j_j_free(void *Memory)
{
  j_free(Memory);
}


// Address: 0x004170B0; symbol: sub_4170B0
void sub_4170B0()
{
  dword_45E3C0 = 1;
  dword_45E3C4 = 0;
  dword_45E3C8 = 0;
  dword_45E3CC = 0;
}


// Address: 0x004170E0; symbol: sub_4170E0
int __cdecl sub_4170E0(char a1)
{
  HKEY *phkResult; // ebx
  char v2; // al
  DWORD *lpdwDisposition; // esi
  HMODULE v4; // eax
  HKEY *v6; // edx
  char v7; // al
  struct _STARTUPINFOA StartupInfo; // [esp+1Ch] [ebp-5Ch]
  char *v9; // [esp+6Ch] [ebp-Ch]

  v9 = &a1;
  sub_4147A0();
  phkResult = (HKEY *)GetCommandLineA();
  GetStartupInfoA(&StartupInfo);
  if ( phkResult )
  {
    while ( 1 )
    {
      v2 = *(_BYTE *)phkResult;
      if ( *(_BYTE *)phkResult != 32 && v2 != 9 )
        break;
      phkResult = (HKEY *)((char *)phkResult + 1);
    }
    if ( v2 == 34 )
    {
      do
      {
        v6 = phkResult;
        phkResult = (HKEY *)((char *)phkResult + 1);
        v7 = *(_BYTE *)phkResult;
      }
      while ( *(_BYTE *)phkResult != 34 && v7 );
      if ( v7 == 34 )
        phkResult = (HKEY *)((char *)v6 + 2);
    }
    else
    {
      while ( *(_BYTE *)phkResult & 0xDF && *(_BYTE *)phkResult != 9 )
        phkResult = (HKEY *)((char *)phkResult + 1);
    }
    while ( *(_BYTE *)phkResult == 32 || *(_BYTE *)phkResult == 9 )
      phkResult = (HKEY *)((char *)phkResult + 1);
  }
  lpdwDisposition = (DWORD *)10;
  if ( StartupInfo.dwFlags & 1 )
    lpdwDisposition = (DWORD *)StartupInfo.wShowWindow;
  v4 = GetModuleHandleA(0);
  return sub_407580((DWORD)v4, 0, phkResult, lpdwDisposition);
}


// Address: 0x004171B0; symbol: sub_4171B0
int sub_4171B0()
{
  return sub_401340();
}

