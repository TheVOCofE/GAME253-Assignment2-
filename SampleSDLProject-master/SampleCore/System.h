#pragma once
#ifndef SYSTEM_H
#define SYSTEM_H


namespace core {
	enum class SystemType : unsigned __int8
	{
		WINDOW,
		INPUT,
		TOTAL_SYSTEMS
	};

	class System
	{
	protected:
		const SystemType type;
		System(SystemType system);
	public:
		virtual System* make_system(SystemType type) = 0; //to call System::make_system(system);
		virtual ~System();
		virtual bool Init() = 0;
		virtual void Update() = 0;
		virtual void Draw() const = 0;
		virtual bool Shutdown() = 0;
	private:
	};

}


#endif // !SYSTEM_H