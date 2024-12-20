#------ TARGET ------#
NAME		:= PmergeMe #$(notdir $(CURDIR))
#------ WFLAGS ------#
D_FLAGS		= -Wall -Wextra -std=c++98 -Werror #-pg #-Wshadow#-Wno-unused-function -Wunused
INC	+= -I include/
#------ SRC FILES & DIRECTORIES ------#
SRC_DIR		:= src/
SRC			:= $(shell find $(SRC_DIR) -name '*.cpp' ! -name 'main.cpp')
MAIN		:= $(shell find $(SRC_DIR) -name 'main.cpp')
SRC			+= $(MAIN)
PROJECT_ROOT:= $(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../)
GIT_REPO	:=$(abspath $(dir $(lastword $(MAKEFILE_LIST)))/../..)
DIRS		:= $(abspath $(dir $(shell find $(PROJECT_ROOT) -name Makefile | sort)))
CURRENT		:= $(shell basename $$PWD)
DEBUG_PATH	:= debug
BUILD_DIR	:= .build/
#------ DEBUG FLAG ------#
D			= 0
#------ Sanitizer Flag ------#
S			= -1
#------ DEBUG UTILS ------#
CXX			:= c++
MAKEFLAGS	+= --no-print-directory #--jobs
VALGRIND	:= valgrind -s --leak-check=yes --show-leak-kinds=all -q 
HELGRIND	:= valgrind -s --tool=helgrind
MAC_LEAKS	:= leaks -atExit --

#------ ADDING DEBUG FLAGS ------#
ifneq ($(D), 0)
CXX			= g++
DEBUG_DIR	:= $(NAME).dSYM
OBJS := $(addprefix $(BUILD_DIR), $(notdir $(SRC:%.cpp=%.o)))
#------ CODE FOR OBJECT FILES ------#
# The `vpath` directive in a Makefile is used to specify a list of
# directories that `make` should search when it's looking for
# prerequisites. 
vpath %.cpp $(sort $(dir $(SRC)))
DEPS		:= $(OBJS:.o=.d)
#DEPENDENCIES := $(shell find $(BUILD_DIR) -name '*.d')
-include $(DEPS) # to include in compilation
D_FLAGS		+= -O0 -g3 #-Og optimization + good debuggin experience
# ASAN_OPTIONS=detect_leaks=1 # in case platform leaks detections is not enable
DEBUG_FLAG	:= $(D)
ifeq ($(DEBUG_FLAG), )
D_FLAGS		+= -DDEBUG=0
else
D_FLAGS		+= -DDEBUG=$(D)
endif
D_FLAGS		+= -Wconversion -Wsign-conversion -pedantic
D_FLAGS		+= -fno-omit-frame-pointer
# /// When debug folder is available///
# DEBUG_SRC	:= $(shell find $(DEBUG_PATH) -name '*.cpp')
# SRC			+= $(DEBUG_SRC)
# INC	+= -I $(DEBUG_PATH)/include
# else
# MAIN		:= $(SRC_DIR)main.cpp
# SRC			+= $(MAIN)
else
OBJS		:= $(SRC)
# D_FLAGS		+= -Werror 
endif
# MAKEFLAGS	+= -j4 #--debug #// -j for multinodes
ifeq ($(S), 1)
#------ INCLUDE SANATIZER FLAGS ------#
D_FLAGS		+= -fsanitize=address,undefined,vptr
endif
# To enable verbose output during compilation Make V=1
V ?= 0
ifeq ($(V),1)
VERBOSE = @
D_FLAGS		+= -ftime-report
else
VERBOSE =
endif
#-------------------- RULES ----------------------------#
all:$(NAME)

$(NAME): $(OBJS)
ifneq ($(D), 0)
	@printf "$(LF)\n$(P_BLUE)☑️  Successfully Created $(P_YELLOW)$(NAME)'s Object files ☑️$(FG_TEXT)\n"
endif
	@printf "\n"
	@printf "$(LF)⚙️ $(P_BLUE) Create $(P_GREEN)$@ ⚙️\n"
	@echo $(GREEN)
	@printf "$(CXX) $(D_FLAGS) $(INC) $(P_YELLOW) $^ $(P_GREEN) -o $@ $(FG_TEXT) \n\n";
	@$(CXX) $(D_FLAGS) $(INC) $^ -o $(NAME)
	@printf "\n$(LF)✅ $(P_BLUE)Successfully Created $(P_GREEN)$@! ✅\n$(P_NC)"
	@echo $(CYAN) "$$CPP" $(E_NC)
	@echo "$$MANUAL" $(E_NC)

