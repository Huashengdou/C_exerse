- 需要由make命令创建的目标对象targets，通常是要生成的目标文件或者可执行文件
- 创建目标文件所要依赖的文件dependent_files
- 创建目标文件时需要运行的命令command
- 一般格式：  
	targets...:dependent_files ...  
		command

