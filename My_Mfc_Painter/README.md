# Finish（x86-release）


实现加载dll的功能：
```C++
void CMFC222View::getplugins()
{
	modules.clear();
	WIN32_FIND_DATA fileData;
	HANDLE fileHandle = FindFirstFile(L"plugins/*.dll", &fileData);
	if (fileHandle == (void*)ERROR_INVALID_HANDLE ||
		fileHandle == (void*)ERROR_FILE_NOT_FOUND) {
		MessageBox(TEXT("NONE DLL"));//检测是否有dll读入
		return;
	}
	do {
		++total_shapes;
		HINSTANCE mod = LoadLibrary((L"./plugins/" + wstring(fileData.cFileName)).c_str());
		modules.push_back(mod);
	} while (FindNextFile(fileHandle, &fileData));
	FindClose(fileHandle);
	return;
}

CLayer* CMFC222View::getobject(size_t n)
{
	size_t i = n - 1;
	HINSTANCE mod = modules[i];
	typedef CLayer* (__cdecl* create_obj_point)(void);
	create_obj_point objFunc = (create_obj_point)GetProcAddress(mod, "create");
	return objFunc();
}
```