ifneq ($(D), 0)
$(OBJS): $(BUILD_DIR)%.o : %.cpp | $(BUILD_DIR)
	@$(CXX) $(D_FLAGS) $(INC) -MMD -MP -c $< -o $@
	@printf "$(LF)🚧 $(P_BLUE)Creating $(P_YELLOW)$@ $(P_BLUE)from $(P_YELLOW) $< $(FG_TEXT)\n"
	@printf "$(P_BLUE)$(CXX) $(D_FLAGS) $(INC) $(P_YELLOW) -MMD -MP -c $< $(P_BLUE) -o $@ $(FG_TEXT) \n\n";

$(BUILD_DIR):
	@mkdir -p $@
endif

.PHONY: clean fclean re test val leaks

clean:
	@echo;
	@if [ -d "$(BUILD_DIR)" ]; then	\
		rm -rf $(BUILD_DIR); 		\
		printf "$(LF)🧹 $(P_RED) Clean $(P_YELLOW)$(NAME)'s Object files$(P_NC)\n"; \
	fi
	@if [ -d "$(DEBUG_DIR)" ]; then	\
		rm -rf $(DEBUG_DIR); 		\
	fi
	@printf  "\n$(P_NC)"

fclean: clean
	@if [ -f $(NAME) ]; then	\
		printf "$(LF)🧹 $(P_RED) Clean $(P_GREEN) $(CURRENT)/$(NAME)\n";	\
		rm -rf $(NAME);														\
		echo $(WHITE) "$$TRASH" $(E_NC);									\
	else																	\
		printf "$(LF)🧹$(P_RED) Clean $(P_GREEN) $(CURRENT)\n";			\
	fi
	@printf "\n$(P_NC)"

re: fclean all

#------------- TEST UTILS -----------------------------------#

#make check f=file -> check file syntax
check:
	@g++ $(D_FLAGS) $(INC) -fsyntax-only $(f); \
	ret=$$? ; \
	if [ $$ret = 0 ]; then \
		echo  $(f) [$(GREEN) OK $(E_NC)]; \
	fi
test: $(NAME)
	@echo $(BOLD) $(CYAN) ./$(NAME) "$(i)" $(E_NC) "\n"; \
	if [ "$(S)" = "0" ]; then \
		echo $(E_NC); $(MAKE) -C . val; \
	else \
		if [ -z "$(i)" ]; then \
			echo $(E_NC); ./$(NAME) ; \
		else \
			echo $(E_NC); ./$(NAME) $(i); \
		fi; \
	fi;
#num=$$(shuf -i 0-2147483647 -n $$max); \;
#num=$$(shuf -i 0-5000 -n $$max); \
num=$$(seq 1 $$max | awk '{print rand() * 5000}'); \;
run:$(NAME)
	@range=0; \
	if [ -z "$(i)" ]; then \
		range=20; \
	else \
		range=$(i); \
	fi; \
	max=$$(shuf -i 1-$$range -n 1); \
	echo "elements: $$max"; \
	num=$$(shuf -i 0-10000 -n $$max); \
	echo $(BOLD) $(CYAN) ./$(NAME) $$num $(E_NC) "\n"; \
	if [ "$(S)" = "0" ]; then \
		echo $(E_NC); $(MAKE) -C . val num="'$$num'"; \
	else \
		echo $(E_NC); ./$(NAME) $$num; \
	fi; \
	echo "------------------------------------\n";
t:
	@num="7482 3202 3671 9133 2049 1445 1987"; \
	echo $(BOLD) $(CYAN) ./$(NAME) $$num $(E_NC) "\n"; \
	if [ "$(S)" = "0" ]; then \
		echo $(E_NC); $(MAKE) -C . val num="$$num"; \
	else \
		echo $(E_NC); ./$(NAME) $$num; \
	fi; \
	echo "------------------------------------\n"; 
t0:
	@num="7482 3202 3671 9133 2049 1445 1987 9460 1352 3485 8473 1234 5678 9101 1121 3141"; \
	echo $(BOLD) $(CYAN) ./$(NAME) $$num $(E_NC) "\n"; \
	if [ "$(S)" = "0" ]; then \
		echo $(E_NC); $(MAKE) -C . val num="$$num"; \
	else \
		echo $(E_NC); ./$(NAME) $$num; \
	fi; \
	echo "------------------------------------\n"; 
