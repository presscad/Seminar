Ŀ¼����
=========

1������������
  1��CalculationSimpleCOM����һ��������COM��������ӵ��һ��ICalc�ӿڣ�
  2��CalculationSimpleCOMProxy���Ƿ������˺Ϳͻ��˹��õĴ������dll��
  3��CalculationAutomation����һ���������Զ�����������ӵ��һ��ICalc2�ӿڡ�

2�����ص��ÿͻ��˳���
  1��TestSimpleCOM�����ڵ���CalculationSimpleCOM���������б��ص��ò��ԣ�
  2��TestAutomation�����ڵ���CalculationAutomation���������б��ص��ò��ԡ�

3��Զ�̵��ÿͻ��˳���
  1��TestRemote���ֱ����������������������Զ�̵��ò��ԣ�
  2��TestRemoteAutomation������ͻ���ֻ�з���˵�tlb�ļ�����tlbת��Ϊ������dll����Զ�̵��ã�
  3��TestRemoteAutomationProxy���Զ�����������tlbת��Ϊ������dll��Ŀ��


ʹ�÷���
=========

1�������ͨ��Calculation_Instal/Uninstall.reg�ļ���װ/ж�������CalculationSimpleCOMProxy
   �Ĵ���dll�ļ�ͨ��RegSvr32���װж�ء�(ʹ��*.regʱ������Ҫ�޸�exe��tlb�ļ���·��)

2�����ص���ֱ��ʹ�ÿͻ��˼���ʵ�ֵ��ã�Զ�̵������ڿͻ��˽������ã�һ�ַ����Ǹ����������
   ��ͬ����(��1��ʾ)����һ�ַ����ǿͻ���ֻ��Ҫ�������õ��Ĵ��������ɡ�

3������TestRemote��Ŀ������CalculationSimpleCOMֻ�谲װCalculationSimpleCOMProxy������dll
   ���ɣ�����CalculationAutomation�谲װͬ������һ�������������

4������TestRemoteAutomation�����ڶ�CalculationAutomation��tlb�ļ�������ת�����õ���������
   ��dll��ֻ�������CalculationSimpleCOMһ����װ������dll���ɡ