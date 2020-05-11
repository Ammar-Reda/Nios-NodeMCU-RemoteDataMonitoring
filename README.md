# Nios-NodeMCU-RemoteDataMonitoring
System on Chip (SoC) using Nios® II processor and NodeMCU(ESP8266) For Remote Data Monitoring.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

These examples use [ModelSim® and Quartus® Prime from Intel FPGA](http://fpgasoftware.intel.com/?edition=lite), [GIT](https://git-scm.com/download/win), [Arduino IDE](https://www.arduino.cc/en/main/Software), make sure they are installed locally on your computer before proceeding.


### Installing

A step by step series of commands and steps that guide you how to get the project env running

1.Grab a copy of this repository to your computer's local folder (i.e. C:\projects):
```
$ cd projects
$ git clone https://github.com/Ammar-Reda/Nios-NodeMCU-RemoteDataMonitoring.git
```
2. The example System on Chip design consists of:
    - Nios&reg; II processor
    - On-Chip memory
    - JTAG UART module
    - Timer core
    - System ID core
    - RS232 UART core
    - SPI (3 Wire Serial) Intel FPGA IP
        
3.  Run the Quartus&reg; Prime Tool to restore (unzip)the Nios&reg; II processor system, then:
  - From the Quartus Menu, choose Project -> Restored Archived Project
  - For the Archive name, fill with: "path to your projects folder"/Nios-NodeMCU-RemoteDataMonitoring/soc_nios.qar
  - Click: Ok
  - From the Menu, choose Processing -> Start -> Start Compilation
  - Wait until the design compilation completes
  - Connect the FPGA Development Board (DE0-NANO) to the any USB port on your computer
  - From the Taskbar, click the Device Programmer icon
  - Click on "Hardware Setup..." and double-click "USB Blaster" then click Close 
  - Click "Add File...", browse to the folder "output_files" in the "soc_nios_restored" folder, select the "soc_nios.sof" file and click Open
  - Click Start to start programming the FPGA device connected to your computer

4. Writing the program to run on the Nios&reg; II:
    - From the Quartus&reg; Prime Menu, choose Tools -> Nios II Software Build Tools for Eclipse
    - When prompted for the Workspace, browse to "your projects folder"/soc_nios_restored/software
    - Click OK
    - From the Nios II - Eclipse Menu, choose File -> New -> Nios II Application and BSP from Template
    - For SOPC Information File name, browse to "your projects folder>/nios-system and open the SOPC Information File: nios_system.sopcinfo
    - In the Project name field, type: nios_program
    - In the Project template, select the "Blank Project" template and click Finish
    - In the Project Explorer view, Right click on "nios_program", choose New -> Source File
    - For the Source file, fill with:"main.c"
    - For Template, Choose -> Default C source template 
    - To build the project, select "nios_program", from the Menu, choose Project -> Build Project
    - To run the C program, select "nios_program", from the Menu, choose Run -> Run As -> Nios II Hardware
    - In the Run Configurations dialog box, click the Target Connection tab, click Refresh Connections, then click Run
    - The Nios II SBT for Eclipse downloads the program to the FPGA on the target board and executes the code


## License

This project is licensed under the MIT License - see the [LICENSE.md](https://github.com/Ammar-Reda/FSMD-MatrixMultiplication/blob/master/LICENSE) file for details