t1:$(NAME)
	@num="2249 4316 2678 4676 3666 2147 2574 2688 4426 3229 4462 1676 4251 969 2630 3129 331 4905 3817 2161 3936 795 478 3567 4044 2485 2128 2770 2975 1515 4187 298 2947 341 2342 3788 4332 239 425 2514 409 2718 3001 3187 2251 2302 28 2238 1512 1701 2258 1168 1800 552 4762 1694 2052 4489 2903 4019 856 2261 755 3455 4635 2567 1325 3484 294 2029 2506 4708 2046 4771 4178 2867 4796 1920 135 2434 4070 1314 2887 2606 1341 163 3921 358 4987 4169 4609 4464 1195 686 2495 3886 4204 1953 1759 3501 1502 1939 1494 2143 4237 1789 3824 4209 3347 2308 746 4023 4165 3358 693 3117 636 3847 1326 3830 2777 69 2907 83 4063 3422 4095 4335 834 2113 332 2843 2846 4896 698 3925 1291 2472 4627 2963 3150 1798 629 720 2591 4646 230 206 1684 1873 4189 1655 4965 1452 4904 2974 289 3259 3837 3947 3979 1021 3869 251 2381 1234 3572 1190 260 4577 2683 2193 221 3497 3944 1627 634 3771 1489 3414 1437 1568 3644 911 3493 2760 1881 2339 1877 3984 4013 4105 1666 2229 1624 2398 2175 870 1203 4123 537 3849 4435 2203 4429 1908 53 4930 1896 2650 767 1563 3832 2108 1049 3663 3808 1559 2140 2076 3722 1689 3833 2744 3615 4436 5 4700 431 220 2563 4979 1906 1640 153 200 4732 1284 4518 4180 4068 3273 3064 1002 3776 4295 3891 3288 765 4140 3450 4028 4509 2772 2445 2504 1102 1155 4922 1199 4949 2002 408 3526 2415 3370 2211 878 1062 2118 3485 2775 2248 666 2096 4980 2981 4531 3274 798 5000 614 2706 4298 1748 669 1066 2294 800 308 2263 4344 3145 1864 504 1073 2751 2309 3653 4899 3103 1695 1638 382 893 4952 4718 1535 1047 3647 4323 3718 4240 3444 3061 601 3792 3852 4399 1740 204 3542 4599 1827 2050 654 1688 2061 617 1351 3175 1240 627 3252 4372 580 1386 2814 1712 4020 1220 2732 4813 2082 4959 1653 1895 3270 4680 349 529 1921 3913 459 2178 4 4891 1499 4306 2750 3408 590 1710 1349 610 1711 2604 1441 16 3829 1922 1751 2976 3206 4390 1367 1110 1288 4470 4308 1112 1904 1951 3798 3401 171 4535 4656 1854 3971 784 1500 2628 3364 3192 2473 3410 1105 4658 2011 143 4757 3590 2288 4525 522 1565 86 1814 2090 3415 4705 26 650 4406 2714 4312 3806 2242 44 3972 4181 3087 510 126 3843 1290 4562 1763 1863 1818 4354 3894 1347 2820 4146 4830 3797 2653 955 1769 637 2120 455 1766 769 3956 917 1838 2761 1733 3699 3851 1757 3652 3960 1879 1495 3348 3585 2425 4041 3618 3804 154 2801 1875 2852 1014 2028 3782 1508 146 3563 3539 4183 1541 1503 4717 3174 196 1317 2055 4115 890 1892 1261 703 3576 322 4083 1537 4543 3143 419 2699 2333 149 3642 1952 921 1544 263 1368 347 2759 1231 3793 1053 1822 4272 3985 4238 1477 1332 2948 3994 2450 1778 3890 1210 1670 42 4566 4418 3998 240 1642 2012 620 1713 4852 2841 4217 4016 284 1529 3999 1910 3082 3022 2946 2894 2221 553 363 855 4468 4947 3973 2585 3115 1260 368 3892 480 1321 1470 4098 1304 1882 1965 1899 152 532 2424 2482 3593 3170 2165 1415 3940 745 810 1522 4945 3742 1005 3141 3969 819 2378 4835 2704 712 778 3640 3453 2656 3856 2180 4297 207 2729 1217 1628 4257 1807 1634 1668 4106 3507 2973 1180 4288 1795 1081 4072 2085 3127 4964 3204 3267 3214 1916 387 1320 3658 2429 4804 4161 3339 961 801 1485 441 4688 585 131 1208 3221 3649 549 2898 4519 3218 3308 2414 1033 4488 3430 4935 1577 2603 4182 723 147 941 571 1747 4985 2838 424 3881 3726 2163 3862 3008 2170 713 271 643 113 2206 613 719 2980 3310 2421 3291 1511 2272 1590 1249 4428 3668 4702 707 214 216 2667 1323 587 1004 15 1605 927 4582 1476 4882 2509 4367 3121 2077 4014 2297 925 2600 4878 4174 3424 3982 4164 4937 2834 4844 747 3579 3062 2879 2039 4948 1283 3514 3476 2764 4442 4917 2959 4065 3205 1744 99 3007 4972 2763 4504 2638 3456 4711 930 3459 2757 4027 692 3173 1273 4483 438 1104 4916 3667 3423 3412 3863 2728 4005 1792 901 4626 2724 2320 863 2416 2668 978 3671 1762 939 1861 1623 2092 4443 3864 3314 2292 4768 4534 4978 2073 4946 3071 3932 2931 2347 3831 3287 1450 3785 1303 4304 788 760 4162 852 13 1201 2160 1955 3049 1890 598 3060 1783 2447 799 4907 2401 2040 3502 1430 718 524 892 3818 400 1114 3208 1557 3538 2310 1594 4620 2044 2651 3447 2017 2179 2614 1697 2173 272 2646 314 538 3506 3688 4834 4496 2635 1996 4554 4689 61 2045 339 1934 3951 3351 1519 193 1045 2914 1173 128 4629 2412 3118 752 3006 1318 4529 2109 4425 102 356 4099 1482 4278 4731 2137 2909 2442 2303 3381 2195 4973 2441 1414 3119 1646 2689 1117 4125 2921 4058 3596 4511 2869 2355 2520 2682 3100 119 3025 4421 1966 1961 2270 2645 1636 3258 2177 4130 4003 4365 2522 1641 1164 1753 4863 4833 3020 1504 4919 396 831 4454 1583 754 1402 3689 943 2698 2363 359 3051 3405 2538 2992 822 457 733 4849 928 3292 4494 3835 768 2466 3113 1345 3228 4453 664 1301 35 1392 4498 2049 1549 3330 1801 3875 4547 4056 3625 3168 168 936 2388 236 4215 2800 865 1355 2491 1003 25 1242 252 2084 181 3646 3058 4290 340 4592 3240 3638 520 122 3112 2436 1411 64 3587 1115 2422 2608 2321 3148 2375 1946 4775 1671 2842 880 3027 2895 3814 3697 2427 3454 1513 3016 2616 578 2878 4662 2354 697 577 729 4693 2710 3200 1243 1400 740 4062 4112 1375 561 572 1538 4574 4100 4481 2255 4438 4974 2475 3172 156 1327 2912 2035 2961 4111 3467 1589 3180 2631 3397 1118 3290 2264 2665 1150 1994 2406 1393 4668 202 1734 4008 3263 3941 470 2215 4999 602 3799 4393 4575 4412 3406 4758 3807 3949 1617 2345 3431 2927 3783 1941 1350 1656 4371 1912 2633 3620 3039 2087 673 1124 4780 1699 814 4871 2033 3359 4387 4229 982 3912 3767 565 307 4767 3249 4449 2611 843 2344 4274 3004 2916 2934 3530 3465 1458 78 1950 1597 1845 2220 2715 3813 1397 18 551 2908 1294 837 1413 2675 2601 2792 1929 4320 1547 4138 4171 2149 3219 370 2900 4149 2774 3839 3400 998 132 3616 1340 4352 1125 4047 1776 4820 4638 3645 4970 3889 4341 559 3720 2935 777 2930 3717 1232 3374 1954 4090 1940 4906 4895 2102 1439 3076 4188 3574 2499 2273 1970 2312 897 1373 2832 3451 895 2610 4343 3171 4723 2341 328 3102 1743 4283 1927 3757 836 853 2741 4838 1098 4458 2805 4828 2291 531 1812 2962 4463 417 415 87 357 1853 2241 249 4943 3260 2951 933 3910 3096 1269 1632 3133 282 237 4307 1591 4586 3957 4398 4707 304 3329 4697 3692 2726 3865 2010 210 4213 3043 3481 604 592 4084 516 19 4497 4480 2394 2064 350 1237 4677 596 3532 2939 3525 2200 3033 2640 3396 371 1311 98 4603 2493 973 3745 2560 2773 2387 3927 626 1911 49 4465 2670 3149 3983 4260 1691 2876 1460 1187 4490 2136 3916 2323 3210 4203 460 3107 4600 2223 648 4992 4682 3283 2870 4727 2821 3345 1084 2671 2990 4885 981 4033 3551 243 3675 71 3707 1947 2904 1044 1956 1726 3461 316 4133 2960 3398 3939 3885 491 2004 4837 446 848 1130 968 2325 2572 1730 4788 3899 2331 2740 1448 2970 1550 2228 2632 3533 291 1931 1679 3047 301 2968 1756 52 3603 690 2484 4699 3838 3825 2154 4294 1223 2564 662 3028 2966 4527 4791 2905 3093 4831 2996 2299 4819 1353 2295 4523 3340 1945 4990 375 1693 2464 705 2579 12 3281 4053 4330 3974 772 2652 4253 543 721 1149 3026 906 1087 656 85 4317 2987 2891 3065 4248 2332 1137 1696 3970 3702 2691 283 1109 3679 695 499 1147 4573 379 839 2525 124 2515 817 4315 167 756 967 507 3201 1542 2964 3529 490 4598 2957 4933 1808 3245 763 6 670 525 1645 3151 2057 4704 1771 3188 3893 3828 1764 2780 4602 3903 3834 1663 4522 1815 907 4391 2411 1239 2328 2548 3120 584 2580 3265 2892 3611 2334 1871 3938 2906 2201 674 1647 679 582 4652 3621 2995 385 4754 2224 1271 1027 3589 2185 605 739 123 2364 269 2315 4137 4143 1999 1040 2856 1709 2370 4091 2393 2507 2578 4953 514 4313 2565 741 2686 1227 1869 597 3958 2476 4420 860 3317 4319 2784 904 3034 4809 4346 735 4345 2001 1433 1897 2875 3123 1507 1604 3962 1705 1760 1501 4351 2365 1680 1648 1412 3072 1725 3498 1874 4733 4639 130 1475 1746 4928 1026 3325 3919 365 829 4437 1566 383 4720 4632 1281 1099 3626 435 2230 3846 564 1768 3975 4057 2330 2862 833 4856 1857 2802 2581 4452 1703 1194 3980 1292 699 2032 2301 4471 1215 806 3052 487 3713 2367 89 691 462 4225 2621 3243 1161 1185 4726 261 566 4407 1610 1058 4637 4184 1409 2582 4800 1969 2391 3904 1438 2929 1564 30 1016 1728 889 611 781 4735 3097 3601 3169 1851 3543 1299 2219 2243 2247 1571 1915 2599 1802 3184 3395 1339 1572 4516 1103 4444 2239 1803 4801 1405 4392 3230 3678 3780 3352 1116 3268 2390 1533 2158 1068 274 1554 4836 3749 3566 1071 1825 2615 3760 4160 4258 791 4303 1365 2690 4414 3737 885 3594 2360 4875 4032 97 4226 1307 2793 3457 1942 2607 4336 4510 2695 4266 886 808 267 3661 926 2349 213 3489 1752 2067 109 4818 190 2672 3458 2708 197 2730 2169 2148 2232 268 818 2156 3633 2831 2954 908 2917 344 2798 2216 3619 4374 1169 4622 4153 1933 4991 1070 4774 3003 1009 2237 4127 4011 1930 2866 4530 1520 4542 323 4560 4197 4559 1582 1192 1064 472 234 3436 3801 312 4166 2409 1985 4524 4195 1434 4291 2553 161 3081 278 317 3038 1517 4625 3871 2797 2065 794 3536 2783 3906 2702 3354 1651 4694 1133 3215 4206 3605 1723 2781 3059 388 1990 1917 174 3714 1852 4853 3822 1561 2819 111 3285 2557 342 2430 74 645 942 2122 2799 4281 2687 2385 2742 4176 2037 4001 2003 179 2944 588 4388 2256 4546 862 2861 4433 2526 4396 2717 4631 2725 2359 4521 1560 3487 3706 977 3966 764 3186 2626 2458 481 550 574 3377 4216 164 2265 4243 2313 589 4265 3710 180 1167 3520 1113 3964 4675 2389 2636 2657 3388 3756 2357 758 226 554 2674 2399 2086 3136 825 945 4512 3872 421 1620 335 4079 4113 1371 4375 1498 3519 4144 3375 2756 4196 2858 24 1980 3545 1282 2985 3896 4664 711 479 1389 4259 4977 2343 1211 38 2059 1690 46 2020 4173 2477 2871 41 2426 2335 2623 3528 625 432 4825 1126 1993 2749 544 2437 635 775 1 535 3612 1028 1510 3331 4400 548 3733 4361 1145 1963 3017 4249 4657 3575 1148 1925 1378 1202 3732 568 3021 1578 280 4097 2470 1144 199 991 4983 2471 1588 3503 4583 2619 1737 2594 812 912 4690 3251 386 486 518 530 120 2060 75 3583 2009 1179 4432 337 54 3220 4925 1462 2644 493 2540 2103 509 1082 2407 1120 2612 4051 4901 2172 3182 3950 3876 1491 909 2997 3216 1383 4597 1706 2379 330 1417 84 4487 3959 4772 1492 675 2423 253 980 1012 1675 857 3976 2989 4612 1539 1306 1862 845 1446 80 144 3599 3438 115 129 949 1089 2739 2 1054 3608 4605 3524 2306 4655 4394 4466 1235 1092 227 1780 2496 835 338 165 1095 4031 279 4376 2700 233 1186 2716 2795 3750 2498 4822 2849 1032 177 3300 2561 4401 540 3231 2202 2655 4296 4314 1685 3491 1839 3853 4924 498 4839 4864 255 3550 4615 4030 3651 3800 2753 2198 3108 4821 76 3826 2277 3443 4719 1359 2226 3124 2214 2986 3734 957 2669 4175 4007 1621 3213 3032 0 4081 3512 2701 2322 162 82 4593 807 657 2823 4986 3870 3183 3868 1735 787 3371 2926 3685 1023 4829 4671 3272 1876 1606 2659 3768 1056 256 1834 445 428 517 4792 354 134 999 1809 4381 2524 3353 4698 4810 3264 4552 3238 381 4608 3965 3989 900 160 63 1279 882 1377 311 3463 4963 4324 3787 2112 2275 1132 2317 1198 683 4640 1722 612 1154 2461 1222 672 29 3687 1682 659 55 1048 1052 4666 1569 1704 1741 681 2918 1729 389 3992 1229 1872 2528 2446 281 4515 4441 262 2719 757 2117 4861 3883 3176 1454 2677 1449 1296"; \
	echo $(BOLD) $(CYAN) ./$(NAME) $$num $(E_NC) "\n"; \
	if [ "$(S)" = "0" ]; then \
		echo $(E_NC); $(MAKE) -C . val num="$$num"; \
	else \
		echo $(E_NC); ./$(NAME) $$num; \
	fi; \
	echo "------------------------------------\n"; 
