#pragma once
#include <iostream>
using namespace std;

namespace Normal
{
	class CSpeaker
	{
		bool m_isOn;
		int m_nVolue;
	public:
		CSpeaker() { cout << "CSpeaker[" << this << "]"; };
		~CSpeaker() { cout << "~CSpeaker[" << this << "]"; };

		void On()
		{
			if (m_isOn) m_isOn = false;
			else  m_isOn = true;
		}
		void SetValue(int volue)
		{
			m_nVolue = volue;
		}
		int GetValue()
		{
			return m_nVolue;
		}
	};

	class CAntena
	{
		float m_fFrequency;
	public:
		CAntena() { cout << "CAntena[" << this << "]"; };
		~CAntena() { cout << "~CAntena[" << this << "]"; };

		void SetFrequency(float frequency)
		{
			 m_fFrequency = frequency;
		}

		float GetFrequency()
		{
			return m_fFrequency;
		}
	};
}

using namespace Normal;
//상속을 받은 경우 부모의 멤버가 변경되면 자식도 영향을 받는다.
//부모가 변경되어도 자식이 변경되는것을 원하지않을때는 문제가 된다.
namespace Inheritance
{
	class CRadio : public CSpeaker, CAntena
	{
	public:
		CRadio() { cout << "CRadio[" << this << "]"; };
		~CRadio() { cout << "~CRadio[" << this << "]"; };
	};

	void RadioMain()
	{
		CRadio cRadio;
	}
}
//부모의 멤버가 변경되었다고해서 자식에게 영향을 주지는 않을 수도 있다.
namespace HasA_InClass
{
	class CRadio
	{
		CSpeaker m_cSpeacker;
		CAntena m_cAntena;
	public:
		CRadio() { cout << "CRadio[" << this << "]"; };
		~CRadio() { cout << "~CRadio[" << this << "]"; };

		void On()
		{
			m_cSpeacker.On();
		}
		void SetValue(int volue)
		{
			m_cSpeacker.SetValue(volue);
		}
		int GetValue()
		{
			return m_cSpeacker.GetValue();
		}
		void SetFrequency(float frequency)
		{
			m_cAntena.SetFrequency(frequency);
		}

		float GetFrequency()
		{
			return m_cAntena.GetFrequency();
		}
	};

	void RadioMain()
	{
		CRadio cRadio;
	}
}

namespace HasA_InRef
{
	class CRadio
	{
		CSpeaker* m_pSpeacker;
		CAntena* m_pAntena;
	public:
		CRadio() { cout << "CRadio[" << this << "]"; };
		~CRadio() { cout << "~CRadio[" << this << "]"; };

		CRadio(CSpeaker* speaker, CAntena* antena)
		{
			m_pSpeacker = speaker;
			m_pAntena = antena;
			cout << "CRadio[" << this << "]";
		}
		void SetSpeaker(CSpeaker* speaker)
		{
			m_pSpeacker = speaker;
		}
		void SetAntena(CAntena* antena)
		{
			m_pAntena = antena;
		}
		void On()
		{
			m_pSpeacker->On();
		}
		void SetValue(int volue)
		{
			m_pSpeacker->SetValue(volue);
		}
		int GetValue()
		{
			return m_pSpeacker->GetValue();
		}
		void SetFrequency(float frequency)
		{
			m_pAntena->SetFrequency(frequency);
		}

		float GetFrequency()
		{
			return m_pAntena->GetFrequency();
		}
	};
	//객체가 내부에 포함되지않으므로 재활용이 가능하다.
	//참조하는 클래스를 확장할때 상속을 하면 본래 기능은 영향을 주지않는다.
	void RadioMain()
	{
		CSpeaker cSpeaker;
		CAntena cAntena;
		CRadio cRadio(&cSpeaker,&cAntena);
	}
}


