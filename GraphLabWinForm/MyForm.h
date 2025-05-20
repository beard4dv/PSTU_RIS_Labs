#pragma once
#include "graph.h"

namespace GraphLabWinForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			graph = new Graph();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ makeGraph;
	private: System::Windows::Forms::Button^ graphPrint;


	protected:



	private:
		Graph* graph;
	private: System::Windows::Forms::Button^ DFS;
	private: System::Windows::Forms::Button^ BFS;
	private: System::Windows::Forms::Button^ Dijkstra;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ clearRTB1;
	private: System::Windows::Forms::Button^ insVertex;
	private: System::Windows::Forms::Button^ delVertex;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ insEdge;
	private: System::Windows::Forms::Button^ delEdge;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::GroupBox^ editBox1;
	private: System::Windows::Forms::Button^ removeGraph;
	private: System::Windows::Forms::Button^ visGraph;







		   /// <summary>
		/// Required designer variable.
		/// </summary>
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			   this->makeGraph = (gcnew System::Windows::Forms::Button());
			   this->graphPrint = (gcnew System::Windows::Forms::Button());
			   this->DFS = (gcnew System::Windows::Forms::Button());
			   this->BFS = (gcnew System::Windows::Forms::Button());
			   this->Dijkstra = (gcnew System::Windows::Forms::Button());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->clearRTB1 = (gcnew System::Windows::Forms::Button());
			   this->insVertex = (gcnew System::Windows::Forms::Button());
			   this->delVertex = (gcnew System::Windows::Forms::Button());
			   this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->insEdge = (gcnew System::Windows::Forms::Button());
			   this->delEdge = (gcnew System::Windows::Forms::Button());
			   this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			   this->label7 = (gcnew System::Windows::Forms::Label());
			   this->editBox1 = (gcnew System::Windows::Forms::GroupBox());
			   this->removeGraph = (gcnew System::Windows::Forms::Button());
			   this->visGraph = (gcnew System::Windows::Forms::Button());
			   this->editBox1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // richTextBox1
			   // 
			   this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->richTextBox1->Location = System::Drawing::Point(290, 12);
			   this->richTextBox1->Name = L"richTextBox1";
			   this->richTextBox1->Size = System::Drawing::Size(432, 408);
			   this->richTextBox1->TabIndex = 0;
			   this->richTextBox1->Text = L"";
			   this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox1_TextChanged);
			   // 
			   // makeGraph
			   // 
			   this->makeGraph->Location = System::Drawing::Point(12, 12);
			   this->makeGraph->Name = L"makeGraph";
			   this->makeGraph->Size = System::Drawing::Size(130, 25);
			   this->makeGraph->TabIndex = 1;
			   this->makeGraph->Text = L"Make Graph (var. 9)";
			   this->makeGraph->UseVisualStyleBackColor = true;
			   this->makeGraph->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			   // 
			   // graphPrint
			   // 
			   this->graphPrint->Location = System::Drawing::Point(12, 183);
			   this->graphPrint->Name = L"graphPrint";
			   this->graphPrint->Size = System::Drawing::Size(272, 25);
			   this->graphPrint->TabIndex = 2;
			   this->graphPrint->Text = L"Print Graph";
			   this->graphPrint->UseVisualStyleBackColor = true;
			   this->graphPrint->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			   // 
			   // DFS
			   // 
			   this->DFS->Location = System::Drawing::Point(12, 214);
			   this->DFS->Name = L"DFS";
			   this->DFS->Size = System::Drawing::Size(190, 25);
			   this->DFS->TabIndex = 3;
			   this->DFS->Text = L"DFS";
			   this->DFS->UseVisualStyleBackColor = true;
			   this->DFS->Click += gcnew System::EventHandler(this, &MyForm::DFS_Click);
			   // 
			   // BFS
			   // 
			   this->BFS->Location = System::Drawing::Point(12, 245);
			   this->BFS->Name = L"BFS";
			   this->BFS->Size = System::Drawing::Size(190, 25);
			   this->BFS->TabIndex = 4;
			   this->BFS->Text = L"BFS";
			   this->BFS->UseVisualStyleBackColor = true;
			   this->BFS->Click += gcnew System::EventHandler(this, &MyForm::BFS_Click);
			   // 
			   // Dijkstra
			   // 
			   this->Dijkstra->Location = System::Drawing::Point(12, 276);
			   this->Dijkstra->Name = L"Dijkstra";
			   this->Dijkstra->Size = System::Drawing::Size(190, 25);
			   this->Dijkstra->TabIndex = 5;
			   this->Dijkstra->Text = L"Dijkstra";
			   this->Dijkstra->UseVisualStyleBackColor = true;
			   this->Dijkstra->Click += gcnew System::EventHandler(this, &MyForm::Dijkstra_Click);
			   // 
			   // textBox1
			   // 
			   this->textBox1->Location = System::Drawing::Point(208, 217);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(20, 20);
			   this->textBox1->TabIndex = 6;
			   this->textBox1->Text = L"3";
			   this->textBox1->KeyPress += gcnew KeyPressEventHandler(this, &MyForm::textBox1_KeyPress);
			   // 
			   // textBox2
			   // 
			   this->textBox2->Location = System::Drawing::Point(208, 248);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(20, 20);
			   this->textBox2->TabIndex = 7;
			   this->textBox2->Text = L"3";
			   this->textBox2->KeyPress += gcnew KeyPressEventHandler(this, &MyForm::textBox2_KeyPress);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(234, 220);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(50, 13);
			   this->label1->TabIndex = 8;
			   this->label1->Text = L"¹ vertex";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(234, 251);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(50, 13);
			   this->label2->TabIndex = 9;
			   this->label2->Text = L"¹ vertex";
			   // 
			   // textBox3
			   // 
			   this->textBox3->Location = System::Drawing::Point(208, 279);
			   this->textBox3->Name = L"textBox3";
			   this->textBox3->Size = System::Drawing::Size(20, 20);
			   this->textBox3->TabIndex = 10;
			   this->textBox3->Text = L"3";
			   this->textBox3->KeyPress += gcnew KeyPressEventHandler(this, &MyForm::textBox3_KeyPress);
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(234, 282);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(50, 13);
			   this->label3->TabIndex = 11;
			   this->label3->Text = L"¹ vertex";
			   // 
			   // clearRTB1
			   // 
			   this->clearRTB1->Location = System::Drawing::Point(290, 426);
			   this->clearRTB1->Name = L"clearRTB1";
			   this->clearRTB1->Size = System::Drawing::Size(432, 23);
			   this->clearRTB1->TabIndex = 12;
			   this->clearRTB1->Text = L"Clear";
			   this->clearRTB1->UseVisualStyleBackColor = true;
			   this->clearRTB1->Click += gcnew System::EventHandler(this, &MyForm::clearRTB1_Click);
			   // 
			   // insVertex
			   // 
			   this->insVertex->Location = System::Drawing::Point(6, 19);
			   this->insVertex->Name = L"insVertex";
			   this->insVertex->Size = System::Drawing::Size(80, 25);
			   this->insVertex->TabIndex = 13;
			   this->insVertex->Text = L"Add Vertex";
			   this->insVertex->UseVisualStyleBackColor = true;
			   this->insVertex->Click += gcnew System::EventHandler(this, &MyForm::insVertex_Click);
			   // 
			   // delVertex
			   // 
			   this->delVertex->Location = System::Drawing::Point(92, 19);
			   this->delVertex->Name = L"delVertex";
			   this->delVertex->Size = System::Drawing::Size(80, 25);
			   this->delVertex->TabIndex = 14;
			   this->delVertex->Text = L"Delete Vertex";
			   this->delVertex->UseVisualStyleBackColor = true;
			   this->delVertex->Click += gcnew System::EventHandler(this, &MyForm::delVertex_Click);
			   // 
			   // textBox4
			   // 
			   this->textBox4->Location = System::Drawing::Point(178, 22);
			   this->textBox4->Name = L"textBox4";
			   this->textBox4->Size = System::Drawing::Size(20, 20);
			   this->textBox4->TabIndex = 15;
			   this->textBox4->KeyPress += gcnew KeyPressEventHandler(this, &MyForm::textBox4_KeyPress);
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Location = System::Drawing::Point(204, 25);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(50, 13);
			   this->label4->TabIndex = 16;
			   this->label4->Text = L"¹ vertex";
			   // 
			   // insEdge
			   // 
			   this->insEdge->Location = System::Drawing::Point(152, 52);
			   this->insEdge->Name = L"insEdge";
			   this->insEdge->Size = System::Drawing::Size(90, 25);
			   this->insEdge->TabIndex = 17;
			   this->insEdge->Text = L"Add Edge";
			   this->insEdge->UseVisualStyleBackColor = true;
			   this->insEdge->Click += gcnew System::EventHandler(this, &MyForm::insEdge_Click);
			   // 
			   // delEdge
			   // 
			   this->delEdge->Location = System::Drawing::Point(152, 99);
			   this->delEdge->Name = L"delEdge";
			   this->delEdge->Size = System::Drawing::Size(90, 25);
			   this->delEdge->TabIndex = 18;
			   this->delEdge->Text = L"Delete Edge";
			   this->delEdge->UseVisualStyleBackColor = true;
			   this->delEdge->Click += gcnew System::EventHandler(this, &MyForm::delEdge_Click);
			   // 
			   // textBox5
			   // 
			   this->textBox5->Location = System::Drawing::Point(26, 52);
			   this->textBox5->Name = L"textBox5";
			   this->textBox5->Size = System::Drawing::Size(30, 20);
			   this->textBox5->TabIndex = 19;
			   this->textBox5->KeyPress += gcnew KeyPressEventHandler(this, &MyForm::textBox5_KeyPress);
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Location = System::Drawing::Point(62, 55);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(84, 13);
			   this->label5->TabIndex = 20;
			   this->label5->Text = L"¹ vertex FROM";
			   // 
			   // textBox6
			   // 
			   this->textBox6->Location = System::Drawing::Point(26, 78);
			   this->textBox6->Name = L"textBox6";
			   this->textBox6->Size = System::Drawing::Size(30, 20);
			   this->textBox6->TabIndex = 21;
			   this->textBox6->KeyPress += gcnew KeyPressEventHandler(this, &MyForm::textBox6_KeyPress);
			   // 
			   // label6
			   // 
			   this->label6->AutoSize = true;
			   this->label6->Location = System::Drawing::Point(62, 81);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(68, 13);
			   this->label6->TabIndex = 22;
			   this->label6->Text = L"¹ vertex TO";
			   // 
			   // textBox7
			   // 
			   this->textBox7->Location = System::Drawing::Point(26, 104);
			   this->textBox7->Name = L"textBox7";
			   this->textBox7->Size = System::Drawing::Size(30, 20);
			   this->textBox7->TabIndex = 23;
			   this->textBox7->KeyPress += gcnew KeyPressEventHandler(this, &MyForm::textBox7_KeyPress);
			   // 
			   // label7
			   // 
			   this->label7->AutoSize = true;
			   this->label7->Location = System::Drawing::Point(62, 107);
			   this->label7->Name = L"label7";
			   this->label7->Size = System::Drawing::Size(66, 13);
			   this->label7->TabIndex = 24;
			   this->label7->Text = L"Edge weight";
			   // 
			   // editBox1
			   // 
			   this->editBox1->Controls->Add(this->insEdge);
			   this->editBox1->Controls->Add(this->label4);
			   this->editBox1->Controls->Add(this->label7);
			   this->editBox1->Controls->Add(this->textBox4);
			   this->editBox1->Controls->Add(this->delEdge);
			   this->editBox1->Controls->Add(this->delVertex);
			   this->editBox1->Controls->Add(this->textBox7);
			   this->editBox1->Controls->Add(this->insVertex);
			   this->editBox1->Controls->Add(this->textBox5);
			   this->editBox1->Controls->Add(this->label6);
			   this->editBox1->Controls->Add(this->label5);
			   this->editBox1->Controls->Add(this->textBox6);
			   this->editBox1->Location = System::Drawing::Point(12, 43);
			   this->editBox1->Name = L"editBox1";
			   this->editBox1->Size = System::Drawing::Size(271, 134);
			   this->editBox1->TabIndex = 25;
			   this->editBox1->TabStop = false;
			   this->editBox1->Text = L"Edit adjacency matrix";
			   // 
			   // removeGraph
			   // 
			   this->removeGraph->Location = System::Drawing::Point(153, 12);
			   this->removeGraph->Name = L"removeGraph";
			   this->removeGraph->Size = System::Drawing::Size(130, 25);
			   this->removeGraph->TabIndex = 26;
			   this->removeGraph->Text = L"Delete Graph";
			   this->removeGraph->UseVisualStyleBackColor = true;
			   this->removeGraph->Click += gcnew System::EventHandler(this, &MyForm::removeGraph_Click);
			   // 
			   // visGraph
			   // 
			   this->visGraph->Location = System::Drawing::Point(12, 307);
			   this->visGraph->Name = L"visGraph";
			   this->visGraph->Size = System::Drawing::Size(272, 25);
			   this->visGraph->TabIndex = 27;
			   this->visGraph->Text = L"Graph Visualization";
			   this->visGraph->UseVisualStyleBackColor = true;
			   this->visGraph->Click += gcnew System::EventHandler(this, &MyForm::visGraph_Click);
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(734, 461);
			   this->Controls->Add(this->visGraph);
			   this->Controls->Add(this->removeGraph);
			   this->Controls->Add(this->editBox1);
			   this->Controls->Add(this->clearRTB1);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->textBox3);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->textBox2);
			   this->Controls->Add(this->textBox1);
			   this->Controls->Add(this->Dijkstra);
			   this->Controls->Add(this->BFS);
			   this->Controls->Add(this->DFS);
			   this->Controls->Add(this->graphPrint);
			   this->Controls->Add(this->makeGraph);
			   this->Controls->Add(this->richTextBox1);
			   this->Name = L"MyForm";
			   this->Text = L"Graph";
			   this->editBox1->ResumeLayout(false);
			   this->editBox1->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		delete graph;
		graph = new Graph();
		RichTextBox^ box = this->richTextBox1;
		this->graph->insertVertex(1, box);
		this->graph->insertVertex(2, box);
		this->graph->insertVertex(3, box);
		this->graph->insertVertex(4, box);
		this->graph->insertVertex(5, box);
		this->graph->insertVertex(6, box);
		this->graph->insertEdge(1, 2, 3, box);
		this->graph->insertEdge(1, 5, 6, box);
		this->graph->insertEdge(2, 4, 27, box);
		this->graph->insertEdge(3, 4, 15, box);
		this->graph->insertEdge(3, 5, 9, box);
		this->graph->insertEdge(4, 3, 15, box);
		this->graph->insertEdge(4, 6, 12, box);
		this->graph->insertEdge(5, 2, 18, box);
		this->graph->insertEdge(5, 3, 9, box);
		this->graph->insertEdge(6, 3, 19, box);
		richTextBox1->AppendText("[Make Graph] Done!\n");
	}
	private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->graph->Print(this->richTextBox1);
	}
	private: System::Void DFS_Click(System::Object^ sender, System::EventArgs^ e) {
		int vertex = Convert::ToInt32(this->textBox1->Text);
		this->graph->DFS(vertex, this->richTextBox1);
	}
	private: System::Void BFS_Click(System::Object^ sender, System::EventArgs^ e) {
		int vertex = Convert::ToInt32(this->textBox2->Text);
		this->graph->BFS(vertex, this->richTextBox1);
	}
	private: System::Void Dijkstra_Click(System::Object^ sender, System::EventArgs^ e) {
		int vertex = Convert::ToInt32(this->textBox3->Text);
		this->graph->Dijkstra(vertex, this->richTextBox1);
	}
	private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8) {
			e->Handled = true;
		}
	}
	private: System::Void textBox2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8) {
			e->Handled = true;
		}
	}
	private: System::Void textBox3_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8) {
			e->Handled = true;
		}
	}
	private: System::Void clearRTB1_Click(System::Object^ sender, System::EventArgs^ e) {
		richTextBox1->Clear();
	}
	private: System::Void insVertex_Click(System::Object^ sender, System::EventArgs^ e) {
		int vertex = Convert::ToInt32(this->textBox4->Text);
		this->graph->insertVertex(vertex, this->richTextBox1);
		richTextBox1->AppendText("[Add Vertex] Done!\n");

	}
	private: System::Void delVertex_Click(System::Object^ sender, System::EventArgs^ e) {
		int vertex = Convert::ToInt32(this->textBox4->Text);
		this->graph->removeVertex(vertex, this->richTextBox1);
		richTextBox1->AppendText("[Delete Vertex] Done!\n");
	}
	private: System::Void textBox4_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8) {
			e->Handled = true;
		}
	}
	private: System::Void textBox5_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8) {
			e->Handled = true;
		}
	}
	private: System::Void textBox6_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8) {
			e->Handled = true;
		}
	}
	private: System::Void textBox7_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8) {
			e->Handled = true;
		}
	}
	private: System::Void insEdge_Click(System::Object^ sender, System::EventArgs^ e) {
		int vertex1 = Convert::ToInt32(this->textBox5->Text);
		int vertex2 = Convert::ToInt32(this->textBox6->Text);
		int weight = Convert::ToInt32(this->textBox7->Text);
		this->graph->insertEdge(vertex1, vertex2, weight, this->richTextBox1);
		richTextBox1->AppendText("[Add Edge] Done!\n");
	}
	private: System::Void delEdge_Click(System::Object^ sender, System::EventArgs^ e) {
		int vertex1 = Convert::ToInt32(this->textBox5->Text);
		int vertex2 = Convert::ToInt32(this->textBox6->Text);
		this->graph->removeEdge(vertex1, vertex2, this->richTextBox1);
	}
	private: System::Void removeGraph_Click(System::Object^ sender, System::EventArgs^ e) {
		delete graph;
		graph = new Graph();
		richTextBox1->AppendText("[Delete Graph] Done!\n");
	}
	private: System::Void visGraph_Click(System::Object^ sender, System::EventArgs^ e) {
		sf::RenderWindow window(sf::VideoMode(800, 600), "Graph Visualization");
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			window.clear(sf::Color::White);
			this->graph->DrawGraph(window);
			window.display();
		}
	}
	};
}