# ATTENTION !!!!!!!!!!!!!!  USE WITH S=0 !
val: $(NAME)
	@echo $(RED) $(VALGRIND) ./$(NAME) $(shell echo $(num)) $(E_NC) "\n"
	@$(VALGRIND) ./$(NAME) $(shell echo "$(num)"); echo
leaks: $(NAME)
	@echo $(RED)$(MAC_LEAKS) ./$(NAME) "$i" $(E_NC)  "\n"
	@$(MAC_LEAKS) ./$(NAME)
	@echo "\n"

# #-------------------- GIT UTILS ----------------------------#
info:
	@echo GIT_REPO:  $(CYAN) $(GIT_REPO) $(E_NC)
	@echo PROJECT_ROOT: $(CYAN) $(PROJECT_ROOT) $(E_NC)
	@echo DIRS: $(BOLD) $(DIRS) "\n" $(E_NC)
	@echo CURRENT: $(GREEN) $(CURRENT) $(E_NC)
	@echo SRC: $(YELLOW) $(SRC) $(E_NC)
	@echo OBJS: $(GRAY) $(OBJS) $(E_NC)
	@echo $(BLUE)"\nD = $(D)" $(E_NC)
	@echo $(BLUE)"S = $(S)" $(E_NC)
	@echo $(BLUE)"V = $(V)" $(E_NC)
	@echo $(BLUE)"DEPENDENCIES =" $(DEPENDENCIES) $(E_NC)
