# SafeVax V2

O SafeVax é um sistema inovador voltado para o monitoramento e a segurança no armazenamento de vacinas em ambientes hospitalares. Desenvolvido para reduzir riscos e aumentar a eficiência no gerenciamento e administração de vacinas, o projeto utiliza sensores IOT como DHT11 e RFID para garantir que as condições ideais de conservação sejam sempre mantidas.

---

## Problema Abordado

O armazenamento adequado de vacinas é essencial para preservar sua eficácia e garantir a segurança dos pacientes. Em ambientes hospitalares, a violação das condições ideais — como a abertura frequente das portas dos refrigeradores e variações de temperatura — pode comprometer a qualidade dos insumos e, consequentemente, a saúde pública. Processos manuais de monitoramento estão sujeitos a falhas humanas, demandando uma solução automatizada e confiável.

---

## Solução Proposta

O SafeVax automatiza o monitoramento dos refrigeradores de vacinas por meio de:

- **Controle de Acesso:** Monitoramento da abertura e fechamento das portas do refrigerador.
- **Monitoramento de Temperatura:** Acompanhamento em tempo real da temperatura interna, garantindo que os níveis ideais sejam mantidos.
- **Identificação via RFID:** Registro de quem acessa o refrigerador, utilizando tecnologia de leitura de cartões RFID, para maior rastreabilidade.

Esta abordagem integrada assegura uma gestão eficiente e segura, minimizando o risco de comprometer a qualidade das vacinas.

---

## Ferramentas Utilizadas

- **ESP32:** Microcontrolador robusto e versátil, ideal para integrar e controlar os sensores do sistema.
- **Sensor DHT11:** Monitoramento em tempo real da temperatura interna dos refrigeradores.
- **Sensor de Abertura/Fechamento de Portas:** Garante o registro preciso dos acessos aos refrigeradores.
- **Leitura de RFID:** Implementado para identificar e registrar os usuários que acessam os equipamentos.
- **Relé eletrônico para controle de acesso**: Implementado como uma forma de abrir e fechar as portas dos refrigeradores e manter o acesso controlado.
- **Integração com Sistemas Hospitalares:** Sincronização de dados com plataformas de gestão de saúde, facilitando o monitoramento centralizado.
- **Relatórios Automáticos:** Geração e análise de dados históricos para otimizar práticas de armazenamento e logística.
- **Alertas via WhatsApp:** Notificações automáticas para os gestores em casos de irregularidades, garantindo uma resposta rápida.

<!-- --- -->
<!-- ## Funcionalidades Futuras -->

<!-- Para ampliar o escopo e a eficácia do SafeVax, estão previstas as seguintes implementações: -->
---

## Desenvolvedores

O projeto SafeVax V2 é fruto da colaboração de uma equipe multidisciplinar comprometida com a inovação e a segurança na área da saúde:

- **Guilherme Lucas Pereira Bernardo** – *Líder de Projeto & Desenvolvedor*  
  Responsável pela coordenação geral do projeto, desenvolvimento do modelo de dados e integração das plataformas.

- **Vinícius Brito** – *Especialista em Hardware* ~ @ViniKhael  
  Focado na seleção, configuração e integração dos dispositivos eletrônicos utilizados.

- **Ruan Oliveira** – *Desenvolvedor de Software e especialista em saúde* ~ @rouan
  Responsável pela implementação dos módulos de monitoramento e notificação, além da futura integração via RFID.

- **Gabriel Guilherme** – *Engenheiro de Dados* ~ @Bounded-Bytes  
  Encarregado da análise e armazenamento dos dados, garantindo que os relatórios sejam precisos e informativos.

Se você deseja contribuir para o projeto ou entrar em contato com a equipe, por favor, consulte as informações de contato no repositório.

---

SafeVax é um passo importante rumo a um sistema de armazenamento de vacinas mais seguro, eficiente e confiável, promovendo a saúde pública e a excelência na gestão hospitalar.