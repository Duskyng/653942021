import 'package:flutter/material.dart';

void main() {
  runApp(const MeuApp());
}

class MeuApp extends StatefulWidget {
  const MeuApp({super.key});

  @override
  State<MeuApp> createState() => _MeuAppState();
}

class _MeuAppState extends State<MeuApp> {
  final List<Tarefa> _tarefas = [];
  final TextEditingController controlador = TextEditingController();

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Lista de Afazeres'),
        ),
        body: Column(
          children: [
            Expanded(
              child: ListView.builder(
                itemCount: _tarefas.length,
                itemBuilder: (context, index) {
                  return CheckboxListTile(
                    title: Text(_tarefas[index].descricao),
                    value: _tarefas[index].status,
                    onChanged: (novoValor) {
                      setState(() {
                        _tarefas[index].status = novoValor ?? false;
                      });
                    },
                  );
                },
              ),
            ),
            Row(
              children: [
                Expanded(
                  child: TextField(
                    controller: controlador,
                    decoration: const InputDecoration(
                      hintText: 'Descrição',
                    ),
                  ),
                ),
                ElevatedButton(
                  child: const Text('Adicionar Tarefa'),
                  onPressed: () {
                    setState(() {
                      _tarefas.add(
                        Tarefa(
                          descricao: controlador.text,
                          status: false,
                        ),
                      );
                    });
                  },
                ),
              ],
            ),
          ],
        ),
      ),
    );
  }
}

class Tarefa {
  final String descricao;
  bool status;

  Tarefa({required this.descricao, required this.status});
}