testAll:
	@for dir in $(DIRS); do \
		$(MAKE) -C $$dir D=$(D) test; \
	done
cleanAll:
	@for dir in $(DIRS); do \
		$(MAKE) -C $$dir fclean; \
	done
gAdd:
	@echo $(CYAN) && git add $(PROJECT_ROOT)
gCommit:
	@echo $(GREEN) && git commit -e ; \
	ret=$$?; \
	if [ $$ret -ne 0 ]; then \
		echo $(RED) "Error in commit message"; \
		exit 1; \
	fi
gPush:
	@echo $(YELLOW) && git push ; \
	ret=$$? ; \
	if [ $$ret -ne 0 ]; then \
		echo $(RED) "git push failed, setting upstream branch" $(YELLOW) && \
		git push --set-upstream origin $(shell git branch --show-current) || \
		if [ $$? -ne 0 ]; then \
			echo $(RED) "git push --set-upstream failed with error" $(E_NC); \
			exit 1; \
		fi \
	fi
git: fclean
	@if [ -f "$(GIT_REPO)/Makefile" ] && [ -d "$(GIT_REPO)/.git" ]; then \
		$(MAKE) -C "$(GIT_REPO)" git; \
	else \
		$(MAKE) -C "$(PROJECT_ROOT)/$(CURRENT)" cleanAll gAdd gCommit gPush; \
	fi
