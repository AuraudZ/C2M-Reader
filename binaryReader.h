#pragma once
#include <cstdint>
#include <fstream>
#include <iostream>
#include "Vector.h"
#include <vector>
class binaryReader
{
	const char* m_pBuffer;
	std::ifstream m_File;
	int m_nSize;
	int m_nPos;
	public:
		binaryReader(std::string fileName);
		int readInt();
		uint8_t readUInt();
		bool readBool();
		float readFloat();
		char* readString();
		char * readByte(); 
		std::vector<uint8_t> readBytes(size_t numBytes);
		int getPos();
		int getSize();
		Vector3 readVector3();
		Vector4 readVector4();
		void setPos(int nPos);

		
};

