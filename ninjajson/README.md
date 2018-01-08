#NinjaJSON

A JSON parsing/writing library. Part of the NinjaFramework.

###Dependancies

-NinjaLog (optional)

###Usage

```c++
using namespace NinjaFramework::JSON;

std::shared_ptr<Document> doc = Document::Parse(json_doc);
// Parse the json document, json_doc can be either a wstring or a wistream


```

###FAQ
Q: Why do I need to use wstring or wistream instead of string or istream?
A: Because JSON is by its definition is written in utf8 and supports wide characters

Q: How do I convert my existing string to wstring?
A: Simply define a wstring with the same length as the string and copy the contents
```c++
std::wstring StringToWString(const std::string& s)
{
    std::wstring temp(s.length(),L' ');
    std::copy(s.begin(), s.end(), temp.begin());
    return temp; 
}
```