quick: cleanAll
	@echo $(GREEN) && git commit -am "* Update in files: "; \
	ret=$$? ; \
	if [ $$ret -ne 0 ]; then \
		exit 1; \
	else \
		$(MAKE) -C . gPush; \
	fi
soft:
	@if [ -f "$(GIT_REPO)/Makefile" ]; then	\
		$(MAKE) -C $(GIT_REPO) soft || \
		if [ $$? -ne 0 ]; then \
			echo $(RED) GIT_REPO not found $(E_NC); \
		fi \
	fi
temp:
	@printf '%b\n' "$${MAIN_CONTENT}\n" | pygmentize -l cpp
	@printf '%b\n' "$${HEADER_CONTENT}\n" | pygmentize -l cpp
	@printf '%b\n' "$${CPP_CONTENT}\n" | pygmentize -l cpp
cpp: # Usage: make cpp h=filename
	@if [ ! -d "include" ]; then \
		mkdir include; \
	fi
	@if [ ! -z "$(h)" ] && [ ! -f "include/$(h).hpp" ]; then \
		UPPER_H=$$(echo $(h) | tr a-z A-Z)_HPP; \
		HEADER_PATH="include/$(h).hpp"; \
		printf "$${HEADER_CONTENT}" | sed -e 's/{{UPPER_H}}/'"$$UPPER_H"'/' \
		-e 's/{{CLASS_NAME}}/$(h)/g' > $$HEADER_PATH; \
		echo "$$HEADER_PATH was created"; \
	fi
	@if [ ! -d "src" ]; then \
		mkdir src; \
	fi
	@for file in include/*.hpp; do \
		cpp_file="src/$$(basename "$${file%.*}").cpp"; \
		if [ ! -f "$$cpp_file" ]; then \
			class_name="$$(basename "$${file%.*}")"; \
			echo "$${CPP_CONTENT}" | sed -e "s/{{CLASS_NAME}}/$$class_name/g" > "$$cpp_file"; \
			echo "$$cpp_file was created"; \
		fi; \
	done
	@echo "Recently Created/Modified files:"; find . -type f \( -name "*.cpp" -o -name "*.hpp" \) -mmin -5 | sort -r
content:
	@find . -type f \( -name "*.cpp" -o -name "*.hpp" \) | sort
main:
	@if [ ! -f "src/main.cpp" ]; then \
		printf "$${MAIN_CONTENT}" > src/main.cpp; \
		echo "src/main.cpp was created"; \
	fi
#	find . -type f \( -name "*.hpp" ! -name "Utils.hpp" \) -exec basename {} \;

#--------------------COLORS----------------------------#
# For print
CL_BOLD  = \e[1m
RAN	 	 = \033[48;5;237m\033[38;5;255m
D_PURPLE = \033[1;38;2;189;147;249m
D_WHITE  = \033[1;37m
NC	  	 = \033[m
P_RED	 = \e[1;91m
P_GREEN  = \e[1;32m
P_BLUE   = \e[0;36m
P_YELLOW = \e[1;33m
P_CCYN   = \e[0;1;36m
P_NC	 = \e[0m
LF	   = \e[1K\r$(P_NC)
FG_TEXT  = $(P_NC)\e[38;2;189;147;249m
# For bash echo
CLEAR  = "\033c"
BOLD   = "\033[1m"
CROSS  = "\033[8m"
E_NC   = "\033[m"
RED	= "\033[1;31m"
GREEN  = "\033[1;32m"
YELLOW = "\033[1;33m"
BLUE   = "\033[1;34m"
WHITE  = "\033[1;37m"
MAG	= "\033[1;35m"
CYAN   = "\033[0;1;36m"
GRAY   = "\033[1;90m"
PURPLE = "\033[1;38;2;189;147;249m"

define CPP

			⠀⠀⠀⠀⠀⠀⢀⣠⣴⣻⣽⣻⢦⣄⡀⠀⠀⠀⠀⠀⠀
			⠀⠀⠀⣀⣤⢶⣻⡽⣞⣧⢷⢯⣟⡾⣽⣳⣤⣀⠀⠀⠀
			⣠⣴⣞⣯⢯⣟⣧⠿⠙⠚⠛⠛⠊⠟⡷⣽⣞⣽⡻⣦⣄
			⣟⡾⣽⡺⣟⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⣞⣷⣻⣷⣿
			⣯⣟⡾⣽⠁⠀⠀⢀⡴⣖⣶⣲⢦⡀⣀⣴⣾⣿⣿⣿⣿
			⣷⣿⣿⡇⠀⠀⠀⣾⣿⣿⣶⣿⣿⣿⣿⣿⢻⣿⣿⢻⣿
			⣯⢿⡽⡃⠀⠀⠀⢷⣯⣿⣿⣿⣿⣿⣿⣶⣰⣾⣶⣰⣾
			⣯⢷⣻⡽⡀⠀⠀⠈⠻⠿⠿⠿⠟⠁⠉⠻⢿⣿⣿⣿⣿
			⣯⣟⣷⣿⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣿⣿⣿⣿⣿
			⠙⠻⢿⣿⣿⣿⣿⣶⣤⣤⣤⣤⣤⣶⣿⣿⣿⣿⡿⠟⠋
			⠀⠀⠀⠈⠛⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠉⠀⠀⠀
			⠀⠀⠀⠀⠀⠀⠈⠙⠻⢿⣿⡿⠟⠋⠁⠀⠀⠀⠀⠀⠀

endef
export CPP

define TRASH

			⠀⠀⠀⠀⠀⠀⢀⣠⣤⣤⣤⣤⣤⣄⡀⠀⠀⠀⠀⠀⠀
			⠀⠀⠀⠀⣰⣾⠋⠙⠛⣿⡟⠛⣿⣿⣿⣷⣆⠀⠀⠀⠀
			⠀⠀⢠⣾⣿⣿⣷⣶⣤⣀⡀⠐⠛⠿⢿⣿⣿⣷⡄⠀⠀
			⠀⢠⣿⣿⣿⡿⠿⠿⠿⠿⠿⠿⠶⠦⠤⢠⣿⣿⣿⡄⠀
			⠀⣾⣿⣿⣿⣿⠀⣤⡀⠀⣤⠀⠀⣤⠀⢸⣿⣿⣿⣷⠀
			⠀⣿⣿⣿⣿⣿⠀⢿⡇⠀⣿⠀⢠⣿⠀⣿⣿⣿⣿⣿⠀
			⠀⢿⣿⣿⣿⣿⡄⢸⡇⠀⣿⠀⢸⡏⠀⣿⣿⣿⣿⡿⠀
			⠀⠘⣿⣿⣿⣿⡇⢸⡇⠀⣿⠀⢸⡇⢠⣿⣿⣿⣿⠃⠀
			⠀⠀⠘⢿⣿⣿⡇⢸⣧⠀⣿⠀⣼⡇⢸⣿⣿⡿⠁⠀⠀
			⠀⠀⠀⠀⠻⢿⣷⡘⠛⠀⠛⠀⠸⢃⣼⡿⠟⠀⠀⠀⠀
			⠀⠀⠀⠀⠀⠀⠈⠙⠛⠛⠛⠛⠛⠋⠁⠀⠀⠀⠀⠀⠀
endef
export TRASH

define MANUAL
$(D_PURPLE)
FLAGS:
	D -> debug information	 (default: 0)
	S -> sanatizer information (default: -1)

Example:
$(D_WHITE)[test]
$(D_PURPLE)$> make D=0 test
$(D_WHITE)[test + DEBUG]
$(D_PURPLE)$> make D=1 test
$(D_WHITE)[DEBUG + Valgrind]
$(D_PURPLE)$> make D=1 S=0 re val
$(D_WHITE)[DEBUG + Sanitizer]
$(D_PURPLE)$> make D=1 S=1 re test

endef
export MANUAL

define HEADER_CONTENT
#ifndef {{UPPER_H}}
# define {{UPPER_H}}

# include <iostream>
# include <sstream>
# include <string>
# include <typeinfo>
# include <Utils.hpp>

# ifndef DEBUG
#  define DEBUG 0
# endif

class {{CLASS_NAME}}
{
	private:

	protected:
		
	public:
		{{CLASS_NAME}}();
		{{CLASS_NAME}}& operator=({{CLASS_NAME}} const& rhs);
		{{CLASS_NAME}}({{CLASS_NAME}} const& rhs);
		virtual ~{{CLASS_NAME}}();
};

// std::ostream& operator << (std::ostream& os, {{CLASS_NAME}}& rhs);

#endif // {{UPPER_H}}
endef
export HEADER_CONTENT
define MAIN_CONTENT
#include <iostream>
$(shell for file in include/*.hpp; do \
	printf '#include "'$$(basename $$file)'"\\n';\
done)
int main(void)
{
	return (0);
}
endef
export MAIN_CONTENT

define CPP_CONTENT
#include "{{CLASS_NAME}}.hpp"

{{CLASS_NAME}}::{{CLASS_NAME}}()
{
}

{{CLASS_NAME}}& {{CLASS_NAME}}::operator=({{CLASS_NAME}} const& rhs)
{

}

{{CLASS_NAME}}::{{CLASS_NAME}}({{CLASS_NAME}} const& rhs)
{

}

{{CLASS_NAME}}::~{{CLASS_NAME}}(void)
{
}

std::ostream& operator << (std::ostream& os, {{CLASS_NAME}}& rhs)
{
	(void)rhs;
	return (os);
}
endef
export CPP_CONTENT

#find . -type f -name "*.*pp" -print | sort -r |  xargs cat | pygmentize -g -O style=material
