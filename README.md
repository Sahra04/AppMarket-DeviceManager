description: mimics an AppMarket and DeviceManager: each device can be loaded with apps from the AppMarket; apps are deep-copied into the device so that if the app is deleted from the AppMarket, it can still exist on the device

compilation instructions: 
1. go to the directory where the file is 
2. type "make"
3. that should make the executable file a2 and a2test

execution instruction for a2test:
1. type "./a2test"  
2. then go through all tests by typing the number associated with test <(ex) test1 -> you will type 1 in order to execute it>

execution instruction for a2:
1. type "./a2"
2. go through all the options you, as a user, would choose

clean object files and executable: 
1. type "make clean"
