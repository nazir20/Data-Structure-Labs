## Binary Tree in C

- Inorder Traversal
- Preorder Traversal
- Postorder Traversal
<hr>

### Soru2: 

```bash
  <b>İkili ağaçta level-order dolaşmanın zaman karmaşıklığı (time complexity) nedir açıklayınız?</b>
  
  
  Cevap: İkili ağaçta level-order dolaşmanın zaman karmaşıklığı O(n) dir ve bu, her düğümün sadece bir kez ziyaret edildiği için ağaçtaki düğümlerin 
  sayısıyla doğru orantılıdır. İkili ağaçta level-order dolaşmanın zaman karmaşıklığı, ağacın düğüm sayısına (n) bağlıdır. 
  Her bir düğüm ziyareti bir sabit zaman alır, bu nedenle toplam zaman karmaşıklığı O(n) dir.
```

### Soru3: 

```bash
  <b>Özyinelemeli biçimde sıralı (in-order) geçişin uzay karmaşıklığı (space complexity) nedir açıklayınız? (d ağaç derinliğidir ve n düğüm sayısıdır)</b>
  
  
  Cevap: Özyinelemeli biçimde sıralı geçiş, bir ikili ağacın tüm düğümlerini sıralı bir şekilde ziyaret etmek için kullanılan bir algoritmadır. 
  Bu algoritmanın uzay karmaşıklığı, ağacın derinliğine (d) ve düğüm sayısına (n) bağlıdır ve genellikle O(log n) olur. 
```

### Soru4: 

```bash
  <b>7, 5, 1, 8, 3, 6, 0, 9, 4, 2 sayılarının başlangıçta boş bir ikili arama ağacına bu sırayla eklendiğini varsayalım. 
  İkili arama ağacı, doğal sayılar üzerinde olağan sıralamayı kullanır. Ortaya çıkan ağacın sırasız (in-order) geçiş dizisi nedir? Ağacı çizerek gösteriniz.</b>
  
  
  Cevap: Bu ağacın sırasız (in-order) geçişi aşağıdaki gibidir:
  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
```

#### İkili Arama Ağacı:


![İkili Arama Ağacı:](https://github.com/nazir20/Data-Structure-Labs/blob/main/Lab_8/binary%20tree.png)
