#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace WordPad {

	/// <summary>
	/// ToForm ժҪ
	///
	/// ����: ������Ĵ�������ƣ�����Ҫ����
	///          ����������������� .resx �ļ��������й���Դ���������ߵ�
	///          ����Դ�ļ��������ԡ�����
	///          �������������˴���Ĺ���
	///          ���ػ���Դ��ȷ������
	/// </summary>
	public ref class ToForm : public System::Windows::Forms::Form
	{
	public:
		ToForm(void)
		{
			InitializeComponent();
			//
			//TODO: �ڴ˴���ӹ��캯������
			//
			
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~ToForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  rdlbtnEnd;
	protected: 

	private: System::Windows::Forms::RadioButton^  rdlbtnStart;
	private: System::Windows::Forms::Button^  btnOK;
	private: System::Windows::Forms::Button^  button2;

	private:
		/// <summary>
		/// ����������������
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->rdlbtnEnd = (gcnew System::Windows::Forms::RadioButton());
			this->rdlbtnStart = (gcnew System::Windows::Forms::RadioButton());
			this->btnOK = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->rdlbtnEnd);
			this->groupBox1->Controls->Add(this->rdlbtnStart);
			this->groupBox1->Location = System::Drawing::Point(26, 8);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(233, 62);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"ת��";
			// 
			// rdlbtnEnd
			// 
			this->rdlbtnEnd->AutoSize = true;
			this->rdlbtnEnd->Location = System::Drawing::Point(157, 30);
			this->rdlbtnEnd->Name = L"rdlbtnEnd";
			this->rdlbtnEnd->Size = System::Drawing::Size(47, 16);
			this->rdlbtnEnd->TabIndex = 1;
			this->rdlbtnEnd->TabStop = true;
			this->rdlbtnEnd->Text = L"ĩβ";
			this->rdlbtnEnd->UseVisualStyleBackColor = true;
			// 
			// rdlbtnStart
			// 
			this->rdlbtnStart->AutoSize = true;
			this->rdlbtnStart->Checked = true;
			this->rdlbtnStart->Location = System::Drawing::Point(35, 30);
			this->rdlbtnStart->Name = L"rdlbtnStart";
			this->rdlbtnStart->Size = System::Drawing::Size(47, 16);
			this->rdlbtnStart->TabIndex = 0;
			this->rdlbtnStart->TabStop = true;
			this->rdlbtnStart->Text = L"��ͷ";
			this->rdlbtnStart->UseVisualStyleBackColor = true;
			// 
			// btnOK
			// 
			this->btnOK->Location = System::Drawing::Point(48, 85);
			this->btnOK->Name = L"btnOK";
			this->btnOK->Size = System::Drawing::Size(60, 23);
			this->btnOK->TabIndex = 1;
			this->btnOK->Text = L"ȷ��";
			this->btnOK->UseVisualStyleBackColor = true;
			this->btnOK->Click += gcnew System::EventHandler(this, &ToForm::btnOK_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(183, 85);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(59, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"ȡ��";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ToForm::button2_Click);
			// 
			// ToForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(298, 120);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->btnOK);
			this->Controls->Add(this->groupBox1);
			this->HelpButton = true;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ToForm";
			this->ShowIcon = false;
			this->Text = L"ת��";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	public:String^ selectItem;
	private: System::Void btnOK_Click(System::Object^  sender, System::EventArgs^  e) {

			 }
   public: String^ point()
	{
		if(this->rdlbtnStart ->Checked ==true)
		{
			selectItem = "��ͷ";
		}
		else
		{
		   selectItem = "ĩβ";
		}
	    	return selectItem;
			}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close ();
		 }
};
}
