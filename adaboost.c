# include "adaboost.h"
# include "haar.h"

double compute_tresh_min(struct image img) // liste d'image
{
	img.pos++; // FAUX A REMPLIR FIX ME
	return 0;
}
double compute_tresh_max(struct image img)
{
	img.pos++; // FAUX A REMPLIR FIX ME
	return 0;
}

void DSES(int nb_img, struct image image, double treshold, double teta, double	epsilon, double marge)
{
	// INITIALISATION
	treshold = compute_tresh_min(image) - 1;
	marge = 0;
	epsilon = 2;

	//sum pos weights + sum neg weights
	int wpos_tp = 0;
	int wpos_tm = 0;
	int wneg_tp = 0;
	int wneg_tm = 0;
	for(int i = 0; i < nb_img/2; i++)
	{
		if(image.haar->val > treshold)
		{	
			image.weight = 1;
			wpos_tp++;
		}
		else
		{
			image.weight = 0;
		}
	}

	for(int i = 0; i < nb_img/2; i++)
	{
		if(image.haar->val > treshold)
		{
			image.weight = -1;
			wneg_tp++;
		}
		else
			image.weight = 0;

	}

	// set iteartor
	int j = 0;
	int Epsilon;
	int Treshold = treshold;
	int Marge = marge;
	int error_p = 0;
	int error_n = 0;
	int Teta;

	while(1)
	{
		error_p = wpos_tm + wneg_tp;
		error_n = wpos_tp + wneg_tm;

		if(error_p < error_n)
		{
			Epsilon = error_p;
			Teta = 1;
		}
		else
		{
			Epsilon = error_n;
			Teta = -1;
		}

		if((Epsilon < epsilon) || (Epsilon = epsilon && Marge == marge))
		{
			epsilon = Epsilon;
			treshold = Treshold;
			marge = Marge;
			teta = Teta;
		}

		if(j == nb_img)
			break;

		j++;

		while(1)
		{
			if(image.pos == -1) // Yij = -1 sur PDF
			{
				wneg_tm += image.weight;
				wneg_tp -= image.weight;
			}
			else
			{
				wpos_tm += image.weight;
				wpos_tp -= image.weight;
			}

			if((j == nb_img) || ( image.haar->val != image.haar->val)) // changer, image I != Image I + 1
				break;
			else
				j++;
		}

		if(j == nb_img)
		{
			Treshold = compute_tresh_max(image); // add i or j ?
			Marge = 0;
		}
		else
		{
			Treshold = image.haar->val + image.haar->val; // t = i + i+1 Cf PDF
			Marge =  image.haar->val - image.haar->val; // same i+1 - i
		}
	}
}

void BStump(int nb_img,struct image image,int nb_feat)
{
	int error = 2;
	double treshold = 0;
	double teta = 0;
	double margin = 0;	
	double epsilon = 0;
	double marge = 0;

	for(int i = 0; i < nb_feat; i++)
	{
		DSES(nb_img, image, treshold, teta, epsilon,  marge);
	}





}
