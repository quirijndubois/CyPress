
<div style="color: green;">

```
                                                        
                                              .*.       
                                             .=++.      
                                            .**++++     
                                           .***+++=.    
                                           .*++++==.    
  _____      _____                         **+++++=.    
 / ____|    |  __ \                       .***+++++=.   
| |    _   _| |__) | __ ___  ___ ___      ****+++++=.   
| |   | | | |  ___/ '__/ _ \/ __/ __|    .***++++++=.   
| |___| |_| | |   | | |  __/\__ \__ \    .**+++++++=.   
 \_____\__, |_|   |_|  \___||___/___/    .**+++++++=.   
        __/ |                            .**++++++++=   
       |___/                              **+++++++=    
                                          .*+++++++.    
By: Quirijn du Bois & Pieter te Brake      .*+++++.     
                                             .#+        
                                             .#+        
                                             .#+        
                                                        
```

</div>

🌲🌲🌲🌲 Custom 🤓 scientific 🧬 text 📚 language compiler 💻 written in C revolutionizing "LaTeX" 🤮. 🌲🌲🌲🌲

Also see:
- [CyPDF](https://github.com/pieterteb/CyPDF)
- [CyDE](https://github.com/quirijndubois/CyDE)

## How to build

cd into the CyPress folder
Add and cd into a build directory 
```bash 
mkdir build && cd build
```
Run cmake using CMakeLists.txt
```bash 
cmake ..
```
Build using make
```bash
make
```
Execute
```bash
./CyPress YOUR_FILE
```

## Goals (long term)

- Scientific document typesetting (Similar to LaTeX)
- Simple syntax with .cyp files (Simpler than LaTeX)
- PDF generation
- High efficiency
- HTML generation
- HTML, PDF equivalency
- IPython implemention
- Streamlining numerical and symbolic calculations (With python)


## TODO (short term)
- [ ] PDF generation
- [x] Syntax tokenizer
- [ ] Syntax tree generator
- [ ] Syntax tree to layout converter
- [ ] Layout to PDF generator
- [ ] HTML generation
- [ ] Layout to HTML generator
- [ ] Documentation
