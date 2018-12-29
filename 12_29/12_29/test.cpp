public static Integer[] bigNumberMultiply(int[] arr1, int[] arr2) {
	ArrayList<Integer> result = new ArrayList<>();  //�м���͵Ľ��

													//arr2 ��λ��arr1���
	for (int i = arr2.length - 1; i >= 0; i--) {
		int carry = 0;
		ArrayList<Integer> singleList = new ArrayList<>();

		//arr2 ��λ���γ˷��Ľ��
		for (int j = arr1.length - 1; j >= 0; j--) {
			int r = arr2[i] * arr1[j] + carry;
			int digit = r % 10;
			carry = r / 10;

			singleList.add(digit);
		}
		if (carry != 0) {
			singleList.add(carry);
		}

		int resultCarry = 0, count = 0;
		int k = 0;
		int l = 0;
		int offset = arr2.length - 1 - i;       //�ӷ���ƫ��λ
		ArrayList<Integer> middleResult = new ArrayList<>();

		//arr2ÿλ�˷��Ľ������һ�ֵ���ͽ����ӣ������������ӷ�����λ
		while (k < singleList.size() || l < result.size()) {
			int kv = 0, lv = 0;
			if (k < singleList.size() && count >= offset) {
				kv = singleList.get(k++);
			}
			if (l < result.size()) {
				lv = result.get(l++);
			}
			int sum = resultCarry + kv + lv;
			middleResult.add(sum % 10);     //��ӽ���������󣨸�λ����λ����ʱ�洢�������Ҫ�������
			resultCarry = sum / 10;
			count++;
		}
		if (resultCarry != 0) {
			middleResult.add(resultCarry);
		}
		result.clear();
		result = middleResult;
	}

	Collections.reverse(result);    //����������
	return result.toArray(new Integer[result.size()]);
}