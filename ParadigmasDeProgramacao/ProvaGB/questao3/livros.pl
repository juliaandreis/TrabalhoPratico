/*Fatos - Gêneros*/
genero(ficcao).
genero(drama).
genero(suspense).
genero(fantasia).
genero(historia).

/*Fatos - Livros*/
livro('1984', orwell, ficcao).
livro('Admirável Mundo Novo', huxley, ficcao).
livro('O Senhor dos Anéis', tolkien, fantasia).
livro('O Hobbit', tolkien, fantasia).
livro('Dom Casmurro', machado, drama).
livro('Memórias Póstumas de Brás Cubas', machado, drama).
livro('A Revolução dos Bichos', orwell, ficcao).
livro('Harry Potter', rowling, fantasia).
livro('O Código Da Vinci', brown, suspense).
livro('Inferno', brown, suspense).
livro('O Pequeno Príncipe', saint_exupery, ficcao).
livro('A Menina que Roubava Livros', zusak, drama).
livro('Ensaio sobre a Cegueira', saramago, drama).
livro('Capitães da Areia', jorge_amado, drama).
livro('It', stephen_king, suspense).
livro('Carrie', stephen_king, suspense).
livro('As Crônicas de Nárnia', lewis, fantasia).
livro('Sapiens', harari, historia).
livro('21 Lições para o Século 21', harari, historia).
livro('Homem Invisível', wells, ficcao).
livro('O Nome do Vento', rothfuss, fantasia).
livro('O Temor do Sábio', rothfuss, fantasia).
livro('A Batalha do Apocalipse', eduardo_sporh, fantasia).
livro('Filhos do Éden', eduardo_sporh, fantasia).
livro('O Alquimista', paulo_coelho, ficcao).
livro('Brida', paulo_coelho, ficcao).
livro('O Diário de Anne Frank', anne_frank, historia).
livro('1982', orwell, ficcao).
livro('Fundação', asimov, ficcao).
livro('Eu, Robô', asimov, ficcao).
livro('O Caçador de Pipas', hosseini, drama).
livro('Mil Sóis Esplêndidos', hosseini, drama).
livro('O Iluminado', stephen_king, suspense).
livro('A Esperança', collins, ficcao).
livro('Em Chamas', collins, ficcao).
livro('Jogos Vorazes', collins, ficcao).
livro('Neuromancer', gibson, ficcao).
livro('A Máquina do Tempo', wells, ficcao).
livro('Viagem ao Centro da Terra', verne, ficcao).
livro('Vinte Mil Léguas Submarinas', verne, ficcao).

/*Fatos - Autores*/
autor(orwell).
autor(huxley).
autor(tolkien).
autor(machado).
autor(rowling).
autor(brown).
autor(saint_exupery).
autor(stephen_king).
autor(harari).
autor(zusak).
autor(rothfuss).
autor(eduardo_sporh).
autor(paulo_coelho).
autor(anne_frank).
autor(collins).
autor(asimov).
autor(hosseini).
autor(verne).
autor(gibson).

/*Fatos - Avaliação*/
avaliacao(maria, 'O Senhor dos Anéis', excelente).
avaliacao(joao, '1984', bom).
avaliacao(carla, 'Sapiens', ótimo).
avaliacao(ana, 'Dom Casmurro', excelente).
avaliacao(paulo, 'Harry Potter', bom).
avaliacao(lucas, 'A Menina que Roubava Livros', ótimo).
avaliacao(beatriz, 'O Caçador de Pipas', excelente).
avaliacao(ricardo, 'Filhos do Éden', ótimo).
avaliacao(juliana, 'Inferno', bom).
avaliacao(marcos, 'Neuromancer', regular).
avaliacao(aline, 'Jogos Vorazes', bom).
avaliacao(daniel, 'O Nome do Vento', ótimo).
avaliacao(tatiane, 'O Diário de Anne Frank', excelente).
avaliacao(felipe, 'Eu, Robô', bom).
avaliacao(rafael, 'Carrie', regular).

/* a) Recomendar livros baseado no gênero que o usuário gosta */

recomendar_livro(Usuario, LivroRecomendado) :-
    avaliacao(Usuario, LivroAvaliado, Avaliacao),
    (Avaliacao = bom; Avaliacao = ótimo; Avaliacao = excelente),
    livro(LivroAvaliado, _, Genero),
    livro(LivroRecomendado, _, Genero),
    LivroRecomendado \= LivroAvaliado.

/* b) Encontrar todos os livros de um determinado autor */

livros_do_autor(Autor, Livro) :-
    livro(Livro, Autor, _).

/* c) Apresentar usuários que gostam do mesmo gênero de um determinado livro */

usuario_gosta_genero_livro(Usuario, Livro) :-
    livro(Livro, _, Genero),
    avaliacao(Usuario, LivroAvaliado, Avaliacao),
    (Avaliacao = bom; Avaliacao = ótimo; Avaliacao = excelente),
    livro(LivroAvaliado, _, Genero).

/* d) Verificar se um autor possui livros em mais de um gênero */

autor_mais_de_um_genero(Autor) :-
    livro(_, Autor, Genero1),
    livro(_, Autor, Genero2),
    Genero1 \= Genero2.