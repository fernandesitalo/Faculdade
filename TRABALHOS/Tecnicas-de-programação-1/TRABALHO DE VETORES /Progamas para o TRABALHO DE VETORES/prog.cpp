inicio = 0; // inicio da sub cadeia 
			fim = 0; // fim da sub cadeia
			
			for(i = 0 ; i < n ; i++) // sera verificada a existencia de n subcadeias, uma a uma
			{	
			// i marca o inicio da sub cadeia ordenada
				
				for(k = i; k < n-1 && vetA[k] < vetA[k+1]; k++);// este for e executado enquanto A[K] for menor que A[K+1] , isto e , enquanto formar uma sequencia crescente
				
			// no final desde laco de repeticao , K marca o final da subcadeia ordenada
				
				if(k - i > fim - inicio)
				{
					inicio = i; // guarda o inicio da maio subcadeia
					fim = k; // guarda o final da sub cadeia
				}
				
			}
